/**
 * @file ur_robot_action_server.cpp
 * @brief ROS2 action server for single UR5e robot task execution.
 *
 * Task types (via task_id field):
 *   0: Move to home position
 *   1: Move to Cartesian target (moveL)  — positions[0..5] = [x y z rx ry rz]
 *   2: Move to joint target (moveJ)      — positions[0..5] = 6 joint angles
 *   3: Tool change sequence (gripper open → pickup → close → set TCP)
 *   4: Custom path execution (waypoints)  — positions = flattened 6-DOF waypoints
 *   5: customMoveL (TCP → IK8 → moveJ)  — positions[0..5] = [x y z rx ry rz]
 */

#include "ur_robot_manager/core/ur_robot_action_server.h"
#include "ur_robot_manager/core/ur_robot_manager.h"

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;
using RobotTaskAction = ur_robot_manager_interfaces::action::RobotTask;
using GoalHandleRobotTask = rclcpp_action::ServerGoalHandle<RobotTaskAction>;

namespace urRobotManager {

URRobotActionServer::URRobotActionServer(
    rclcpp::Node::SharedPtr node,
    const std::string& action_name,
    URRobotManager& robot_manager)
    : node_(node),
      action_name_(action_name),
      robot_manager_(robot_manager),
      is_executing_(false)
{
    action_server_ = rclcpp_action::create_server<RobotTaskAction>(
        node_, action_name_,
        std::bind(&URRobotActionServer::handleGoal, this,
                  std::placeholders::_1, std::placeholders::_2),
        std::bind(&URRobotActionServer::handleCancel, this,
                  std::placeholders::_1),
        std::bind(&URRobotActionServer::handleAccepted, this,
                  std::placeholders::_1));

    state_pub_ = node_->create_publisher<std_msgs::msg::String>(
        "/" + action_name_ + "/state", 10);

    RCLCPP_INFO(node_->get_logger(),
                "Action server '%s' ready", action_name_.c_str());
}

rclcpp_action::GoalResponse URRobotActionServer::handleGoal(
    const rclcpp_action::GoalUUID& uuid,
    std::shared_ptr<const RobotTaskAction::Goal> goal)
{
    (void)uuid;
    RCLCPP_INFO(node_->get_logger(),
                "Received goal: task_id=%d, tool_type=%d",
                goal->task_id, goal->tool_type);

    if (is_executing_) {
        RCLCPP_WARN(node_->get_logger(), "Rejecting: already executing");
        return rclcpp_action::GoalResponse::REJECT;
    }
    if (!robot_manager_.isRobotConnected()) {
        RCLCPP_WARN(node_->get_logger(), "Rejecting: robot not connected");
        return rclcpp_action::GoalResponse::REJECT;
    }
    if (goal->task_id < 0 || goal->task_id > 5) {
        RCLCPP_WARN(node_->get_logger(),
                    "Rejecting: invalid task_id %d", goal->task_id);
        return rclcpp_action::GoalResponse::REJECT;
    }

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse URRobotActionServer::handleCancel(
    const std::shared_ptr<GoalHandleRobotTask> goal_handle)
{
    (void)goal_handle;
    RCLCPP_INFO(node_->get_logger(), "Cancel requested, stopping robot");
    robot_manager_.stopRobot();
    return rclcpp_action::CancelResponse::ACCEPT;
}

void URRobotActionServer::handleAccepted(
    const std::shared_ptr<GoalHandleRobotTask> goal_handle)
{
    std::thread([this, goal_handle]() {
        executeTask(goal_handle);
    }).detach();
}

void URRobotActionServer::executeTask(
    const std::shared_ptr<GoalHandleRobotTask> goal_handle)
{
    is_executing_ = true;
    auto goal = goal_handle->get_goal();
    auto result = std::make_shared<RobotTaskAction::Result>();
    auto feedback = std::make_shared<RobotTaskAction::Feedback>();

    RCLCPP_INFO(node_->get_logger(), "Executing task: task_id=%d",
                goal->task_id);
    publishState("executing");

    bool success = false;

    try {
        switch (goal->task_id) {
            case 0: {
                // Home position
                feedback->status = "Moving to home";
                feedback->completion_percentage = 0.1f;
                goal_handle->publish_feedback(feedback);

                // Default home pose (can be overridden via positions)
                std::vector<double> home = {0.0, -1.57, 0.0, -1.57, 0.0, 0.0};
                if (goal->positions.size() == 6) {
                    home.assign(goal->positions.begin(), goal->positions.end());
                }
                success = robot_manager_.moveJ(home, 0.5, 0.5);

                feedback->completion_percentage = 1.0f;
                goal_handle->publish_feedback(feedback);
                break;
            }

            case 1: {
                // Cartesian move
                if (goal->positions.size() != 6) {
                    result->error_message = "positions must have 6 elements for moveL";
                    break;
                }
                feedback->status = "Moving to target pose";
                feedback->completion_percentage = 0.1f;
                goal_handle->publish_feedback(feedback);

                if (goal_handle->is_canceling()) break;
                std::vector<double> target_pose(goal->positions.begin(),
                                                goal->positions.end());
                success = robot_manager_.moveL(target_pose, 0.1, 0.5);

                feedback->completion_percentage = 1.0f;
                goal_handle->publish_feedback(feedback);
                break;
            }

            case 2: {
                // Joint move
                if (goal->positions.size() != 6) {
                    result->error_message = "positions must have 6 elements for moveJ";
                    break;
                }
                feedback->status = "Moving to joint target";
                feedback->completion_percentage = 0.1f;
                goal_handle->publish_feedback(feedback);

                if (goal_handle->is_canceling()) break;
                std::vector<double> target_joints(goal->positions.begin(),
                                                  goal->positions.end());
                success = robot_manager_.moveJ(target_joints, 0.5, 0.5);

                feedback->completion_percentage = 1.0f;
                goal_handle->publish_feedback(feedback);
                break;
            }

            case 3: {
                // Tool change: open gripper → move to pickup → close gripper
                feedback->status = "Tool change: opening gripper";
                feedback->completion_percentage = 0.1f;
                goal_handle->publish_feedback(feedback);
                robot_manager_.gripperOpen();

                if (goal_handle->is_canceling()) break;

                if (goal->positions.size() == 6) {
                    feedback->status = "Tool change: moving to pickup";
                    feedback->completion_percentage = 0.4f;
                    goal_handle->publish_feedback(feedback);
                    std::vector<double> pickup_pose(goal->positions.begin(),
                                                    goal->positions.end());
                    robot_manager_.moveL(pickup_pose, 0.05, 0.3);
                }

                if (goal_handle->is_canceling()) break;

                feedback->status = "Tool change: closing gripper";
                feedback->completion_percentage = 0.8f;
                goal_handle->publish_feedback(feedback);
                robot_manager_.gripperClose();

                feedback->completion_percentage = 1.0f;
                goal_handle->publish_feedback(feedback);
                success = true;
                break;
            }

            case 4: {
                // Custom path — positions is a flat array of 6-DOF waypoints
                if (goal->positions.empty()) {
                    result->error_message = "No waypoints provided";
                    break;
                }

                std::vector<std::vector<double>> waypoints;
                for (size_t i = 0; i + 5 < goal->positions.size(); i += 6) {
                    waypoints.push_back(std::vector<double>{
                        goal->positions[i],   goal->positions[i+1],
                        goal->positions[i+2], goal->positions[i+3],
                        goal->positions[i+4], goal->positions[i+5]
                    });
                }

                for (size_t i = 0; i < waypoints.size(); ++i) {
                    if (goal_handle->is_canceling()) break;

                    feedback->status = "Waypoint " + std::to_string(i+1) +
                                       "/" + std::to_string(waypoints.size());
                    feedback->completion_percentage = static_cast<float>(i) /
                                         static_cast<float>(waypoints.size());
                    goal_handle->publish_feedback(feedback);

                    if (!robot_manager_.moveL(waypoints[i], 0.05, 0.5)) break;
                    if (i == waypoints.size() - 1) success = true;
                }

                feedback->completion_percentage = 1.0f;
                goal_handle->publish_feedback(feedback);
                break;
            }

            case 5: {
                // customMoveL: TCP target → IK8 → best pick → moveJ (singularity-safe)
                if (goal->positions.size() != 6) {
                    result->error_message = "positions must have 6 elements for customMoveL";
                    break;
                }
                feedback->status = "customMoveL: IK solving + moveJ";
                feedback->completion_percentage = 0.1f;
                goal_handle->publish_feedback(feedback);

                if (goal_handle->is_canceling()) break;
                std::vector<double> tcp_target(goal->positions.begin(),
                                                goal->positions.end());
                success = robot_manager_.customMoveL(tcp_target, 0.5, 0.5);

                feedback->completion_percentage = 1.0f;
                goal_handle->publish_feedback(feedback);
                break;
            }
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(node_->get_logger(), "Task error: %s", e.what());
        result->error_message = std::string("Exception: ") + e.what();
    }

    // Finalize
    if (goal_handle->is_canceling()) {
        result->success = false;
        result->error_message = "Cancelled";
        goal_handle->canceled(result);
        publishState("cancelled");
    } else if (success) {
        result->success = true;
        goal_handle->succeed(result);
        publishState("succeeded");
    } else {
        result->success = false;
        if (result->error_message.empty()) result->error_message = "Task failed";
        goal_handle->abort(result);
        publishState("failed");
    }

    is_executing_ = false;
}

void URRobotActionServer::publishState(const std::string& state)
{
    std_msgs::msg::String msg;
    msg.data = state;
    state_pub_->publish(msg);
}

}  // namespace urRobotManager
