#pragma once

/**
 * @file robot_trajectory.h
 * @brief Trajectory utilities and coordinate transforms for UR5e.
 */

#include "ur_robot_manager/robot_types.h"

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <vector>
#include <string>

namespace urRobotManager {

std::vector<double> rad2deg(const std::vector<double>& pose);
std::vector<double> deg2rad(const std::vector<double>& pose);

namespace trajectory {

/// Default home pose (joint space, radians)
extern const std::vector<double> HOME_POSE;

/// Transform a vector by a UR-format TCP pose (axis-angle rotation)
std::vector<double> transformVectorWithURPose(
    const std::vector<double>& current_tcp_pose,
    const std::vector<double>& pose_vector);

} // namespace trajectory
} // namespace urRobotManager
