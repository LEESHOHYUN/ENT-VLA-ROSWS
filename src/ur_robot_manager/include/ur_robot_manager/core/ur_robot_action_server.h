#pragma once

/**
 * @file ur_robot_action_server.h
 * @brief ROS2 action server for UR5e robot task execution.
 *
 * Accepts RobotTask goals and dispatches them to URRobotManager
 * motion commands. Single robot only.
 */

#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <std_msgs/msg/string.hpp>
#include <ur_robot_manager_interfaces/action/robot_task.hpp>

namespace urRobotManager {

class URRobotManager;

class URRobotActionServer {
public:
    using RobotTaskAction = ur_robot_manager_interfaces::action::RobotTask;
    using GoalHandleRobotTask = rclcpp_action::ServerGoalHandle<RobotTaskAction>;

    URRobotActionServer(rclcpp::Node::SharedPtr node,
                        const std::string& action_name,
                        URRobotManager& robot_manager);

    URRobotActionServer(const URRobotActionServer&) = delete;
    URRobotActionServer& operator=(const URRobotActionServer&) = delete;

    bool isExecuting() const { return is_executing_; }

private:
    rclcpp_action::GoalResponse handleGoal(
        const rclcpp_action::GoalUUID& uuid,
        std::shared_ptr<const RobotTaskAction::Goal> goal);

    rclcpp_action::CancelResponse handleCancel(
        const std::shared_ptr<GoalHandleRobotTask> goal_handle);

    void handleAccepted(
        const std::shared_ptr<GoalHandleRobotTask> goal_handle);

    void executeTask(const std::shared_ptr<GoalHandleRobotTask> goal_handle);

    void publishState(const std::string& state);

    rclcpp::Node::SharedPtr node_;
    std::string action_name_;
    URRobotManager& robot_manager_;
    bool is_executing_;

    rclcpp_action::Server<RobotTaskAction>::SharedPtr action_server_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_pub_;
};

} // namespace urRobotManager
