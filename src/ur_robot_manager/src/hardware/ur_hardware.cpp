/**
 * @file ur_hardware.cpp
 * @brief Headless UR5e hardware layer implementation.
 *
 * Owns ur_rtde interfaces, kinematics, servo thread.
 * No ROS dependencies.
 */

#include "ur_robot_manager/hardware/ur_hardware.h"

#include <Eigen/Dense>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stdexcept>

namespace urRobotManager {

using std::chrono::steady_clock;

// ===================================================================
// Constructor / Destructor
// ===================================================================
URHardware::URHardware(const std::string& robot_ip, LogCallback log)
    : log_cb_(std::move(log)),
      robot_ip_(robot_ip)
{
    kinematics_ = std::make_shared<URKinematics>();
    this->log(LogLevel::Info, "URHardware: Initializing for %s", robot_ip_.c_str());
    connect();
}

URHardware::~URHardware()
{
    this->log(LogLevel::Info, "URHardware: Shutting down");
    stopServoThread();
    stop();
    disconnect();
}

// ===================================================================
// Logging
// ===================================================================
void URHardware::log(LogLevel lvl, const char* fmt, ...) const
{
    char buf[512];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    if (log_cb_) {
        log_cb_(lvl, buf);
        return;
    }
    const char* tag = "INFO";
    switch (lvl) {
        case LogLevel::Debug: tag = "DEBUG"; break;
        case LogLevel::Info:  tag = "INFO";  break;
        case LogLevel::Warn:  tag = "WARN";  break;
        case LogLevel::Error: tag = "ERROR"; break;
    }
    std::cerr << "[URHardware][" << tag << "] " << buf << std::endl;
}

// ===================================================================
// Connection
// ===================================================================
void URHardware::connect()
{
#ifndef SIM_MODE
    try {
        log(LogLevel::Info, "Connecting to robot at %s", robot_ip_.c_str());
        rtde_control_ = std::make_shared<ur_rtde::RTDEControlInterface>(robot_ip_);
        rtde_receive_ = std::make_shared<ur_rtde::RTDEReceiveInterface>(robot_ip_);
        rtde_io_ = std::make_shared<ur_rtde::RTDEIOInterface>(robot_ip_);
        connected_ = true;
        log(LogLevel::Info, "Connected to robot at %s", robot_ip_.c_str());
    } catch (const std::exception& e) {
        log(LogLevel::Error, "Failed to connect to robot at %s: %s",
            robot_ip_.c_str(), e.what());
        rtde_control_.reset();
        rtde_receive_.reset();
        rtde_io_.reset();
        connected_ = false;
        log(LogLevel::Warn,
            "Running without robot connection. Check: 1) Robot power on  "
            "2) Remote Control mode on pendant  3) IP reachable (ping %s)",
            robot_ip_.c_str());
    }
#else
    log(LogLevel::Warn, "SIM_MODE: Skipping real robot connection");
    connected_ = true;
#endif
}

void URHardware::disconnect()
{
#ifndef SIM_MODE
    try {
        if (rtde_control_) {
            rtde_control_->stopScript();
            rtde_control_->disconnect();
        }
    } catch (const std::exception& e) {
        log(LogLevel::Error, "Error disconnecting: %s", e.what());
    }
#endif
    connected_ = false;
}

void URHardware::reconnectControl()
{
#ifndef SIM_MODE
    try {
        log(LogLevel::Info, "Reconnecting control interface...");
        rtde_control_->reconnect();
        log(LogLevel::Info, "Control interface reconnected");
    } catch (const std::exception& e) {
        log(LogLevel::Warn, "Reconnect failed, creating new interface: %s", e.what());
        try {
            rtde_control_ = std::make_shared<ur_rtde::RTDEControlInterface>(robot_ip_);
            log(LogLevel::Info, "New control interface created");
        } catch (const std::exception& e2) {
            log(LogLevel::Error, "Failed to recreate control interface: %s", e2.what());
            connected_ = false;
        }
    }
#endif
}

// ===================================================================
// State queries
// ===================================================================
std::vector<double> URHardware::getJointPositions()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (connected_ && rtde_receive_) {
        current_joint_positions_ = rtde_receive_->getActualQ();
    }
#endif
    return current_joint_positions_;
}

