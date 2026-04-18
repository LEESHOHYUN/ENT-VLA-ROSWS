#pragma once

/**
 * @file ur_robot_manager.h
 * @brief Single UR5e robot manager via ur_rtde.
 *
 * Provides motion commands, servo mode (SVD-based), singularity handling,
 * gripper integration, safety monitoring, and joint state publishing.
 */

#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <geometry_msgs/msg/wrench_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/bool.hpp>

#include <Eigen/Dense>
#include "ur_robot_manager/utils/ur_kinematics.h"

#ifndef SIM_MODE
#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <ur_rtde/rtde_io_interface.h>
#endif

namespace urRobotManager {

// ============================================================
// Servo parameters (from original catkin_m)
// ============================================================
struct ServoParams {
    double dt           = 0.002;    // #TUNABLE servo period [s] (500Hz)
    double lookahead    = 0.1;      // #TUNABLE servoJ lookahead [0.03-0.2]
    double gain         = 300.0;    // #TUNABLE servoJ gain [100-2000]
    double sigma_min    = 0.005;    // #TUNABLE SVD min singular value for damping
    double lambda_max   = 0.1;     // #TUNABLE SVD max damping
    double qdot_max     = 2.5;     // #TUNABLE max joint velocity [rad/s]
    double ref_error_max = 0.5;    // #TUNABLE q_ref drift reset threshold [rad]
};

// ============================================================
// customSpeedL parameters (from original catkin_m customSpeedL_)
// ============================================================
struct SpeedLParams {
    double lambda_max   = 0.018;    // #TUNABLE singularity max lambda
    double lambda_min   = 0.002;    // #TUNABLE normal min lambda
    double w_threshold  = 0.009;    // #TUNABLE manipulability threshold for lambda ramp
    double qdot_lim     = 2.5;     // #TUNABLE max joint velocity [rad/s]
    double beta_min     = 0.5;     // #TUNABLE TCP speed correction beta lower bound
    double beta_max     = 1.5;     // #TUNABLE TCP speed correction beta upper bound
    double eps_norm     = 1e-6;    // zero-division protection
};

// ============================================================
// Safety parameters
// ============================================================
struct SafetyParams {
    double force_limit      = 30.0;     // #TUNABLE force magnitude stop threshold [N]
    double joint_limit_threshold = 0.1; // #TUNABLE distance to joint limit for stop [rad]
    // #TUNABLE joint limits [rad] — UR5e defaults
    std::vector<double> joint_limits_upper = { 6.28,  6.28,  3.14,  6.28,  6.28,  6.28};
    std::vector<double> joint_limits_lower = {-6.28, -6.28, -3.14, -6.28, -6.28, -6.28};
};

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

    /// customSpeedL: TCP twist → adaptive DLS + β correction → speedJ (joint space)
    void customSpeedL(const Eigen::Matrix<double,6,1>& base_twist,
                      double a, double lookahead = 0.06);

    bool movePath(const std::vector<std::vector<double>>& waypoints,
                  double speed = 0.1, double acceleration = 0.5,
                  double blend_radius = 0.005);

    // -- Stop --
    void stopRobot();
    void emergencyStop();

    // -- Servo mode (SVD-based, from original) --
    /// servoSpeedL: Selective Damping SVD → q_ref_ integration → servoJ
    void servoSpeedL(const Eigen::Matrix<double,6,1>& twist_base);

    /// servoJ6Only: J6-only velocity integration → servoJ
    void servoJ6Only(double wz_tcp);

    void servoStop(double deceleration = 3.2);

    /// Start/stop the dedicated servo control thread (500Hz)
    void startServoThread();
    void stopServoThread();

    /// Update the twist command for the servo thread (thread-safe)
    void setServoTwist(const Eigen::Matrix<double,6,1>& twist);

    // -- Payload --
    bool setPayload(double mass, const std::vector<double>& cog = {});

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

    // -- NOTE: computePostureEnergyAndGrad_numeric --
    // Null-space posture optimization (J4-J5 alignment avoidance).
    // Available in catkin_m original but not ported here.
    // Used with customSpeedL_ for null-space qdot_post = N * (-k_post * PE.grad).
    // Can be added later if null-space control is needed.

private:
    void safetyCheckCallback();
    bool checkJointLimits();
    void publishMovingStatus(bool moving);
    void servoThreadLoop();  // 500Hz servo control loop

    // Command topic callbacks
    void cmdMoveJCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdCustomMoveLCallback(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
    void cmdHomeCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdStopCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void cmdFreedriveCallback(const std_msgs::msg::Bool::SharedPtr msg);
    void reconnectControl();

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
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr cmd_reconnect_sub_;

    // Timers
    rclcpp::TimerBase::SharedPtr safety_timer_;

    // ur_rtde
#ifndef SIM_MODE
    std::shared_ptr<ur_rtde::RTDEControlInterface> rtde_control_;
    std::shared_ptr<ur_rtde::RTDEReceiveInterface> rtde_receive_;
    std::shared_ptr<ur_rtde::RTDEIOInterface> rtde_io_;
#endif
    std::mutex rtde_mutex_;  // protects rtde_control_ calls (not thread-safe)

    // Kinematics
    std::shared_ptr<URKinematics> kinematics_;

    // Parameters
    ServoParams servo_params_;
    SpeedLParams speedl_params_;
    SafetyParams safety_params_;

    // State
    std::string robot_ip_;
    bool robot_connected_;
    std::atomic<bool> is_moving_;
    bool servo_active_;
    bool freedrive_active_;
    bool safety_check_active_;

    double speed_scale_;
    double max_linear_speed_;
    double max_angular_speed_;
    double max_joint_speed_;
    double max_joint_accel_;
    double max_linear_accel_;

    // Servo state (for servoSpeedL / servoJ6Only)
    Eigen::Matrix<double,6,1> q_ref_;
    bool servo_mode_active_ = false;
    std::chrono::steady_clock::time_point last_servo_time_;

    // Servo thread (500Hz dedicated control loop)
    std::thread servo_thread_;
    std::atomic<bool> servo_thread_running_{false};
    std::mutex servo_twist_mutex_;
    Eigen::Matrix<double,6,1> servo_twist_cmd_ = Eigen::Matrix<double,6,1>::Zero();

    // Cached state (protected by state_mutex_)
    std::mutex state_mutex_;
    std::vector<double> current_joint_positions_;
    std::vector<double> current_joint_velocities_;
    std::vector<double> current_tcp_pose_;
    std::vector<double> current_tcp_force_;
};

} // namespace urRobotManager
