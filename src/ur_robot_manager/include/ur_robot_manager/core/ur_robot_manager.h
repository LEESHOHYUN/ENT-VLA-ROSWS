#pragma once

/**
 * @file ur_robot_manager.h
 * @brief ROS2 adapter around URHardware.
 *
 * Thin layer that exposes URHardware functionality via ROS2 topics:
 *   publish: /joint_states, /tcp_pose, /tcp_wrench, /robot_status, /is_moving
 *   subscribe: /cmd/move_j, /cmd/custom_move_l, /cmd/home, /cmd/stop,
 *              /cmd/freedrive, /cmd/reconnect, /cmd/servo_twist, /cmd/servo_enable,
 *              /speed_scale
 *
 * All hardware logic lives in URHardware (ROS-free).
 */

#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/wrench_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/bool.hpp>

#include "ur_robot_manager/hardware/ur_hardware.h"

namespace urRobotManager {

class URRobotManager {
public:
    URRobotManager(rclcpp::Node::SharedPtr node, const std::string& robot_ip);
    ~URRobotManager();

    URRobotManager(const URRobotManager&) = delete;
    URRobotManager& operator=(const URRobotManager&) = delete;

    /// Access the hardware layer directly (for action server, tests, etc.)
    URHardware& hw() { return *hw_; }
    const URHardware& hw() const { return *hw_; }

    bool isRobotConnected() const { return hw_->isConnected(); }

private:
    // Timer callbacks
    void publishStateCallback();
    void safetyCheckCallback();

    // Command topic callbacks
    void cmdMoveJCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdCustomMoveLCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdHomeCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdStopCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdFreedriveCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdReconnectCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdServoTwistCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdServoEnableCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void speedScaleCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);

    // Bridge hardware logs into rclcpp logger
    void hwLog(LogLevel lvl, const std::string& msg);

    // ROS
    rclcpp::Node::SharedPtr node_;

    // Callback groups (Reentrant for commands → parallel, MutuallyExclusive for pub/safety)
    rclcpp::CallbackGroup::SharedPtr cmd_cb_group_;
    rclcpp::CallbackGroup::SharedPtr pub_cb_group_;

    // Publishers
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr tcp_pose_pub_;
    rclcpp::Publisher<geometry_msgs::msg::WrenchStamped>::SharedPtr tcp_force_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr robot_status_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr moving_status_pub_;

    // Subscribers
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr speed_scale_sub_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr cmd_movej_sub_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr cmd_custom_movel_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cmd_home_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cmd_stop_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cmd_freedrive_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cmd_reconnect_sub_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr cmd_servo_twist_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cmd_servo_enable_sub_;

    // Timers
    rclcpp::TimerBase::SharedPtr publish_timer_;   // state publishing (100Hz)
    rclcpp::TimerBase::SharedPtr safety_timer_;    // force/joint limit (100Hz)

    // Hardware layer (ROS-free)
    std::unique_ptr<URHardware> hw_;
    bool safety_check_active_ = true;
};

} // namespace urRobotManager