std::vector<double> URHardware::getJointVelocities()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (connected_ && rtde_receive_) {
        current_joint_velocities_ = rtde_receive_->getActualQd();
    }
#endif
    return current_joint_velocities_;
}

std::vector<double> URHardware::getTCPPose()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (connected_ && rtde_receive_) {
        current_tcp_pose_ = rtde_receive_->getActualTCPPose();
    }
#endif
    return current_tcp_pose_;
}

std::vector<double> URHardware::getTCPForce()
{
    std::lock_guard<std::mutex> lock(state_mutex_);
#ifndef SIM_MODE
    if (connected_ && rtde_receive_) {
        current_tcp_force_ = rtde_receive_->getActualTCPForce();
    }
#endif
    return current_tcp_force_;
}

// ===================================================================
// Motion commands
// ===================================================================
bool URHardware::moveJ(const std::vector<double>& joint_target,
                        double speed, double acceleration, bool async)
{
    if (!connected_) {
        log(LogLevel::Error, "moveJ: Robot not connected");
        return false;
    }
    if (joint_target.size() != 6) {
        log(LogLevel::Error, "moveJ: Invalid target size");
        return false;
    }

    double s = std::min(speed * speed_scale_, motion_limits_.max_joint_speed);
    double a = std::min(acceleration, motion_limits_.max_joint_accel);

    log(LogLevel::Info,
        "moveJ: [%.3f, %.3f, %.3f, %.3f, %.3f, %.3f] speed=%.2f",
        joint_target[0], joint_target[1], joint_target[2],
        joint_target[3], joint_target[4], joint_target[5], s);

    is_moving_ = true;

#ifndef SIM_MODE
    try {
        rtde_control_->moveJ(joint_target, s, a, async);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "moveJ failed: %s", e.what());
        is_moving_ = false;
        return false;
    }
#else
    if (!async) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_joint_positions_ = joint_target;
    }
#endif

    if (!async) is_moving_ = false;
    return true;
}

bool URHardware::moveL(const std::vector<double>& pose_target,
                        double speed, double acceleration, bool async)
{
    if (!connected_) {
        log(LogLevel::Error, "moveL: Robot not connected");
        return false;
    }
    if (pose_target.size() != 6) {
        log(LogLevel::Error, "moveL: Invalid target size");
        return false;
    }

    double s = std::min(speed * speed_scale_, motion_limits_.max_linear_speed);
    double a = std::min(acceleration, motion_limits_.max_linear_accel);

    log(LogLevel::Info,
        "moveL: [%.4f, %.4f, %.4f, %.4f, %.4f, %.4f] speed=%.3f",
        pose_target[0], pose_target[1], pose_target[2],
        pose_target[3], pose_target[4], pose_target[5], s);

    is_moving_ = true;

#ifndef SIM_MODE
    try {
        rtde_control_->moveL(pose_target, s, a, async);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "moveL failed: %s", e.what());
        is_moving_ = false;
        return false;
    }
#else
    if (!async) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_tcp_pose_ = pose_target;
    }
#endif

    if (!async) is_moving_ = false;
    return true;
}

bool URHardware::speedJ(const std::vector<double>& joint_speeds,
                         double acceleration, double time)
{
    if (!connected_) return false;
    if (joint_speeds.size() != 6) return false;

    std::vector<double> clamped(6);
    for (int i = 0; i < 6; ++i) {
        clamped[i] = std::clamp(joint_speeds[i] * speed_scale_,
                                -motion_limits_.max_joint_speed,
                                 motion_limits_.max_joint_speed);
    }

#ifndef SIM_MODE
    try {
        rtde_control_->speedJ(clamped, acceleration, time);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "speedJ failed: %s", e.what());
        return false;
    }
