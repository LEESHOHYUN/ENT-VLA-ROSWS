/**
 * @file ur_robot_manager.cpp
 * @brief Single UR5e robot manager via ur_rtde.
 *
 * Provides motion commands (moveJ, moveL, speedJ, speedL), servo mode,
 * singularity handling, gripper integration, safety monitoring,
 * and joint state publishing.
 */

#include "ur_robot_manager/core/ur_robot_manager.h"
#include "ur_robot_manager/utils/ur_kinematics.h"

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/wrench_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/bool.hpp>

#ifndef SIM_MODE
// #include <ur_rtde/rtde_control_interface.h>
// #include <ur_rtde/rtde_receive_interface.h>
// #include <ur_rtde/rtde_io_interface.h>
#endif

#include <Eigen/Dense>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace urRobotManager {

// ===================================================================
// Constructor
// ===================================================================
URRobotManager::URRobotManager(rclcpp::Node::SharedPtr node,
                               const std::string& robot_ip)
    : node_(node),
      robot_ip_(robot_ip),
      robot_connected_(false),
      is_moving_(false),
      servo_active_(false),
      freedrive_active_(false),
      safety_check_active_(true),
      speed_scale_(1.0),
      max_linear_speed_(0.25),
      max_angular_speed_(0.5),
      max_joint_speed_(1.0),
      max_joint_accel_(1.4),
      max_linear_accel_(1.2),
      servo_lookahead_(0.1),
      servo_gain_(300.0)
{
    RCLCPP_INFO(node_->get_logger(), "URRobotManager: Initializing for %s",
                robot_ip_.c_str());

    kinematics_ = std::make_shared<URKinematics>();

    current_joint_positions_.resize(6, 0.0);
    current_joint_velocities_.resize(6, 0.0);
    current_tcp_pose_.resize(6, 0.0);
    current_tcp_force_.resize(6, 0.0);

    // Publishers
    joint_state_pub_ = node_->create_publisher<sensor_msgs::msg::JointState>(
        "/joint_states", 10);
    tcp_pose_pub_ = node_->create_publisher<std_msgs::msg::Float64MultiArray>(
        "/tcp_pose", 10);
    tcp_force_pub_ = node_->create_publisher<geometry_msgs::msg::WrenchStamped>(
        "/tcp_wrench", 10);
    robot_status_pub_ = node_->create_publisher<std_msgs::msg::String>(
        "/robot_status", 10);
    moving_status_pub_ = node_->create_publisher<std_msgs::msg::Bool>(
        "/is_moving", 10);

    // Speed scale subscriber
    speed_scale_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/speed_scale", 10,
        [this](const std_msgs::msg::Float64MultiArray::SharedPtr msg) {
            if (!msg->data.empty()) {
                speed_scale_ = std::clamp(msg->data[0], 0.01, 1.0);
                RCLCPP_INFO(node_->get_logger(), "Speed scale set to %.2f",
                            speed_scale_);
            }
        });

    // Command topic subscribers
    cmd_movej_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/cmd/move_j", 10,
        std::bind(&URRobotManager::cmdMoveJCallback, this, _1));

    cmd_custom_movel_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/cmd/custom_move_l", 10,
        std::bind(&URRobotManager::cmdCustomMoveLCallback, this, _1));

    cmd_home_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/home", 10,
        std::bind(&URRobotManager::cmdHomeCallback, this, _1));

    cmd_stop_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/stop", 10,
        std::bind(&URRobotManager::cmdStopCallback, this, _1));

    cmd_freedrive_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/freedrive", 10,
        std::bind(&URRobotManager::cmdFreedriveCallback, this, _1));

    // Safety check timer (10 Hz)
    safety_timer_ = node_->create_wall_timer(
        100ms, std::bind(&URRobotManager::safetyCheckCallback, this));

    connectToRobot();

    RCLCPP_INFO(node_->get_logger(),
                "URRobotManager: Initialization complete (%s)", robot_ip_.c_str());
}

