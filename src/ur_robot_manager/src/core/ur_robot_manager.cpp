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
#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <ur_rtde/rtde_io_interface.h>
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
      q_ref_(Eigen::Matrix<double,6,1>::Zero())
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

    cmd_reconnect_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/reconnect", 10,
        [this](const std_msgs::msg::Bool::SharedPtr) {
            RCLCPP_INFO(node_->get_logger(), "/cmd/reconnect received");
            reconnectControl();
        });

    // Servo twist command subscriber (for servo thread)
    node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/cmd/servo_twist", 10,
        [this](const std_msgs::msg::Float64MultiArray::SharedPtr msg) {
            if (msg->data.size() != 6) return;
            Eigen::Matrix<double,6,1> twist;
            for (int i = 0; i < 6; ++i) twist(i) = msg->data[i];
            setServoTwist(twist);
        });

    // Servo thread start/stop subscriber
    node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/servo_enable", 10,
        [this](const std_msgs::msg::Bool::SharedPtr msg) {
            if (msg->data) {
                startServoThread();
            } else {
                stopServoThread();
            }
        });

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
    stopServoThread();
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
        rtde_control_ = std::make_shared<ur_rtde::RTDEControlInterface>(robot_ip_);
        rtde_receive_ = std::make_shared<ur_rtde::RTDEReceiveInterface>(robot_ip_);
        rtde_io_ = std::make_shared<ur_rtde::RTDEIOInterface>(robot_ip_);
        robot_connected_ = true;
        RCLCPP_INFO(node_->get_logger(), "Connected to robot at %s",
                    robot_ip_.c_str());
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(),
                     "Failed to connect to robot at %s: %s",
                     robot_ip_.c_str(), e.what());
        rtde_control_.reset();
        rtde_receive_.reset();
        rtde_io_.reset();
        robot_connected_ = false;
        RCLCPP_WARN(node_->get_logger(),
                    "Running without robot connection. Check: "
                    "1) Robot power on  2) Remote Control mode on pendant  "
                    "3) IP reachable (ping %s)", robot_ip_.c_str());
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
        if (rtde_control_) {
            rtde_control_->stopScript();
            rtde_control_->disconnect();
        }
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
    if (robot_connected_ && rtde_receive_) {
        current_joint_positions_ = rtde_receive_->getActualQ();
    }
#endif
    return current_joint_positions_;
}

std::vector<double> URRobotManager::getJointVelocities()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (robot_connected_ && rtde_receive_) {
        current_joint_velocities_ = rtde_receive_->getActualQd();
    }
#endif
    return current_joint_velocities_;
}

std::vector<double> URRobotManager::getTCPPose()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (robot_connected_ && rtde_receive_) {
        current_tcp_pose_ = rtde_receive_->getActualTCPPose();
    }
#endif
    return current_tcp_pose_;
}

std::vector<double> URRobotManager::getTCPForce()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (robot_connected_ && rtde_receive_) {
        current_tcp_force_ = rtde_receive_->getActualTCPForce();
    }
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
        rtde_control_->moveJ(joint_target, s, a, async);
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
        rtde_control_->moveL(pose_target, s, a, async);
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
        rtde_control_->speedJ(clamped, acceleration, time);
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
        rtde_control_->speedL(clamped, acceleration, time);
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
    // TCP target → sync TCP offset → IK8 → best pick → moveJ (singularity-safe)
    if (!robot_connected_) {
        RCLCPP_ERROR(node_->get_logger(), "customMoveL: Robot not connected");
        return false;
    }
    if (tcp_target.size() != 6) {
        RCLCPP_ERROR(node_->get_logger(), "customMoveL: Invalid target size");
        return false;
    }

    // (0) Sync TCP offset from robot controller
#ifndef SIM_MODE
    if (rtde_control_) {
        auto t_offset = rtde_control_->getTCPOffset();
        if (t_offset.size() == 6) {
            Eigen::Vector3d tcp_t(t_offset[0], t_offset[1], t_offset[2]);
            Eigen::Vector3d tcp_r(t_offset[3], t_offset[4], t_offset[5]);
            kinematics_->setToolTCP(tcp_t, tcp_r);
            RCLCPP_DEBUG(node_->get_logger(),
                        "customMoveL: TCP offset synced [%.4f,%.4f,%.4f,%.4f,%.4f,%.4f]",
                        t_offset[0], t_offset[1], t_offset[2],
                        t_offset[3], t_offset[4], t_offset[5]);
        }
    }
