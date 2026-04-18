/**
 * @file ur_robot_manager.cpp
 * @brief ROS2 adapter around URHardware.
 */

#include "ur_robot_manager/core/ur_robot_manager.h"

#include <Eigen/Dense>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace urRobotManager {

// ===================================================================
// QoS helpers
// ===================================================================
// Commands: reliable, keep_last(1) — minimal latency, don't drop critical cmds
static rclcpp::QoS cmdQoS() {
    rclcpp::QoS q(rclcpp::KeepLast(1));
    q.reliable();
    return q;
}

// State publish: reliable, keep_last(1) — monitors care about latest sample
static rclcpp::QoS stateQoS() {
    rclcpp::QoS q(rclcpp::KeepLast(1));
    q.reliable();
    return q;
}

// Status: reliable, keep_last(1)
static rclcpp::QoS statusQoS() {
    rclcpp::QoS q(rclcpp::KeepLast(1));
    q.reliable();
    return q;
}

// ===================================================================
// Constructor / Destructor
// ===================================================================
URRobotManager::URRobotManager(rclcpp::Node::SharedPtr node,
                                const std::string& robot_ip)
    : node_(node)
{
    RCLCPP_INFO(node_->get_logger(), "URRobotManager: Initializing for %s",
                robot_ip.c_str());

    // Hardware layer with logger bridge into rclcpp
    hw_ = std::make_unique<URHardware>(
        robot_ip,
        [this](LogLevel lvl, const std::string& msg) { hwLog(lvl, msg); });

    // ---- Callback groups ----
    // Commands → Reentrant: multiple cmd callbacks can run in parallel
    cmd_cb_group_ = node_->create_callback_group(
        rclcpp::CallbackGroupType::Reentrant);
    // Pub/safety timers → MutuallyExclusive: serialize state read/publish
    pub_cb_group_ = node_->create_callback_group(
        rclcpp::CallbackGroupType::MutuallyExclusive);

    rclcpp::SubscriptionOptions cmd_opts;
    cmd_opts.callback_group = cmd_cb_group_;

    // ---- Publishers ----
    joint_state_pub_ = node_->create_publisher<sensor_msgs::msg::JointState>(
        "/joint_states", stateQoS());
    tcp_pose_pub_ = node_->create_publisher<std_msgs::msg::Float64MultiArray>(
        "/tcp_pose", stateQoS());
    tcp_force_pub_ = node_->create_publisher<geometry_msgs::msg::WrenchStamped>(
        "/tcp_wrench", stateQoS());
    robot_status_pub_ = node_->create_publisher<std_msgs::msg::String>(
        "/robot_status", statusQoS());
    moving_status_pub_ = node_->create_publisher<std_msgs::msg::Bool>(
        "/is_moving", statusQoS());

    // ---- Subscribers (all in cmd_cb_group_) ----
    speed_scale_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/speed_scale", cmdQoS(),
        std::bind(&URRobotManager::speedScaleCallback, this, _1), cmd_opts);

    cmd_movej_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/cmd/move_j", cmdQoS(),
        std::bind(&URRobotManager::cmdMoveJCallback, this, _1), cmd_opts);

    cmd_custom_movel_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/cmd/custom_move_l", cmdQoS(),
        std::bind(&URRobotManager::cmdCustomMoveLCallback, this, _1), cmd_opts);

    cmd_home_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/home", cmdQoS(),
        std::bind(&URRobotManager::cmdHomeCallback, this, _1), cmd_opts);

    cmd_stop_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/stop", cmdQoS(),
        std::bind(&URRobotManager::cmdStopCallback, this, _1), cmd_opts);

    cmd_freedrive_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/freedrive", cmdQoS(),
        std::bind(&URRobotManager::cmdFreedriveCallback, this, _1), cmd_opts);

    cmd_reconnect_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/reconnect", cmdQoS(),
        std::bind(&URRobotManager::cmdReconnectCallback, this, _1), cmd_opts);

    cmd_servo_twist_sub_ = node_->create_subscription<std_msgs::msg::Float64MultiArray>(
        "/cmd/servo_twist", cmdQoS(),
        std::bind(&URRobotManager::cmdServoTwistCallback, this, _1), cmd_opts);

    cmd_servo_enable_sub_ = node_->create_subscription<std_msgs::msg::Bool>(
        "/cmd/servo_enable", cmdQoS(),
        std::bind(&URRobotManager::cmdServoEnableCallback, this, _1), cmd_opts);

    // ---- Timers (100Hz, pub_cb_group_) ----
    publish_timer_ = node_->create_wall_timer(
        10ms,
        std::bind(&URRobotManager::publishStateCallback, this),
        pub_cb_group_);

    safety_timer_ = node_->create_wall_timer(
        10ms,
        std::bind(&URRobotManager::safetyCheckCallback, this),
        pub_cb_group_);

    RCLCPP_INFO(node_->get_logger(),
                "URRobotManager: Initialization complete (%s)", robot_ip.c_str());
}