#endif
    return true;
}

bool URHardware::speedL(const std::vector<double>& tcp_speeds,
                         double acceleration, double time)
{
    if (!connected_) return false;
    if (tcp_speeds.size() != 6) return false;

    std::vector<double> clamped(6);
    for (int i = 0; i < 3; ++i) {
        clamped[i] = std::clamp(tcp_speeds[i] * speed_scale_,
                                -motion_limits_.max_linear_speed,
                                 motion_limits_.max_linear_speed);
    }
    for (int i = 3; i < 6; ++i) {
        clamped[i] = std::clamp(tcp_speeds[i] * speed_scale_,
                                -motion_limits_.max_angular_speed,
                                 motion_limits_.max_angular_speed);
    }

#ifndef SIM_MODE
    try {
        rtde_control_->speedL(clamped, acceleration, time);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "speedL failed: %s", e.what());
        return false;
    }
#endif
    return true;
}

bool URHardware::customMoveL(const std::vector<double>& tcp_target,
                              double speed, double acceleration)
{
    if (!connected_) {
        log(LogLevel::Error, "customMoveL: Robot not connected");
        return false;
    }
    if (tcp_target.size() != 6) {
        log(LogLevel::Error, "customMoveL: Invalid target size");
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
        }
    }
#endif

    // (1) Build TCP target
    PoseAA target;
    target.p = Eigen::Vector3d(tcp_target[0], tcp_target[1], tcp_target[2]);
    target.rvec = Eigen::Vector3d(tcp_target[3], tcp_target[4], tcp_target[5]);
    Eigen::Matrix4d T_tcp = URKinematics::poseToT(target);

    // (2) Current joint state
    auto q_now = getJointPositions();
    Eigen::Matrix<double, 6, 1> q_current;
    for (int i = 0; i < 6; ++i) q_current(i) = q_now[i];

    // (3) IK
    Eigen::Matrix<double, 6, 1> q_best;
    int best_idx = -1;
    if (!kinematics_->ikBestForTCPPose(T_tcp, q_current, q_best, &best_idx)) {
        log(LogLevel::Error, "customMoveL: IK failed (no valid solution)");
        return false;
    }

    // (4) FK verification of solution
    Eigen::Matrix4d T_fk = kinematics_->forwardKinematicsTCP(q_best);
    double pos_err = (T_fk.block<3, 1>(0, 3) - target.p).norm() * 1000.0;
    Eigen::Matrix3d R_err = T_fk.block<3,3>(0,0) *
                            URKinematics::rvecToR(target.rvec).transpose();
    double ori_err = URKinematics::RToRvec(R_err).norm() * 180.0 / M_PI;

    log(LogLevel::Info,
        "customMoveL: IK idx=%d, pos_err=%.2fmm, ori_err=%.2fdeg, "
        "target=[%.4f,%.4f,%.4f]",
        best_idx, pos_err, ori_err,
        tcp_target[0], tcp_target[1], tcp_target[2]);

    if (pos_err > 5.0) {
        log(LogLevel::Error,
            "customMoveL: IK position error too large (%.2fmm), aborting",
            pos_err);
        return false;
    }

    std::vector<double> q_cmd(6);
    for (int i = 0; i < 6; ++i) q_cmd[i] = q_best(i);

    return moveJ(q_cmd, speed, acceleration);
}