#endif

    // (1) Build TCP target as 4x4 transform
    PoseAA target;
    target.p = Eigen::Vector3d(tcp_target[0], tcp_target[1], tcp_target[2]);
    target.rvec = Eigen::Vector3d(tcp_target[3], tcp_target[4], tcp_target[5]);
    Eigen::Matrix4d T_tcp = URKinematics::poseToT(target);

    // (2) Current joint state
    auto q_now = getJointPositions();
    Eigen::Matrix<double, 6, 1> q_current;
    for (int i = 0; i < 6; ++i) q_current(i) = q_now[i];

    // (3) FK verification of current state
    Eigen::Matrix4d T_fk_cur = kinematics_->forwardKinematicsTCP(q_current);
    auto tcp_meas = getTCPPose();
    RCLCPP_DEBUG(node_->get_logger(),
                "customMoveL: FK_cur=[%.4f,%.4f,%.4f] meas=[%.4f,%.4f,%.4f]",
                T_fk_cur(0,3), T_fk_cur(1,3), T_fk_cur(2,3),
                tcp_meas[0], tcp_meas[1], tcp_meas[2]);

    // (4) IK: TCP target → flange target → 8 solutions → best pick
    Eigen::Matrix<double, 6, 1> q_best;
    int best_idx = -1;
    if (!kinematics_->ikBestForTCPPose(T_tcp, q_current, q_best, &best_idx)) {
        RCLCPP_ERROR(node_->get_logger(), "customMoveL: IK failed (no valid solution)");
        return false;
    }

    // (5) FK verification of solution
    Eigen::Matrix4d T_fk = kinematics_->forwardKinematicsTCP(q_best);
    double pos_err = (T_fk.block<3, 1>(0, 3) - target.p).norm() * 1000.0;
    Eigen::Matrix3d R_err = T_fk.block<3,3>(0,0) * URKinematics::rvecToR(target.rvec).transpose();
    double ori_err = URKinematics::RToRvec(R_err).norm() * 180.0 / M_PI;

    RCLCPP_INFO(node_->get_logger(),
                "customMoveL: IK idx=%d, pos_err=%.2fmm, ori_err=%.2fdeg, "
                "target=[%.4f,%.4f,%.4f]",
                best_idx, pos_err, ori_err,
                tcp_target[0], tcp_target[1], tcp_target[2]);

    // Safety: reject if IK error too large
    if (pos_err > 5.0) {  // 5mm threshold
        RCLCPP_ERROR(node_->get_logger(),
                    "customMoveL: IK position error too large (%.2fmm), aborting", pos_err);
        return false;
    }

    // (6) Execute via moveJ (joint space → no singularity)
    std::vector<double> q_cmd(6);
    for (int i = 0; i < 6; ++i) q_cmd[i] = q_best(i);

    return moveJ(q_cmd, speed, acceleration);
}