URRobotManager::~URRobotManager()
{
    RCLCPP_INFO(node_->get_logger(), "URRobotManager: Shutting down");
    hw_.reset();  // URHardware destructor stops servo, stops robot, disconnects
}

// ===================================================================
// Log bridge
// ===================================================================
void URRobotManager::hwLog(LogLevel lvl, const std::string& msg)
{
    auto logger = node_->get_logger();
    switch (lvl) {
        case LogLevel::Debug: RCLCPP_DEBUG(logger, "%s", msg.c_str()); break;
        case LogLevel::Info:  RCLCPP_INFO (logger, "%s", msg.c_str()); break;
        case LogLevel::Warn:  RCLCPP_WARN (logger, "%s", msg.c_str()); break;
        case LogLevel::Error: RCLCPP_ERROR(logger, "%s", msg.c_str()); break;
    }
}

// ===================================================================
// State publish (100Hz)
// ===================================================================
void URRobotManager::publishStateCallback()
{
    if (!hw_->isConnected()) return;

    auto q = hw_->getJointPositions();
    if (q.size() != 6) return;
    auto qd = hw_->getJointVelocities();
    auto tcp = hw_->getTCPPose();
    auto ft = hw_->getTCPForce();

    // Joint state
    sensor_msgs::msg::JointState js;
    js.header.stamp = node_->now();
    js.name = {"shoulder_pan_joint","shoulder_lift_joint","elbow_joint",
                "wrist_1_joint","wrist_2_joint","wrist_3_joint"};
    js.position.assign(q.begin(), q.end());
    if (qd.size() == 6) js.velocity.assign(qd.begin(), qd.end());
    js.effort.resize(6, 0.0);
    joint_state_pub_->publish(js);

    // TCP pose
    if (tcp.size() == 6) {
        std_msgs::msg::Float64MultiArray tcp_msg;
        tcp_msg.data = tcp;
        tcp_pose_pub_->publish(tcp_msg);
    }

    // TCP wrench
    if (ft.size() == 6) {
        geometry_msgs::msg::WrenchStamped w;
        w.header.stamp = node_->now();
        w.header.frame_id = "tool0";
        w.wrench.force.x  = ft[0];
        w.wrench.force.y  = ft[1];
        w.wrench.force.z  = ft[2];
        w.wrench.torque.x = ft[3];
        w.wrench.torque.y = ft[4];
        w.wrench.torque.z = ft[5];
        tcp_force_pub_->publish(w);
    }

    // Moving status
    std_msgs::msg::Bool m;
    m.data = hw_->isMoving();
    moving_status_pub_->publish(m);
}