void URHardware::customSpeedL(const Eigen::Matrix<double,6,1>& base_twist,
                               double a, double lookahead)
{
    if (!connected_) return;

    auto q_now = getJointPositions();
    Eigen::Matrix<double,6,1> q;
    for (int i = 0; i < 6; ++i) q(i) = q_now[i];

    Eigen::Matrix<double,6,6> J = kinematics_->geometricJacobianTCP(q);

    // Adaptive lambda based on manipulability
    double w = std::sqrt(std::max(0.0, (J * J.transpose()).determinant()));
    double lambda;
    if (w >= speedl_params_.w_threshold) {
        lambda = speedl_params_.lambda_min;
    } else {
        double t = (speedl_params_.w_threshold - w) / speedl_params_.w_threshold;
        lambda = speedl_params_.lambda_min +
                 t * (speedl_params_.lambda_max - speedl_params_.lambda_min);
    }

    Eigen::Matrix<double,6,6> JJt = J * J.transpose();
    Eigen::Matrix<double,6,6> A = JJt + (lambda * lambda) *
                                   Eigen::Matrix<double,6,6>::Identity();

    // β normalization
    Eigen::Matrix<double,6,1> v0 = base_twist;
    Eigen::Matrix<double,6,1> vA0 = A.ldlt().solve(v0);
    Eigen::Matrix<double,6,1> qdot0 = J.transpose() * vA0;
    Eigen::Matrix<double,6,1> v_tilde = J * qdot0;

    const double v_ref_lin = v0.head<3>().norm();
    const double v_til_lin = v_tilde.head<3>().norm();

    double beta = 1.0;
    if (v_ref_lin > speedl_params_.eps_norm) {
        beta = v_ref_lin / std::max(v_til_lin, speedl_params_.eps_norm);
        beta = std::clamp(beta, speedl_params_.beta_min, speedl_params_.beta_max);
    }

    Eigen::Matrix<double,6,1> v_cmd = v0;
    v_cmd.head<3>() *= beta;
    v_cmd.tail<3>() *= beta;

    Eigen::Matrix<double,6,1> vA = A.ldlt().solve(v_cmd);
    Eigen::Matrix<double,6,1> qdot = J.transpose() * vA;

    double max_abs_qdot = qdot.cwiseAbs().maxCoeff();
    if (max_abs_qdot > speedl_params_.qdot_lim) {
        qdot *= (speedl_params_.qdot_lim / max_abs_qdot);
    }

    std::vector<double> qd(6);
    for (int i = 0; i < 6; ++i) qd[i] = qdot(i);

#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        rtde_control_->speedJ(qd, a, lookahead);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "customSpeedL failed: %s", e.what());
    }
#endif
}

bool URHardware::movePath(const std::vector<std::vector<double>>& waypoints,
                           double speed, double acceleration,
                           double blend_radius)
{
    if (!connected_) return false;
    if (waypoints.empty()) return false;

    log(LogLevel::Info, "movePath: %zu waypoints, blend=%.4f",
        waypoints.size(), blend_radius);

    is_moving_ = true;

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
        path.back()[8] = 0.0;
        rtde_control_->moveL(path);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "movePath failed: %s", e.what());
        is_moving_ = false;
        return false;
    }
#else
    for (const auto& wp : waypoints) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::lock_guard<std::mutex> lock(state_mutex_);
        current_tcp_pose_ = wp;
    }
#endif

    is_moving_ = false;
    return true;
}

// ===================================================================
// Stop
// ===================================================================
void URHardware::stop()
{
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
        }
    } catch (const std::exception& e) {
        log(LogLevel::Error, "stop failed: %s", e.what());
    }
#endif

    log(LogLevel::Info, "Robot stopped");
}

void URHardware::emergencyStop()
{
    log(LogLevel::Error, "EMERGENCY STOP triggered");

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
        log(LogLevel::Error, "emergencyStop failed: %s", e.what());
    }
#endif
}