void URRobotManager::customSpeedL(const Eigen::Matrix<double,6,1>& base_twist,
                                   double a, double lookahead)
{
    // Original customSpeedL_ algorithm: TCP twist → adaptive DLS + β correction → speedJ
    if (!robot_connected_) return;

    auto q_now = getJointPositions();
    Eigen::Matrix<double,6,1> q;
    for (int i = 0; i < 6; ++i) q(i) = q_now[i];

    Eigen::Matrix<double,6,6> J = kinematics_->geometricJacobianTCP(q);

    // Adaptive lambda based on manipulability
    double w = std::sqrt(std::max(0.0, (J * J.transpose()).determinant()));
    double lambda;
    if (w >= speedl_params_.w_threshold) {                          // #TUNABLE
        lambda = speedl_params_.lambda_min;                         // #TUNABLE
    } else {
        double t = (speedl_params_.w_threshold - w) / speedl_params_.w_threshold;
        lambda = speedl_params_.lambda_min +
                 t * (speedl_params_.lambda_max - speedl_params_.lambda_min); // #TUNABLE
    }

    Eigen::Matrix<double,6,6> JJt = J * J.transpose();
    Eigen::Matrix<double,6,6> A = JJt + (lambda * lambda) * Eigen::Matrix<double,6,6>::Identity();

    // β normalization: match knob input TCP speed to actual TCP speed
    Eigen::Matrix<double,6,1> v0 = base_twist;

    // Predict qdot and resulting TCP velocity
    Eigen::Matrix<double,6,1> vA0 = A.ldlt().solve(v0);
    Eigen::Matrix<double,6,1> qdot0 = J.transpose() * vA0;
    Eigen::Matrix<double,6,1> v_tilde = J * qdot0;

    // β = |v_ref_lin| / |v_tilde_lin| (linear velocity only)
    const double v_ref_lin = v0.head<3>().norm();
    const double v_til_lin = v_tilde.head<3>().norm();

    double beta = 1.0;
    if (v_ref_lin > speedl_params_.eps_norm) {
        beta = v_ref_lin / std::max(v_til_lin, speedl_params_.eps_norm);
        beta = std::clamp(beta, speedl_params_.beta_min, speedl_params_.beta_max); // #TUNABLE
    }

    // Apply β correction to both linear and angular
    Eigen::Matrix<double,6,1> v_cmd = v0;
    v_cmd.head<3>() *= beta;
    v_cmd.tail<3>() *= beta;

    // Final qdot via DLS
    Eigen::Matrix<double,6,1> vA = A.ldlt().solve(v_cmd);
    Eigen::Matrix<double,6,1> qdot = J.transpose() * vA;

    // Velocity limit (proportional scaling)
    double max_abs_qdot = qdot.cwiseAbs().maxCoeff();
    if (max_abs_qdot > speedl_params_.qdot_lim) {                   // #TUNABLE
        qdot *= (speedl_params_.qdot_lim / max_abs_qdot);
    }

    // Execute via speedJ (joint space → singularity-safe)
    std::vector<double> qd(6);
    for (int i = 0; i < 6; ++i) qd[i] = qdot(i);

#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        rtde_control_->speedJ(qd, a, lookahead);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "customSpeedL failed: %s", e.what());
    }
#endif
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
        std::vector<std::vector<double>> path;
        for (const auto& wp : waypoints) {
            auto wp_params = wp;
            wp_params.push_back(speed);
            wp_params.push_back(acceleration);
            wp_params.push_back(blend_radius);
            path.push_back(wp_params);
        }
        path.back()[8] = 0.0;  // Last waypoint: zero blend
        rtde_control_->moveL(path);
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
    servo_mode_active_ = false;

#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        if (rtde_control_) {
            rtde_control_->stopJ(2.0);      // stop moveJ/speedJ (joint deceleration)
            rtde_control_->stopL(10.0);     // stop moveL/speedL (TCP deceleration)
            rtde_control_->servoStop(3.2);  // stop servoJ/servoL
        }
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

    is_moving_ = false;
    servo_active_ = false;
    servo_mode_active_ = false;

#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        if (rtde_control_) {
            rtde_control_->stopJ(2.0);
            rtde_control_->stopL(10.0);
            rtde_control_->servoStop(3.2);
            rtde_control_->triggerProtectiveStop();
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "emergencyStop failed: %s", e.what());
    }
#endif

    publishMovingStatus(false);
}

