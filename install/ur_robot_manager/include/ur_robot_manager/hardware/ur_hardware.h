#pragma once

/**
 * @file ur_hardware.h
 * @brief Headless UR5e hardware layer — NO ROS dependencies.
 *
 * Pure C++ + ur_rtde + Eigen + URKinematics only.
 * Can be reused across frameworks (ROS1, LCM, embedded, unit tests).
 * The ROS adapter is URRobotManager which composes an instance of URHardware.
 *
 * Logging is injected via LogCallback; defaults to std::cerr.
 */

#include <atomic>
#include <chrono>
#include <cstdarg>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <Eigen/Dense>
#include "ur_robot_manager/utils/ur_kinematics.h"

#ifndef SIM_MODE
#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>
#include <ur_rtde/rtde_io_interface.h>
#endif

namespace urRobotManager {

// ============================================================
// Logging
// ============================================================
enum class LogLevel { Debug = 0, Info = 1, Warn = 2, Error = 3 };
using LogCallback = std::function<void(LogLevel, const std::string&)>;

// ============================================================
// Parameter structs
// ============================================================
struct ServoParams {
    double dt           = 0.002;    // servo period [s] (500Hz)
    double lookahead    = 0.1;      // servoJ lookahead [0.03-0.2]
    double gain         = 300.0;    // servoJ gain [100-2000]
    double sigma_min    = 0.005;    // SVD min singular value for damping
    double lambda_max   = 0.1;      // SVD max damping
    double qdot_max     = 2.5;      // max joint velocity [rad/s]
    double ref_error_max = 0.5;     // q_ref drift reset threshold [rad]
};

struct SpeedLParams {
    double lambda_max   = 0.018;
    double lambda_min   = 0.002;
    double w_threshold  = 0.009;
    double qdot_lim     = 2.5;
    double beta_min     = 0.5;
    double beta_max     = 1.5;
    double eps_norm     = 1e-6;
};

struct SafetyParams {
    double force_limit      = 30.0;
    double joint_limit_threshold = 0.1;
    std::vector<double> joint_limits_upper = { 6.28,  6.28,  3.14,  6.28,  6.28,  6.28};
    std::vector<double> joint_limits_lower = {-6.28, -6.28, -3.14, -6.28, -6.28, -6.28};
};

struct MotionLimits {
    double max_linear_speed   = 0.25;
    double max_angular_speed  = 0.5;
    double max_joint_speed    = 1.0;
    double max_joint_accel    = 1.4;
    double max_linear_accel   = 1.2;
};

// ============================================================
// URHardware — headless hardware layer
// ============================================================
class URHardware {
public:
    explicit URHardware(const std::string& robot_ip, LogCallback log = nullptr);
    ~URHardware();

    URHardware(const URHardware&) = delete;
    URHardware& operator=(const URHardware&) = delete;

    // -- Connection --
    void connect();
    void disconnect();
    void reconnectControl();
    bool isConnected() const { return connected_; }
    const std::string& ip() const { return robot_ip_; }

    // -- State queries --
    std::vector<double> getJointPositions();
    std::vector<double> getJointVelocities();
    std::vector<double> getTCPPose();
    std::vector<double> getTCPForce();

    // -- Motion commands --
    bool moveJ(const std::vector<double>& joint_target,
               double speed = 0.5, double acceleration = 0.5, bool async = false);
    bool moveL(const std::vector<double>& pose_target,
               double speed = 0.1, double acceleration = 0.5, bool async = false);
    bool speedJ(const std::vector<double>& joint_speeds,
                double acceleration = 1.4, double time = 0.1);
    bool speedL(const std::vector<double>& tcp_speeds,
                double acceleration = 1.2, double time = 0.1);

    /// customMoveL: TCP target → IK8 → best pick → moveJ
    bool customMoveL(const std::vector<double>& tcp_target,
                     double speed = 0.5, double acceleration = 0.5);

    /// customSpeedL: TCP twist → adaptive DLS + β → speedJ
    void customSpeedL(const Eigen::Matrix<double,6,1>& base_twist,
                      double a, double lookahead = 0.06);

