/**
 * @file robot_trajectory.cpp
 * @brief Trajectory utilities and coordinate transforms for UR5e.
 */

#include "ur_robot_manager/utils/robot_trajectory.h"

#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace urRobotManager {

std::vector<double> rad2deg(const std::vector<double>& pose) {
    std::vector<double> result(pose.size());
    for (size_t i = 0; i < pose.size(); i++) {
        result[i] = pose[i] * 180.0 / M_PI;
    }
    return result;
}

std::vector<double> deg2rad(const std::vector<double>& pose) {
    std::vector<double> result(pose.size());
    for (size_t i = 0; i < pose.size(); i++) {
        result[i] = pose[i] * M_PI / 180.0;
    }
    return result;
}

bool RobotConfig::validate() {
    bool isValid = true;
    validation_errors_.clear();
    if (safety.joint_limits_upper.size() != 6 ||
        safety.joint_limits_lower.size() != 6) {
        validation_errors_.push_back("Joint limits must have 6 elements");
        isValid = false;
    }
    if (safety.speed_scaling < 0.0 || safety.speed_scaling > 1.0) {
        validation_errors_.push_back("Speed scaling must be 0.0 - 1.0");
        isValid = false;
    }
    if (movement.max_payload <= movement.min_payload) {
        validation_errors_.push_back("max_payload must exceed min_payload");
        isValid = false;
    }
    if (rtde.frequency <= 0.0 || rtde.frequency > 500.0) {
        validation_errors_.push_back("RTDE frequency must be 0 - 500 Hz");
        isValid = false;
    }
    return isValid;
}

namespace trajectory {

// Default home: upright with elbow bent
const std::vector<double> HOME_POSE = {0.0, -1.5708, 0.0, -1.5708, 0.0, 0.0};

static Eigen::Isometry3d makeIsometryFromURPose(const std::vector<double>& ur_pose)
{
    double x = ur_pose[0], y = ur_pose[1], z = ur_pose[2];
    double rx = ur_pose[3], ry = ur_pose[4], rz = ur_pose[5];

    double theta = std::sqrt(rx*rx + ry*ry + rz*rz);
    Eigen::Matrix3d rot = Eigen::Matrix3d::Identity();
    if (theta > 1e-16) {
        Eigen::Vector3d axis(rx / theta, ry / theta, rz / theta);
        rot = Eigen::AngleAxisd(theta, axis).toRotationMatrix();
    }

    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.linear() = rot;
    T.translation() = Eigen::Vector3d(x, y, z);
    return T;
}

std::vector<double> transformVectorWithURPose(
    const std::vector<double>& current_tcp_pose,
    const std::vector<double>& pose_vector)
{
    Eigen::Isometry3d T = makeIsometryFromURPose(current_tcp_pose);
    Eigen::Vector3d p_in(pose_vector[0], pose_vector[1], pose_vector[2]);
    Eigen::Vector3d p_out = T.rotation() * p_in;
    return { p_out.x(), p_out.y(), p_out.z() };
}

} // namespace trajectory
} // namespace urRobotManager