// ===================================================================
// Servo mode
// ===================================================================
void URRobotManager::servoSpeedL(const Eigen::Matrix<double,6,1>& twist_base)
{
    // Original servoSpeedL: Selective Damping SVD → q_ref_ integration → servoJ
    if (!robot_connected_) return;

    auto q_vec = getJointPositions();
    Eigen::Matrix<double,6,1> q_now;
    for (int i = 0; i < 6; ++i) q_now(i) = q_vec[i];

    // Servo mode init
    if (!servo_mode_active_) {
        q_ref_ = q_now;
        servo_mode_active_ = true;
        last_servo_time_ = std::chrono::steady_clock::now();
        RCLCPP_INFO(node_->get_logger(), "Servo mode activated");
    }

    // Actual elapsed time
    auto now = std::chrono::steady_clock::now();
    double dt_actual = std::chrono::duration<double>(now - last_servo_time_).count();
    dt_actual = std::clamp(dt_actual, 0.001, 0.1);
    last_servo_time_ = now;

    // Selective Damping SVD
    Eigen::Matrix<double,6,6> J = kinematics_->geometricJacobianTCP(q_now);
    Eigen::JacobiSVD<Eigen::Matrix<double,6,6>> svd(
        J, Eigen::ComputeFullU | Eigen::ComputeFullV);
    const auto& U = svd.matrixU();
    const auto& V = svd.matrixV();
    const auto& S = svd.singularValues();

    // Per-singular-value adaptive damping
    Eigen::Matrix<double,6,1> S_inv;
    for (int i = 0; i < 6; ++i) {
        if (S(i) > servo_params_.sigma_min) {                       // #TUNABLE
            S_inv(i) = 1.0 / S(i);
        } else {
            double ratio = S(i) / servo_params_.sigma_min;
            double lam = servo_params_.lambda_max * (1.0 - ratio);  // #TUNABLE
            S_inv(i) = S(i) / (S(i) * S(i) + lam * lam);
        }
    }

    Eigen::Matrix<double,6,1> qdot = V * S_inv.asDiagonal() * U.transpose() * twist_base;

    // Velocity limit (proportional scaling)
    double max_val = qdot.cwiseAbs().maxCoeff();
    if (max_val > servo_params_.qdot_max) {                         // #TUNABLE
        qdot *= (servo_params_.qdot_max / max_val);
    }

    // Position integration
    q_ref_ += qdot * dt_actual;

    // Joint limit clamping
    for (int i = 0; i < 6; ++i) {
        q_ref_(i) = std::clamp(q_ref_(i),
                               safety_params_.joint_limits_lower[i] + 0.05,
                               safety_params_.joint_limits_upper[i] - 0.05);
    }

    // Drift correction
    double ref_error = (q_ref_ - q_now).norm();
    if (ref_error > servo_params_.ref_error_max) {                  // #TUNABLE
        RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000,
                             "Servo ref drift: %.3f rad, resetting", ref_error);
        q_ref_ = q_now;
    }

    // servoJ command
    std::vector<double> q_cmd(6);
    for (int i = 0; i < 6; ++i) q_cmd[i] = q_ref_(i);

#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        rtde_control_->servoJ(q_cmd, 0, 0,
                              servo_params_.dt,             // #TUNABLE
                              servo_params_.lookahead,      // #TUNABLE
                              servo_params_.gain);          // #TUNABLE
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "servoSpeedL failed: %s", e.what());
    }
#else
    {
        std::lock_guard<std::mutex> lock(state_mutex_);
        for (int i = 0; i < 6; ++i) current_joint_positions_[i] = q_cmd[i];
    }
#endif
    servo_active_ = true;
}

void URRobotManager::servoJ6Only(double wz_tcp)
{
    // Original servoJ6Only: J6-only velocity integration → servoJ
    if (!robot_connected_) return;

    auto q_vec = getJointPositions();
    Eigen::Matrix<double,6,1> q_now;
    for (int i = 0; i < 6; ++i) q_now(i) = q_vec[i];

    // Servo mode init
    if (!servo_mode_active_) {
        q_ref_ = q_now;
        servo_mode_active_ = true;
        last_servo_time_ = std::chrono::steady_clock::now();
    }

    // Elapsed time
    auto now = std::chrono::steady_clock::now();
    double dt_actual = std::chrono::duration<double>(now - last_servo_time_).count();
    dt_actual = std::clamp(dt_actual, 0.001, 0.1);
    last_servo_time_ = now;

    // J1-J5: track current position (drift prevention)
    for (int i = 0; i < 5; ++i) {
        q_ref_(i) = q_now(i);
    }

    // J6 only: velocity integration
    double j6_vel = std::clamp(wz_tcp,
                               -servo_params_.qdot_max, servo_params_.qdot_max); // #TUNABLE
    q_ref_(5) += j6_vel * dt_actual;

    // Joint limit
    q_ref_(5) = std::clamp(q_ref_(5),
                           safety_params_.joint_limits_lower[5] + 0.05,
                           safety_params_.joint_limits_upper[5] - 0.05);

    // servoJ command
    std::vector<double> q_cmd(6);
    for (int i = 0; i < 6; ++i) q_cmd[i] = q_ref_(i);

#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        rtde_control_->servoJ(q_cmd, 0, 0,
                              servo_params_.dt,
                              servo_params_.lookahead,
                              servo_params_.gain);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "servoJ6Only failed: %s", e.what());
    }