// ===================================================================
// Servo mode
// ===================================================================
void URHardware::servoSpeedL(const Eigen::Matrix<double,6,1>& twist_base)
{
    if (!connected_) return;

    auto q_vec = getJointPositions();
    Eigen::Matrix<double,6,1> q_now;
    for (int i = 0; i < 6; ++i) q_now(i) = q_vec[i];

    if (!servo_mode_active_) {
        q_ref_ = q_now;
        servo_mode_active_ = true;
        last_servo_time_ = steady_clock::now();
        log(LogLevel::Info, "Servo mode activated");
    }

    auto now = steady_clock::now();
    double dt_actual = std::chrono::duration<double>(now - last_servo_time_).count();
    dt_actual = std::clamp(dt_actual, 0.001, 0.1);
    last_servo_time_ = now;

    Eigen::Matrix<double,6,6> J = kinematics_->geometricJacobianTCP(q_now);
    Eigen::JacobiSVD<Eigen::Matrix<double,6,6>> svd(
        J, Eigen::ComputeFullU | Eigen::ComputeFullV);
    const auto& U = svd.matrixU();
    const auto& V = svd.matrixV();
    const auto& S = svd.singularValues();

    Eigen::Matrix<double,6,1> S_inv;
    for (int i = 0; i < 6; ++i) {
        if (S(i) > servo_params_.sigma_min) {
            S_inv(i) = 1.0 / S(i);
        } else {
            double ratio = S(i) / servo_params_.sigma_min;
            double lam = servo_params_.lambda_max * (1.0 - ratio);
            S_inv(i) = S(i) / (S(i) * S(i) + lam * lam);
        }
    }

    Eigen::Matrix<double,6,1> qdot = V * S_inv.asDiagonal() * U.transpose() * twist_base;

    double max_val = qdot.cwiseAbs().maxCoeff();
    if (max_val > servo_params_.qdot_max) {
        qdot *= (servo_params_.qdot_max / max_val);
    }

    q_ref_ += qdot * dt_actual;

    for (int i = 0; i < 6; ++i) {
        q_ref_(i) = std::clamp(q_ref_(i),
                               safety_params_.joint_limits_lower[i] + 0.05,
                               safety_params_.joint_limits_upper[i] - 0.05);
    }

    double ref_error = (q_ref_ - q_now).norm();
    if (ref_error > servo_params_.ref_error_max) {
        log(LogLevel::Warn, "Servo ref drift: %.3f rad, resetting", ref_error);
        q_ref_ = q_now;
    }

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
        log(LogLevel::Error, "servoSpeedL failed: %s", e.what());
    }
#else
    {
        std::lock_guard<std::mutex> lock(state_mutex_);
        for (int i = 0; i < 6; ++i) current_joint_positions_[i] = q_cmd[i];
    }
#endif
    servo_active_ = true;
}

void URHardware::servoJ6Only(double wz_tcp)
{
    if (!connected_) return;

    auto q_vec = getJointPositions();
    Eigen::Matrix<double,6,1> q_now;
    for (int i = 0; i < 6; ++i) q_now(i) = q_vec[i];

    if (!servo_mode_active_) {
        q_ref_ = q_now;
        servo_mode_active_ = true;
        last_servo_time_ = steady_clock::now();
    }

    auto now = steady_clock::now();
    double dt_actual = std::chrono::duration<double>(now - last_servo_time_).count();
    dt_actual = std::clamp(dt_actual, 0.001, 0.1);
    last_servo_time_ = now;

    for (int i = 0; i < 5; ++i) q_ref_(i) = q_now(i);
    double j6_vel = std::clamp(wz_tcp, -servo_params_.qdot_max, servo_params_.qdot_max);
    q_ref_(5) += j6_vel * dt_actual;
    q_ref_(5) = std::clamp(q_ref_(5),
                           safety_params_.joint_limits_lower[5] + 0.05,
                           safety_params_.joint_limits_upper[5] - 0.05);

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
        log(LogLevel::Error, "servoJ6Only failed: %s", e.what());
    }
#endif
    servo_active_ = true;
}