// ===================================================================
// Safety check (100Hz)
// ===================================================================
void URRobotManager::safetyCheckCallback()
{
    if (!safety_check_active_) return;

    // Publish status (even when disconnected)
    std_msgs::msg::String status;
    status.data = hw_->isConnected() ? "connected" : "disconnected";
    if (hw_->isMoving())           status.data += ":moving";
    if (hw_->isServoActive())      status.data += ":servo";
    if (hw_->isServoModeActive())  status.data += ":servo_mode";
    if (hw_->isFreedrive())        status.data += ":freedrive";
    robot_status_pub_->publish(status);

    if (!hw_->isConnected()) return;

    // Force limit
    double fmag = 0.0;
    if (hw_->checkForceLimit(&fmag)) {
        RCLCPP_ERROR(node_->get_logger(),
                     "SAFETY: Force %.1fN exceeds limit, stopping!", fmag);
        hw_->stop();
    }

    // Joint limits
    if (!hw_->checkJointLimits()) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(), *node_->get_clock(), 1000,
                             "SAFETY: Joint limit reached, stopping!");
        hw_->stop();
    }
}

// ===================================================================
// Command callbacks
// ===================================================================
void URRobotManager::speedScaleCallback(
    const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (!msg->data.empty()) hw_->setSpeedScale(msg->data[0]);
}

void URRobotManager::cmdMoveJCallback(
    const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (msg->data.size() != 6) {
        RCLCPP_WARN(node_->get_logger(),
                    "/cmd/move_j: need 6 values, got %zu", msg->data.size());
        return;
    }
    std::vector<double> target(msg->data.begin(), msg->data.end());
    double speed = std::min(hw_->speedScale(), hw_->motionLimits().max_joint_speed);
    RCLCPP_INFO(node_->get_logger(), "/cmd/move_j received");
    hw_->moveJ(target, speed, hw_->motionLimits().max_joint_accel, /*async=*/true);
}

void URRobotManager::cmdCustomMoveLCallback(
    const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (msg->data.size() != 6) {
        RCLCPP_WARN(node_->get_logger(),
                    "/cmd/custom_move_l: need 6 values, got %zu", msg->data.size());
        return;
    }
    std::vector<double> target(msg->data.begin(), msg->data.end());
    double speed = std::min(hw_->speedScale(), hw_->motionLimits().max_joint_speed);
    RCLCPP_INFO(node_->get_logger(), "/cmd/custom_move_l received");
    hw_->customMoveL(target, speed, hw_->motionLimits().max_joint_accel);
}

void URRobotManager::cmdHomeCallback(const std_msgs::msg::Bool::SharedPtr)
{
    RCLCPP_INFO(node_->get_logger(), "/cmd/home received");
    std::vector<double> home = {0.0, -1.5708, 0.0, -1.5708, 0.0, 0.0};
    double speed = std::min(hw_->speedScale(), hw_->motionLimits().max_joint_speed);
    hw_->moveJ(home, speed, hw_->motionLimits().max_joint_accel);
}

void URRobotManager::cmdStopCallback(const std_msgs::msg::Bool::SharedPtr)
{
    RCLCPP_WARN(node_->get_logger(), "/cmd/stop received — EMERGENCY STOP");
    if (hw_->isFreedrive()) hw_->stopFreedrive();
    hw_->emergencyStop();
}

void URRobotManager::cmdFreedriveCallback(const std_msgs::msg::Bool::SharedPtr msg)
{
    if (msg->data) hw_->startFreedrive();
    else           hw_->stopFreedrive();
}

void URRobotManager::cmdReconnectCallback(const std_msgs::msg::Bool::SharedPtr)
{
    RCLCPP_INFO(node_->get_logger(), "/cmd/reconnect received");
    hw_->reconnectControl();
}

void URRobotManager::cmdServoTwistCallback(
    const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
    if (msg->data.size() != 6) return;
    Eigen::Matrix<double,6,1> twist;
    for (int i = 0; i < 6; ++i) twist(i) = msg->data[i];
    hw_->setServoTwist(twist);
}

void URRobotManager::cmdServoEnableCallback(const std_msgs::msg::Bool::SharedPtr msg)
{
    if (msg->data) hw_->startServoThread();
    else           hw_->stopServoThread();
}

} // namespace urRobotManager