#endif
    servo_active_ = true;
}

void URRobotManager::servoStop(double deceleration)
{
    servo_active_ = false;
    servo_mode_active_ = false;
#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        if (rtde_control_) rtde_control_->servoStop(deceleration);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "servoStop failed: %s", e.what());
    }
#endif
}

// NOTE: computeStandardDLS / computeSingularityRobustVelocity removed.
// Singularity handling is now integrated into customSpeedL (adaptive DLS + β)
// and servoSpeedL (Selective Damping SVD).

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
    if (rtde_io_) rtde_io_->setStandardDigitalOut(0, on);
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
    if (rtde_control_) rtde_control_->setTcp(tcp_pose);
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

    // Force limit check → stop                                     // #TUNABLE force_limit
    auto force = getTCPForce();
    if (force.size() == 6) {
        double force_mag = std::sqrt(force[0]*force[0] + force[1]*force[1] +
                                      force[2]*force[2]);
        if (force_mag > safety_params_.force_limit) {
            RCLCPP_ERROR(node_->get_logger(),
                         "SAFETY: Force %.1fN > %.1fN limit, stopping!",
                         force_mag, safety_params_.force_limit);
            stopRobot();
        }
    }

    // Joint limit check → stop (original checkJointLimits pattern)
    if (!checkJointLimits()) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000,
                             "SAFETY: Joint limit reached, stopping!");
        stopRobot();
    }

    // Publish status
    std_msgs::msg::String status;
    status.data = robot_connected_ ? "connected" : "disconnected";
    if (is_moving_) status.data += ":moving";
    if (servo_active_) status.data += ":servo";
    if (servo_mode_active_) status.data += ":servo_mode";
    if (freedrive_active_) status.data += ":freedrive";
    robot_status_pub_->publish(status);
}

bool URRobotManager::checkJointLimits()
{
    auto q = getJointPositions();
    if (q.size() != 6) return false;

    for (int i = 0; i < 6; ++i) {
        double dist_upper = safety_params_.joint_limits_upper[i] - q[i];
        double dist_lower = q[i] - safety_params_.joint_limits_lower[i];

        if (dist_upper < safety_params_.joint_limit_threshold ||    // #TUNABLE
            dist_lower < safety_params_.joint_limit_threshold) {
            RCLCPP_WARN(node_->get_logger(),
                        "Joint %d approaching limit: %.3f rad (upper=%.3f, lower=%.3f)",
                        i, q[i], safety_params_.joint_limits_upper[i],
                        safety_params_.joint_limits_lower[i]);
            return false;
        }
    }
    return true;
}

bool URRobotManager::setPayload(double mass, const std::vector<double>& cog)
{
#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        if (rtde_control_) {
            rtde_control_->setPayload(mass, cog);
            RCLCPP_INFO(node_->get_logger(), "Payload set: mass=%.2f kg", mass);
            return true;
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "setPayload failed: %s", e.what());
    }
#endif
    return false;
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
        if (rtde_receive_) {
            auto mode = rtde_receive_->getRobotMode();
            // Mode 7 = RUNNING (idle), check if movement complete
            if (mode == 7 && !rtde_control_->isProgramRunning()) {
                is_moving_ = false;
                break;
            }
        }
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
    moveJ(target, speed, max_joint_accel_, true);  // async=true so stop can interrupt
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
        rtde_control_->freedriveMode();
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
        rtde_control_->endFreedriveMode();
        freedrive_active_ = false;
        RCLCPP_INFO(node_->get_logger(), "Freedrive OFF");
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "Freedrive stop failed: %s", e.what());
    }

    // Reconnect control interface (freedrive can leave script in bad state)
    reconnectControl();
