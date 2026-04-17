#pragma once

/**
 * @file ur_robot_manager.h
 * @brief Single UR5e robot manager via ur_rtde.
 *
 * Provides motion commands, servo mode, singularity handling,
 * gripper integration, safety monitoring, and joint state publishing.
 */

#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/wrench_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/bool.hpp>

#include "ur_robot_manager/utils/ur_kinematics.h"

#ifndef SIM_MODE
// #include <ur_rtde/rtde_control_interface.h>
// #include <ur_rtde/rtde_receive_interface.h>
// #include <ur_rtde/rtde_io_interface.h>
#endif

namespace urRobotManager {

class URRobotManager {
public:
    URRobotManager(rclcpp::Node::SharedPtr node, const std::string& robot_ip);
    ~URRobotManager();

    URRobotManager(const URRobotManager&) = delete;
    URRobotManager& operator=(const URRobotManager&) = delete;

    // -- Connection --
    void connectToRobot();
    void disconnectFromRobot();
    bool isRobotConnected() const;

    // -- State queries --
    std::vector<double> getJointPositions();
    std::vector<double> getJointVelocities();
    std::vector<double> getTCPPose();
    std::vector<double> getTCPForce();

    // -- Motion commands --
    bool moveJ(const std::vector<double>& joint_target,
               double speed = 0.5, double acceleration = 0.5,
               bool async = false);

    bool moveL(const std::vector<double>& pose_target,
               double speed = 0.1, double acceleration = 0.5,
               bool async = false);

    bool speedJ(const std::vector<double>& joint_speeds,
                double acceleration = 1.4, double time = 0.1);

    bool speedL(const std::vector<double>& tcp_speeds,
                double acceleration = 1.2, double time = 0.1);

    /// customMoveL: TCP target → IK8 → best pick → moveJ (singularity-safe)
    bool customMoveL(const std::vector<double>& tcp_target,
                     double speed = 0.5, double acceleration = 0.5);

    bool customSpeedL(const std::vector<double>& tcp_speeds,
                      double acceleration = 1.2, double time = 0.1);

    bool movePath(const std::vector<std::vector<double>>& waypoints,
                  double speed = 0.1, double acceleration = 0.5,
                  double blend_radius = 0.005);

    // -- Stop --
    void stopRobot();
    void emergencyStop();

    // -- Servo mode --
    bool servoSpeedL(const std::vector<double>& tcp_speeds,
                     double acceleration = 1.2, double time = 0.1);

    bool servoJ6Only(const std::vector<double>& joint_target,
                     double time = 0.002, double lookahead = 0.1,
                     double gain = 300.0);

    void servoStop();

    // -- Singularity handling --
    std::vector<double> computeStandardDLS(
        const std::vector<double>& twist,
        const std::vector<double>& q,
        double damping = 0.01);

    std::vector<double> computeSingularityRobustVelocity(
        const std::vector<double>& desired_twist,
        const std::vector<double>& q);

    // -- Freedrive (Kinesthetic Teaching) --
    void startFreedrive();
    void stopFreedrive();
    bool isFreedrive() const { return freedrive_active_; }

    // -- Gripper / Tool --
    void gripperOpen();
    void gripperClose();
    void setSuctionState(bool on);
    void setToolTCP(const std::vector<double>& tcp_pose);

    // -- Publishing --
    void publishJointState(const std::vector<double>& joint_positions);

    // -- Utilities --
    bool waitForMove(double timeout_sec = 30.0);

private:
    void safetyCheckCallback();
    void publishMovingStatus(bool moving);

    // Command topic callbacks
    void cmdMoveJCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdCustomMoveLCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdHomeCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdStopCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdFreedriveCallback(const std_msgs::msg::Bool::SharedPtr msg);

    // ROS2
    rclcpp::Node::SharedPtr node_;

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

    // Timers
    rclcpp::TimerBase::SharedPtr safety_timer_;

    // ur_rtde
#ifndef SIM_MODE
    // std::shared_ptr<ur_rtde::RTDEControlInterface> rtde_control_;
    // std::shared_ptr<ur_rtde::RTDEReceiveInterface> rtde_receive_;
    // std::shared_ptr<ur_rtde::RTDEIOInterface> rtde_io_;
#endif

    // Kinematics
    std::shared_ptr<URKinematics> kinematics_;

    // State
    std::string robot_ip_;
    bool robot_connected_;
    bool is_moving_;
    bool servo_active_;
    bool freedrive_active_;
    bool safety_check_active_;

    double speed_scale_;
    double max_linear_speed_;
    double max_angular_speed_;
    double max_joint_speed_;
    double max_joint_accel_;
    double max_linear_accel_;
    double servo_lookahead_;
    double servo_gain_;

    std::mutex state_mutex_;
    std::vector<double> current_joint_positions_;
    std::vector<double> current_joint_velocities_;
    std::vector<double> current_tcp_pose_;
    std::vector<double> current_tcp_force_;
};

} // namespace urRobotManager