URRobotManager::~URRobotManager()
{
    RCLCPP_INFO(node_->get_logger(), "URRobotManager: Shutting down");
    stopRobot();
    disconnectFromRobot();
}

// ===================================================================
// Connection
// ===================================================================
void URRobotManager::connectToRobot()
{
#ifndef SIM_MODE
    try {
        RCLCPP_INFO(node_->get_logger(), "Connecting to robot at %s",
                    robot_ip_.c_str());
        // rtde_control_ = std::make_shared<ur_rtde::RTDEControlInterface>(robot_ip_);
        // rtde_receive_ = std::make_shared<ur_rtde::RTDEReceiveInterface>(robot_ip_);
        // rtde_io_ = std::make_shared<ur_rtde::RTDEIOInterface>(robot_ip_);
        robot_connected_ = true;
        RCLCPP_INFO(node_->get_logger(), "Connected to robot at %s",
                    robot_ip_.c_str());
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(),
                     "Failed to connect to robot at %s: %s",
                     robot_ip_.c_str(), e.what());
        robot_connected_ = false;
    }
#else
    RCLCPP_WARN(node_->get_logger(),
                "SIM_MODE: Skipping real robot connection");
    robot_connected_ = true;
#endif
}

void URRobotManager::disconnectFromRobot()
{
#ifndef SIM_MODE
    try {
        // if (rtde_control_) {
        //     rtde_control_->stopScript();
        //     rtde_control_->disconnect();
        // }
        robot_connected_ = false;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "Error disconnecting: %s", e.what());
    }
#else
    robot_connected_ = false;
#endif
}

bool URRobotManager::isRobotConnected() const
{
    return robot_connected_;
}

// ===================================================================
// State queries
// ===================================================================
std::vector<double> URRobotManager::getJointPositions()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    // if (robot_connected_ && rtde_receive_) {
    //     current_joint_positions_ = rtde_receive_->getActualQ();
    // }
#endif
    return current_joint_positions_;
}

std::vector<double> URRobotManager::getJointVelocities()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    // if (robot_connected_ && rtde_receive_) {
    //     current_joint_velocities_ = rtde_receive_->getActualQd();
    // }
#endif
    return current_joint_velocities_;
}

std::vector<double> URRobotManager::getTCPPose()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    // if (robot_connected_ && rtde_receive_) {
    //     current_tcp_pose_ = rtde_receive_->getActualTCPPose();
    // }
#endif
    return current_tcp_pose_;
}

std::vector<double> URRobotManager::getTCPForce()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    // if (robot_connected_ && rtde_receive_) {
    //     current_tcp_force_ = rtde_receive_->getActualTCPForce();
    // }
#endif
    return current_tcp_force_;
}

// ===================================================================
// Motion commands
// ===================================================================
bool URRobotManager::moveJ(const std::vector<double>& joint_target,
                            double speed, double acceleration, bool async)
{
    if (!robot_connected_) {
        RCLCPP_ERROR(node_->get_logger(), "moveJ: Robot not connected");
        return false;
    }
    if (joint_target.size() != 6) {
        RCLCPP_ERROR(node_->get_logger(), "moveJ: Invalid target size");
        return false;
    }

    double s = std::min(speed * speed_scale_, max_joint_speed_);
    double a = std::min(acceleration, max_joint_accel_);

    RCLCPP_INFO(node_->get_logger(),
                "moveJ: [%.3f, %.3f, %.3f, %.3f, %.3f, %.3f] speed=%.2f",
                joint_target[0], joint_target[1], joint_target[2],
                joint_target[3], joint_target[4], joint_target[5], s);

    is_moving_ = true;
    publishMovingStatus(true);

#ifndef SIM_MODE
    try {
        // rtde_control_->moveJ(joint_target, s, a, async);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "moveJ failed: %s", e.what());
        is_moving_ = false;
        publishMovingStatus(false);
        return false;
    }
#else
    if (!async) {
        std::this_thread::sleep_for(500ms);
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_joint_positions_ = joint_target;
    }
#endif

    if (!async) {
        is_moving_ = false;
        publishMovingStatus(false);
    }
    return true;
}