#else
    freedrive_active_ = false;
    RCLCPP_INFO(node_->get_logger(), "Freedrive OFF (SIM_MODE)");
#endif
}

void URRobotManager::reconnectControl()
{
#ifndef SIM_MODE
    try {
        RCLCPP_INFO(node_->get_logger(), "Reconnecting control interface...");
        rtde_control_->reconnect();
        RCLCPP_INFO(node_->get_logger(), "Control interface reconnected");
    } catch (const std::exception& e) {
        RCLCPP_WARN(node_->get_logger(), "Reconnect failed, creating new interface: %s", e.what());
        try {
            rtde_control_ = std::make_shared<ur_rtde::RTDEControlInterface>(robot_ip_);
            RCLCPP_INFO(node_->get_logger(), "New control interface created");
        } catch (const std::exception& e2) {
            RCLCPP_ERROR(node_->get_logger(), "Failed to recreate control interface: %s", e2.what());
            robot_connected_ = false;
        }
    }
#endif
}

// ===================================================================
// Servo Thread (500Hz dedicated control loop)
// ===================================================================
void URRobotManager::startServoThread()
{
    if (servo_thread_running_) {
        RCLCPP_WARN(node_->get_logger(), "Servo thread already running");
        return;
    }

    servo_mode_active_ = false;  // will be set true on first servoSpeedL call
    servo_thread_running_ = true;
    servo_thread_ = std::thread(&URRobotManager::servoThreadLoop, this);

    RCLCPP_INFO(node_->get_logger(), "Servo thread started (%.0fHz)",
                1.0 / servo_params_.dt);
}

void URRobotManager::stopServoThread()
{
    servo_thread_running_ = false;
    if (servo_thread_.joinable()) {
        servo_thread_.join();
    }
    servoStop();
    servo_mode_active_ = false;
    RCLCPP_INFO(node_->get_logger(), "Servo thread stopped");
}

void URRobotManager::setServoTwist(const Eigen::Matrix<double,6,1>& twist)
{
    std::lock_guard<std::mutex> lock(servo_twist_mutex_);
    servo_twist_cmd_ = twist;
}

void URRobotManager::servoThreadLoop()
{
    // This runs in a dedicated thread at ~500Hz using ur_rtde timing.
    //
    // Flow:
    //   1. External code calls setServoTwist(twist) to update target twist
    //   2. This loop reads the twist and calls servoSpeedL() each cycle
    //   3. servoSpeedL() does: SVD inverse → q_ref_ integration → servoJ
    //   4. initPeriod()/waitPeriod() ensures precise timing
    //
    // Architecture:
    //   [/cmd/servo_twist topic]  →  setServoTwist()  (just stores the vector)
    //           ↓
    //   [servo thread 500Hz]  →  servoSpeedL(twist)  →  servoJ(q_ref_)
    //           ↓
    //   [UR controller]  →  robot moves

    RCLCPP_INFO(node_->get_logger(), "Servo loop running at %.0fHz", 1.0 / servo_params_.dt);

    while (servo_thread_running_ && rclcpp::ok()) {
#ifndef SIM_MODE
        if (!robot_connected_ || !rtde_control_) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        auto t_start = rtde_control_->initPeriod();

        // Read current twist command (thread-safe)
        Eigen::Matrix<double,6,1> twist;
        {
            std::lock_guard<std::mutex> lock(servo_twist_mutex_);
            twist = servo_twist_cmd_;
        }

        // Only servo if twist is non-zero
        double twist_norm = twist.norm();
        if (twist_norm > 1e-6) {
            servoSpeedL(twist);
        } else if (servo_mode_active_) {
            // Twist is zero but servo was active → hold position
            // (servoSpeedL with zero twist will keep q_ref_ stable)
            servoSpeedL(Eigen::Matrix<double,6,1>::Zero());
        }

        rtde_control_->waitPeriod(t_start);
#else
        std::this_thread::sleep_for(
            std::chrono::microseconds(static_cast<int>(servo_params_.dt * 1e6)));
#endif
    }

    RCLCPP_INFO(node_->get_logger(), "Servo loop exited");
}

}  // namespace urRobotManager
