#pragma once

/**
 * @file robot_types.h
 * @brief Core types and configurations for UR5e robot control.
 */

#include <string>
#include <vector>
#include <cstdint>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace urRobotManager {

// ============================================================================
// Configuration structs
// ============================================================================

struct SafetyConfig {
    std::vector<double> joint_limits_upper;
    std::vector<double> joint_limits_lower;
    double speed_scaling = 1.0;
    double linear_speed_limit = 0.25;
    double angular_speed_limit = 1.05;
};

struct MovementConfig {
    double linear_speed = 0.25;
    double linear_accel = 1.2;
    double angular_speed = 1.05;
    double angular_accel = 1.4;
    double force_mode_damping = 0.005;
    double force_mode_gain_scaling = 1.0;
    std::vector<double> force_mode_limits = {150, 150, 150, 10, 10, 10};
    double min_payload = 0.0;
    double max_payload = 5.0;
};

struct RTDEConfig {
    double frequency = 500.0;
    uint32_t receive_timeout = 2000;
    bool verbose = false;
};

class RobotConfig {
public:
    RobotConfig(const std::string& robot_name)
        : robot_name_(robot_name) {
        safety.joint_limits_lower = {-2*M_PI, -2*M_PI, -M_PI, -2*M_PI, -2*M_PI, -2*M_PI};
        safety.joint_limits_upper = {2*M_PI, 2*M_PI, M_PI, 2*M_PI, 2*M_PI, 2*M_PI};
    }

    SafetyConfig safety;
    MovementConfig movement;
    RTDEConfig rtde;

    std::string getRobotName() const { return robot_name_; }
    void setRobotName(const std::string& name) { robot_name_ = name; }
    bool validate();

private:
    std::string robot_name_;
    std::vector<std::string> validation_errors_;
};

// ============================================================================
// Gripper positions (encoder values for Faulhaber motor)
// ============================================================================

enum GripperPosition {
    GRP_OPEN = 1000,
    GRP_CLOSE = 0,
    GRP_SUCTION_OPEN = 700,
    GRP_SUCTION_GRIP = 100,
    GRP_SUCTION_CLOSE = 0,
    GRP_FORCEP_OPEN = 850,
    GRP_FORCEP_GRIP = 590,
    GRP_FORCEP_CLOSE = 130,
};

} // namespace urRobotManager