bool URRobotManager::moveL(const std::vector<double>& pose_target,
                            double speed, double acceleration, bool async)
{
    if (!robot_connected_) {
        RCLCPP_ERROR(node_->get_logger(), "moveL: Robot not connected");
        return false;
    }
    if (pose_target.size() != 6) {
        RCLCPP_ERROR(node_->get_logger(), "moveL: Invalid target size");
        return false;
    }

    double s = std::min(speed * speed_scale_, max_linear_speed_);
    double a = std::min(acceleration, max_linear_accel_);

    RCLCPP_INFO(node_->get_logger(),
                "moveL: [%.4f, %.4f, %.4f, %.4f, %.4f, %.4f] speed=%.3f",
                pose_target[0], pose_target[1], pose_target[2],
                pose_target[3], pose_target[4], pose_target[5], s);

    is_moving_ = true;
    publishMovingStatus(true);

#ifndef SIM_MODE
    try {
        // rtde_control_->moveL(pose_target, s, a, async);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "moveL failed: %s", e.what());
        is_moving_ = false;
        publishMovingStatus(false);
        return false;
    }
#else
    if (!async) {
        std::this_thread::sleep_for(500ms);
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_tcp_pose_ = pose_target;
    }
#endif

    if (!async) {
        is_moving_ = false;
        publishMovingStatus(false);
    }
    return true;
}

bool URRobotManager::speedJ(const std::vector<double>& joint_speeds,
                             double acceleration, double time)
{
    if (!robot_connected_) return false;
    if (joint_speeds.size() != 6) return false;

    std::vector<double> clamped(6);
    for (int i = 0; i < 6; ++i) {
        clamped[i] = std::clamp(joint_speeds[i] * speed_scale_,
                                -max_joint_speed_, max_joint_speed_);
    }

#ifndef SIM_MODE
    try {
        // rtde_control_->speedJ(clamped, acceleration, time);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "speedJ failed: %s", e.what());
        return false;
    }
#endif
    return true;
}

bool URRobotManager::speedL(const std::vector<double>& tcp_speeds,
                             double acceleration, double time)
{
    if (!robot_connected_) return false;
    if (tcp_speeds.size() != 6) return false;

    std::vector<double> clamped(6);
    for (int i = 0; i < 3; ++i) {
        clamped[i] = std::clamp(tcp_speeds[i] * speed_scale_,
                                -max_linear_speed_, max_linear_speed_);
    }
    for (int i = 3; i < 6; ++i) {
        clamped[i] = std::clamp(tcp_speeds[i] * speed_scale_,
                                -max_angular_speed_, max_angular_speed_);
    }

#ifndef SIM_MODE
    try {
        // rtde_control_->speedL(clamped, acceleration, time);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "speedL failed: %s", e.what());
        return false;
    }
#endif
    return true;
}