void URHardware::servoStop(double deceleration)
{
    servo_active_ = false;
    servo_mode_active_ = false;
#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        if (rtde_control_) rtde_control_->servoStop(deceleration);
    } catch (const std::exception& e) {
        log(LogLevel::Error, "servoStop failed: %s", e.what());
    }
#endif
}

// ===================================================================
// Servo thread
// ===================================================================
void URHardware::startServoThread()
{
    if (servo_thread_running_) {
        log(LogLevel::Warn, "Servo thread already running");
        return;
    }

    servo_mode_active_ = false;
    servo_thread_running_ = true;
    servo_thread_ = std::thread(&URHardware::servoThreadLoop, this);

    log(LogLevel::Info, "Servo thread started (%.0fHz)", 1.0 / servo_params_.dt);
}

void URHardware::stopServoThread()
{
    servo_thread_running_ = false;
    if (servo_thread_.joinable()) servo_thread_.join();
    servoStop();
    servo_mode_active_ = false;
    log(LogLevel::Info, "Servo thread stopped");
}

void URHardware::setServoTwist(const Eigen::Matrix<double,6,1>& twist)
{
    std::lock_guard<std::mutex> lock(servo_twist_mutex_);
    servo_twist_cmd_ = twist;
}

void URHardware::servoThreadLoop()
{
    log(LogLevel::Info, "Servo loop running at %.0fHz", 1.0 / servo_params_.dt);

    while (servo_thread_running_) {
#ifndef SIM_MODE
        if (!connected_ || !rtde_control_) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        auto t_start = rtde_control_->initPeriod();

        Eigen::Matrix<double,6,1> twist;
        {
            std::lock_guard<std::mutex> lock(servo_twist_mutex_);
            twist = servo_twist_cmd_;
        }

        double twist_norm = twist.norm();
        if (twist_norm > 1e-6) {
            servoSpeedL(twist);
        } else if (servo_mode_active_) {
            servoSpeedL(Eigen::Matrix<double,6,1>::Zero());
        }

        rtde_control_->waitPeriod(t_start);
#else
        std::this_thread::sleep_for(
            std::chrono::microseconds(static_cast<int>(servo_params_.dt * 1e6)));
#endif
    }

    log(LogLevel::Info, "Servo loop exited");
}

// ===================================================================
// Freedrive
// ===================================================================
void URHardware::startFreedrive()
{
    if (freedrive_active_) return;
    if (!connected_) {
        log(LogLevel::Warn, "Freedrive: robot not connected");
        return;
    }

#ifndef SIM_MODE
    try {
        rtde_control_->freedriveMode();
        freedrive_active_ = true;
        log(LogLevel::Info, "Freedrive ON — kinesthetic teaching enabled");
    } catch (const std::exception& e) {
        log(LogLevel::Error, "Freedrive start failed: %s", e.what());
    }
#else
    freedrive_active_ = true;
    log(LogLevel::Info, "Freedrive ON (SIM_MODE)");
#endif
}

void URHardware::stopFreedrive()
{
    if (!freedrive_active_) return;

#ifndef SIM_MODE
    try {
        rtde_control_->endFreedriveMode();
        freedrive_active_ = false;
        log(LogLevel::Info, "Freedrive OFF");
    } catch (const std::exception& e) {
        log(LogLevel::Error, "Freedrive stop failed: %s", e.what());
    }
    reconnectControl();
#else
    freedrive_active_ = false;
    log(LogLevel::Info, "Freedrive OFF (SIM_MODE)");
#endif
}

// ===================================================================
// Gripper / Tool
// ===================================================================
void URHardware::gripperOpen()
{
    log(LogLevel::Info, "Gripper: OPEN");
    // TODO: delegated to gripper_interfaces service
}

void URHardware::gripperClose()
{
    log(LogLevel::Info, "Gripper: CLOSE");
    // TODO: delegated to gripper_interfaces service
}