    bool movePath(const std::vector<std::vector<double>>& waypoints,
                  double speed = 0.1, double acceleration = 0.5,
                  double blend_radius = 0.005);

    // -- Stop --
    void stop();
    void emergencyStop();

    // -- Servo mode --
    void servoSpeedL(const Eigen::Matrix<double,6,1>& twist_base);
    void servoJ6Only(double wz_tcp);
    void servoStop(double deceleration = 3.2);

    /// Start/stop the dedicated 500Hz servo thread
    void startServoThread();
    void stopServoThread();
    void setServoTwist(const Eigen::Matrix<double,6,1>& twist);
    bool isServoThreadRunning() const { return servo_thread_running_; }

    // -- Freedrive --
    void startFreedrive();
    void stopFreedrive();
    bool isFreedrive() const { return freedrive_active_; }

    // -- Gripper / Tool --
    void gripperOpen();
    void gripperClose();
    void setSuctionState(bool on);
    void setToolTCP(const std::vector<double>& tcp_pose);

    // -- Payload --
    bool setPayload(double mass, const std::vector<double>& cog = {});

    // -- Safety --
    bool checkJointLimits();
    /// Returns true if force magnitude exceeds safety_params_.force_limit.
    /// Caller should decide to stop; does not stop automatically.
    bool checkForceLimit(double* out_magnitude = nullptr);

    // -- Runtime state --
    bool isMoving() const { return is_moving_; }
    bool isServoActive() const { return servo_active_; }
    bool isServoModeActive() const { return servo_mode_active_; }
    void setSpeedScale(double s);
    double speedScale() const { return speed_scale_; }

    // -- Parameters (read-only accessors) --
    const MotionLimits& motionLimits() const { return motion_limits_; }
    const ServoParams& servoParams() const { return servo_params_; }
    const SafetyParams& safetyParams() const { return safety_params_; }

    /// Wait until motion is complete or timeout. Uses wall clock (no ROS).
    bool waitForMove(double timeout_sec = 30.0);

private:
    void servoThreadLoop();

    // Logging helpers (printf-style)
    void log(LogLevel lvl, const char* fmt, ...) const;

    LogCallback log_cb_;

    // ur_rtde
#ifndef SIM_MODE
    std::shared_ptr<ur_rtde::RTDEControlInterface> rtde_control_;
    std::shared_ptr<ur_rtde::RTDEReceiveInterface> rtde_receive_;
    std::shared_ptr<ur_rtde::RTDEIOInterface> rtde_io_;
#endif
    std::mutex rtde_mutex_;

    // Kinematics
    std::shared_ptr<URKinematics> kinematics_;

    // Parameters
    ServoParams servo_params_;
    SpeedLParams speedl_params_;
    SafetyParams safety_params_;
    MotionLimits motion_limits_;

    // Identity / connection
    std::string robot_ip_;
    std::atomic<bool> connected_{false};
    std::atomic<bool> is_moving_{false};
    std::atomic<bool> servo_active_{false};
    std::atomic<bool> servo_mode_active_{false};
    std::atomic<bool> freedrive_active_{false};

    double speed_scale_ = 1.0;

    // Servo control state
    Eigen::Matrix<double,6,1> q_ref_ = Eigen::Matrix<double,6,1>::Zero();
    std::chrono::steady_clock::time_point last_servo_time_;

    // Servo thread
    std::thread servo_thread_;
    std::atomic<bool> servo_thread_running_{false};
    std::mutex servo_twist_mutex_;
    Eigen::Matrix<double,6,1> servo_twist_cmd_ = Eigen::Matrix<double,6,1>::Zero();

    // Cached state
    std::mutex state_mutex_;
    std::vector<double> current_joint_positions_  = std::vector<double>(6, 0.0);
    std::vector<double> current_joint_velocities_ = std::vector<double>(6, 0.0);
    std::vector<double> current_tcp_pose_         = std::vector<double>(6, 0.0);
    std::vector<double> current_tcp_force_        = std::vector<double>(6, 0.0);
};

} // namespace urRobotManager