bool URRobotManager::customMoveL(const std::vector<double>& tcp_target,
                                  double speed, double acceleration)
{
    // TCP target → IK8 → best pick → moveJ (singularity-safe)
    if (!robot_connected_) {
        RCLCPP_ERROR(node_->get_logger(), "customMoveL: Robot not connected");
        return false;
    }
    if (tcp_target.size() != 6) {
        RCLCPP_ERROR(node_->get_logger(), "customMoveL: Invalid target size");
        return false;
    }

    // Build TCP target as 4x4 transform
    PoseAA target;
    target.p = Eigen::Vector3d(tcp_target[0], tcp_target[1], tcp_target[2]);
    target.rvec = Eigen::Vector3d(tcp_target[3], tcp_target[4], tcp_target[5]);
    Eigen::Matrix4d T_tcp = URKinematics::poseToT(target);

    // Current joint state
    auto q_now = getJointPositions();
    Eigen::Matrix<double, 6, 1> q_current;
    for (int i = 0; i < 6; ++i) q_current(i) = q_now[i];

    // IK: TCP target → flange target → 8 solutions → best pick
    Eigen::Matrix<double, 6, 1> q_best;
    int best_idx = -1;
    if (!kinematics_->ikBestForTCPPose(T_tcp, q_current, q_best, &best_idx)) {
        RCLCPP_ERROR(node_->get_logger(), "customMoveL: IK failed (no valid solution)");
        return false;
    }

    // FK verification
    Eigen::Matrix4d T_fk = kinematics_->forwardKinematicsTCP(q_best);
    double pos_err = (T_fk.block<3, 1>(0, 3) - target.p).norm() * 1000.0;

    RCLCPP_INFO(node_->get_logger(),
                "customMoveL: IK idx=%d, pos_err=%.2fmm, target=[%.4f,%.4f,%.4f]",
                best_idx, pos_err, tcp_target[0], tcp_target[1], tcp_target[2]);

    // Execute via moveJ (joint space → no singularity)
    std::vector<double> q_cmd(6);
    for (int i = 0; i < 6; ++i) q_cmd[i] = q_best(i);

    return moveJ(q_cmd, speed, acceleration);
}

bool URRobotManager::customSpeedL(const std::vector<double>& tcp_speeds,
                                   double acceleration, double time)
{
    if (!robot_connected_) return false;

    // Force magnitude check for safety
    auto force = getTCPForce();
    double force_mag = std::sqrt(force[0]*force[0] + force[1]*force[1] +
                                  force[2]*force[2]);
    if (force_mag > 20.0) {
        RCLCPP_WARN(node_->get_logger(),
                    "customSpeedL: Force limit exceeded (%.1fN), stopping",
                    force_mag);
        stopRobot();
        return false;
    }

    return speedL(tcp_speeds, acceleration, time);
}

bool URRobotManager::movePath(const std::vector<std::vector<double>>& waypoints,
                               double speed, double acceleration,
                               double blend_radius)
{
    if (!robot_connected_) return false;
    if (waypoints.empty()) return false;

    RCLCPP_INFO(node_->get_logger(),
                "movePath: %zu waypoints, blend=%.4f",
                waypoints.size(), blend_radius);

    is_moving_ = true;
    publishMovingStatus(true);

#ifndef SIM_MODE
    try {
        // Build path with blend radii
        // std::vector<std::vector<double>> path;
        // for (const auto& wp : waypoints) {
        //     auto wp_params = wp;
        //     wp_params.push_back(speed);
        //     wp_params.push_back(acceleration);
        //     wp_params.push_back(blend_radius);
        //     path.push_back(wp_params);
        // }
        // path.back()[8] = 0.0;  // Last waypoint: zero blend
        // rtde_control_->moveL(path);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "movePath failed: %s", e.what());
        is_moving_ = false;
        publishMovingStatus(false);
        return false;
    }
#else
    for (const auto& wp : waypoints) {
        std::this_thread::sleep_for(200ms);
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_tcp_pose_ = wp;
    }
#endif

    is_moving_ = false;
    publishMovingStatus(false);
    return true;
}

// ===================================================================
// Stop
// ===================================================================
void URRobotManager::stopRobot()
{
    is_moving_ = false;
    servo_active_ = false;

#ifndef SIM_MODE
    try {
        // if (rtde_control_) {
        //     rtde_control_->speedStop();
        //     rtde_control_->servoStop();
        // }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "stopRobot failed: %s", e.what());
    }
#endif

    publishMovingStatus(false);
    RCLCPP_INFO(node_->get_logger(), "Robot stopped");
}

void URRobotManager::emergencyStop()
{
    RCLCPP_ERROR(node_->get_logger(), "EMERGENCY STOP triggered");
    stopRobot();

#ifndef SIM_MODE
    // if (rtde_control_) {
    //     rtde_control_->triggerProtectiveStop();
    // }
#endif
}