void URHardware::setSuctionState(bool on)
{
    log(LogLevel::Info, "Suction: %s", on ? "ON" : "OFF");
#ifndef SIM_MODE
    if (rtde_io_) rtde_io_->setStandardDigitalOut(0, on);
#endif
}

void URHardware::setToolTCP(const std::vector<double>& tcp_pose)
{
    if (tcp_pose.size() != 6) return;
    Eigen::Vector3d t_tcp(tcp_pose[0], tcp_pose[1], tcp_pose[2]);
    Eigen::Vector3d rvec_tcp(tcp_pose[3], tcp_pose[4], tcp_pose[5]);
    kinematics_->setToolTCP(t_tcp, rvec_tcp);
    log(LogLevel::Info, "Tool TCP set: [%.4f, %.4f, %.4f, %.4f, %.4f, %.4f]",
        tcp_pose[0], tcp_pose[1], tcp_pose[2],
        tcp_pose[3], tcp_pose[4], tcp_pose[5]);

#ifndef SIM_MODE
    if (rtde_control_) rtde_control_->setTcp(tcp_pose);
#endif
}

bool URHardware::setPayload(double mass, const std::vector<double>& cog)
{
#ifndef SIM_MODE
    std::lock_guard<std::mutex> lock(rtde_mutex_);
    try {
        if (rtde_control_) {
            rtde_control_->setPayload(mass, cog);
            log(LogLevel::Info, "Payload set: mass=%.2f kg", mass);
            return true;
        }
    } catch (const std::exception& e) {
        log(LogLevel::Error, "setPayload failed: %s", e.what());
    }
#else
    (void)mass; (void)cog;
#endif
    return false;
}

// ===================================================================
// Safety
// ===================================================================
bool URHardware::checkJointLimits()
{
    auto q = getJointPositions();
    if (q.size() != 6) return false;

    for (int i = 0; i < 6; ++i) {
        double dist_upper = safety_params_.joint_limits_upper[i] - q[i];
        double dist_lower = q[i] - safety_params_.joint_limits_lower[i];

        if (dist_upper < safety_params_.joint_limit_threshold ||
            dist_lower < safety_params_.joint_limit_threshold) {
            log(LogLevel::Warn,
                "Joint %d approaching limit: %.3f rad (upper=%.3f, lower=%.3f)",
                i, q[i], safety_params_.joint_limits_upper[i],
                safety_params_.joint_limits_lower[i]);
            return false;
        }
    }
    return true;
}

bool URHardware::checkForceLimit(double* out_magnitude)
{
    auto force = getTCPForce();
    if (force.size() != 6) {
        if (out_magnitude) *out_magnitude = 0.0;
        return false;
    }
    double mag = std::sqrt(force[0]*force[0] + force[1]*force[1] +
                            force[2]*force[2]);
    if (out_magnitude) *out_magnitude = mag;
    return mag > safety_params_.force_limit;
}

// ===================================================================
// Speed scale
// ===================================================================
void URHardware::setSpeedScale(double s)
{
    speed_scale_ = std::clamp(s, 0.01, 1.0);
    log(LogLevel::Info, "Speed scale set to %.2f", speed_scale_);
}

// ===================================================================
// Wait for move
// ===================================================================
bool URHardware::waitForMove(double timeout_sec)
{
    auto start = steady_clock::now();
    while (is_moving_) {
        double elapsed = std::chrono::duration<double>(
            steady_clock::now() - start).count();
        if (elapsed > timeout_sec) {
            log(LogLevel::Warn, "waitForMove timed out after %.1f sec", elapsed);
            return false;
        }

#ifndef SIM_MODE
        if (rtde_receive_) {
            auto mode = rtde_receive_->getRobotMode();
            if (mode == 7 && !rtde_control_->isProgramRunning()) {
                is_moving_ = false;
                break;
            }
        }
#endif
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    return true;
}

} // namespace urRobotManager