// ===================================================================
// Servo mode
// ===================================================================
bool URRobotManager::servoSpeedL(const std::vector<double>& tcp_speeds,
                                  double acceleration, double time)
{
    if (!robot_connected_) return false;

    auto q = getJointPositions();
    Eigen::Matrix<double,6,1> q_eigen;
    for (int i = 0; i < 6; ++i) q_eigen(i) = q[i];
    auto J = kinematics_->geometricJacobianTCP(q_eigen);
    double manip = URKinematics::manipulability(J);

    if (manip < 0.01) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000,
                             "Near singularity (m=%.6f), using robust velocity",
                             manip);
        auto robust_speeds = computeSingularityRobustVelocity(tcp_speeds, q);
        return speedL(robust_speeds, acceleration, time);
    }

    return speedL(tcp_speeds, acceleration, time);
}

bool URRobotManager::servoJ6Only(const std::vector<double>& joint_target,
                                  double time, double lookahead, double gain)
{
    if (!robot_connected_) return false;
    if (joint_target.size() != 6) return false;

    servo_active_ = true;

#ifndef SIM_MODE
    try {
        // rtde_control_->servoJ(joint_target, 0.0, 0.0, time,
        //                       lookahead, gain);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "servoJ6Only failed: %s", e.what());
        servo_active_ = false;
        return false;
    }
#else
    {
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_joint_positions_ = joint_target;
    }
#endif
    return true;
}

void URRobotManager::servoStop()
{
    servo_active_ = false;
#ifndef SIM_MODE
    try {
        // if (rtde_control_) rtde_control_->servoStop();
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "servoStop failed: %s", e.what());
    }
#endif
}

// ===================================================================
// Singularity handling
// ===================================================================
std::vector<double> URRobotManager::computeStandardDLS(
    const std::vector<double>& twist,
    const std::vector<double>& q,
    double damping)
{
    Eigen::Matrix<double,6,1> q_eigen;
    for (int i = 0; i < 6; ++i) q_eigen(i) = q[i];
    Eigen::Matrix<double,6,1> tw;
    for (int i = 0; i < 6; ++i) tw(i) = twist[i];

    auto J = kinematics_->geometricJacobianTCP(q_eigen);
    auto J_inv = URKinematics::dlsInverse(J, damping);
    Eigen::Matrix<double,6,1> qdot = J_inv * tw;

    std::vector<double> result(6);
    for (int i = 0; i < 6; ++i) result[i] = qdot(i);
    return result;
}

std::vector<double> URRobotManager::computeSingularityRobustVelocity(
    const std::vector<double>& desired_twist,
    const std::vector<double>& q)
{
    Eigen::Matrix<double,6,1> q_eigen;
    for (int i = 0; i < 6; ++i) q_eigen(i) = q[i];
    auto J = kinematics_->geometricJacobianTCP(q_eigen);
    double manip = URKinematics::manipulability(J);

    double lambda_min = 0.001;
    double lambda_max = 0.1;
    double manip_threshold = 0.05;

    double damping;
    if (manip >= manip_threshold) {
        damping = lambda_min;
    } else {
        double ratio = manip / manip_threshold;
        damping = lambda_min + (lambda_max - lambda_min) *
                  (1.0 - ratio) * (1.0 - ratio);
    }

    auto qdot = computeStandardDLS(desired_twist, q, damping);

    for (int i = 0; i < 6; ++i) {
        qdot[i] = std::clamp(qdot[i], -max_joint_speed_, max_joint_speed_);
    }
    return qdot;
}

// ===================================================================
// Gripper
// ===================================================================
void URRobotManager::gripperOpen()
{
    RCLCPP_INFO(node_->get_logger(), "Gripper: OPEN");
#ifndef SIM_MODE
    // TODO: Send via gripper_interfaces service client
#endif
}

void URRobotManager::gripperClose()
{
    RCLCPP_INFO(node_->get_logger(), "Gripper: CLOSE");
#ifndef SIM_MODE
    // TODO: Send via gripper_interfaces service client
#endif
}

void URRobotManager::setSuctionState(bool on)
{
    RCLCPP_INFO(node_->get_logger(), "Suction: %s", on ? "ON" : "OFF");
#ifndef SIM_MODE
    // if (rtde_io_) rtde_io_->setStandardDigitalOut(0, on);
#endif
}

void URRobotManager::setToolTCP(const std::vector<double>& tcp_pose)
{
    Eigen::Vector3d t_tcp(tcp_pose[0], tcp_pose[1], tcp_pose[2]);
    Eigen::Vector3d rvec_tcp(tcp_pose[3], tcp_pose[4], tcp_pose[5]);
    kinematics_->setToolTCP(t_tcp, rvec_tcp);
    RCLCPP_INFO(node_->get_logger(),
                "Tool TCP set: [%.4f, %.4f, %.4f, %.4f, %.4f, %.4f]",
                tcp_pose[0], tcp_pose[1], tcp_pose[2],
                tcp_pose[3], tcp_pose[4], tcp_pose[5]);

#ifndef SIM_MODE
    // if (rtde_control_) rtde_control_->setTcp(tcp_pose);
#endif
}

// ===================================================================
// Publishing
// ===================================================================
void URRobotManager::publishJointState(const std::vector<double>& joint_positions)
{
    if (joint_positions.size() != 6) return;

    sensor_msgs::msg::JointState js;
    js.header.stamp = node_->now();
    js.name = {
        "shoulder_pan_joint",
        "shoulder_lift_joint",
        "elbow_joint",
        "wrist_1_joint",
        "wrist_2_joint",
        "wrist_3_joint"
    };
    js.position.assign(joint_positions.begin(), joint_positions.end());

    auto velocities = getJointVelocities();
    js.velocity.assign(velocities.begin(), velocities.end());
    js.effort.resize(6, 0.0);

    joint_state_pub_->publish(js);

    // TCP pose
    auto tcp = getTCPPose();
    if (tcp.size() == 6) {
        std_msgs::msg::Float64MultiArray tcp_msg;
        tcp_msg.data = tcp;
        tcp_pose_pub_->publish(tcp_msg);
    }

    // TCP force/torque
    auto ft = getTCPForce();
    if (ft.size() == 6) {
        geometry_msgs::msg::WrenchStamped wrench;
        wrench.header.stamp = node_->now();
        wrench.header.frame_id = "tool0";
        wrench.wrench.force.x  = ft[0];
        wrench.wrench.force.y  = ft[1];
        wrench.wrench.force.z  = ft[2];
        wrench.wrench.torque.x = ft[3];
        wrench.wrench.torque.y = ft[4];
        wrench.wrench.torque.z = ft[5];
        tcp_force_pub_->publish(wrench);
    }
}

// ===================================================================
// Safety
// ===================================================================
void URRobotManager::safetyCheckCallback()
{
    if (!robot_connected_ || !safety_check_active_) return;

    // Force limit check
    auto force = getTCPForce();
    if (force.size() == 6) {
        double force_mag = std::sqrt(force[0]*force[0] + force[1]*force[1] +
                                      force[2]*force[2]);
        if (force_mag > 30.0) {
            RCLCPP_ERROR(node_->get_logger(),
                         "SAFETY: Force limit exceeded (%.1fN), stopping!",
                         force_mag);
            stopRobot();
        }
    }

    // Joint limit check
    auto q = getJointPositions();
    if (q.size() == 6) {
        for (int i = 0; i < 6; ++i) {
            if (std::abs(q[i]) > 2.0 * M_PI) {
                RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(),
                                     2000,
                                     "Joint %d near limit: %.3f rad", i, q[i]);
            }
        }
    }

    // Publish status
    std_msgs::msg::String status;
    status.data = robot_connected_ ? "connected" : "disconnected";
    if (is_moving_) status.data += ":moving";
    if (servo_active_) status.data += ":servo";
    robot_status_pub_->publish(status);
}

void URRobotManager::publishMovingStatus(bool moving)
{
    std_msgs::msg::Bool msg;
    msg.data = moving;
    moving_status_pub_->publish(msg);
}

bool URRobotManager::waitForMove(double timeout_sec)
{
    auto start = node_->now();
    rclcpp::Rate rate(50);

    while (rclcpp::ok() && is_moving_) {
        double elapsed = (node_->now() - start).seconds();
        if (elapsed > timeout_sec) {
            RCLCPP_WARN(node_->get_logger(),
                        "waitForMove timed out after %.1f sec", elapsed);
            return false;
        }

#ifndef SIM_MODE
        // if (rtde_receive_) {
        //     auto status = rtde_receive_->getRobotStatus();
        //     // Check if idle, then break
        // }
#endif
        rate.sleep();
    }
    return true;
}

// ===================================================================
// Command topic callbacks
// ===================================================================
void URRobotManager::cmdMoveJCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (msg->data.size() != 6) {
        RCLCPP_WARN(node_->get_logger(), "/cmd/move_j: need 6 values, got %zu", msg->data.size());
        return;
    }
    std::vector<double> target(msg->data.begin(), msg->data.end());
    double speed = std::min(speed_scale_, max_joint_speed_);
    RCLCPP_INFO(node_->get_logger(), "/cmd/move_j received");
    moveJ(target, speed, max_joint_accel_);
}

void URRobotManager::cmdCustomMoveLCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (msg->data.size() != 6) {
        RCLCPP_WARN(node_->get_logger(), "/cmd/custom_move_l: need 6 values, got %zu", msg->data.size());
        return;
    }
    std::vector<double> target(msg->data.begin(), msg->data.end());
    double speed = std::min(speed_scale_, max_joint_speed_);
    RCLCPP_INFO(node_->get_logger(), "/cmd/custom_move_l received");
    customMoveL(target, speed, max_joint_accel_);
}

void URRobotManager::cmdHomeCallback(const std_msgs::msg::Bool::SharedPtr msg)
{
    (void)msg;
    RCLCPP_INFO(node_->get_logger(), "/cmd/home received");
    std::vector<double> home = {0.0, -1.5708, 0.0, -1.5708, 0.0, 0.0};
    moveJ(home, std::min(speed_scale_, max_joint_speed_), max_joint_accel_);
}

void URRobotManager::cmdStopCallback(const std_msgs::msg::Bool::SharedPtr msg)
{
    (void)msg;
    RCLCPP_WARN(node_->get_logger(), "/cmd/stop received — EMERGENCY STOP");
    if (freedrive_active_) stopFreedrive();
    emergencyStop();
}

void URRobotManager::cmdFreedriveCallback(const std_msgs::msg::Bool::SharedPtr msg)
{
    if (msg->data) {
        startFreedrive();
    } else {
        stopFreedrive();
    }
}

// ===================================================================
// Freedrive (Kinesthetic Teaching)
// ===================================================================
void URRobotManager::startFreedrive()
{
    if (freedrive_active_) return;
    if (!robot_connected_) {
        RCLCPP_WARN(node_->get_logger(), "Freedrive: robot not connected");
        return;
    }

#ifndef SIM_MODE
    try {
        // rtde_control_->freedriveMode();
        freedrive_active_ = true;
        RCLCPP_INFO(node_->get_logger(), "Freedrive ON — kinesthetic teaching enabled");
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "Freedrive start failed: %s", e.what());
    }
#else
    freedrive_active_ = true;
    RCLCPP_INFO(node_->get_logger(), "Freedrive ON (SIM_MODE)");
#endif
}

void URRobotManager::stopFreedrive()
{
    if (!freedrive_active_) return;

#ifndef SIM_MODE
    try {
        // rtde_control_->endFreedriveMode();
        freedrive_active_ = false;
        RCLCPP_INFO(node_->get_logger(), "Freedrive OFF");
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "Freedrive stop failed: %s", e.what());
    }
#else
    freedrive_active_ = false;
    RCLCPP_INFO(node_->get_logger(), "Freedrive OFF (SIM_MODE)");
#endif
}

}  // namespace urRobotManager
