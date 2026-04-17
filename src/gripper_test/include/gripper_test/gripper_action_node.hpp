#pragma once

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <std_msgs/msg/int32.hpp>
#include <gripper_interfaces/msg/gripper_msg.hpp>
#include <gripper_interfaces/action/gripper.hpp>
#include <functional>
#include <memory>
#include <thread>

namespace gripper_test {

class GripperActionNode : public rclcpp::Node {
public:
    using GripperAction = gripper_interfaces::action::Gripper;
    using GoalHandleGripper = rclcpp_action::ServerGoalHandle<GripperAction>;

    explicit GripperActionNode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

private:
    // Action server
    rclcpp_action::Server<GripperAction>::SharedPtr action_server_;

    // Publisher for gripper position commands
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr grp_pos_pub_;

    // Subscriber for gripper states
    rclcpp::Subscription<gripper_interfaces::msg::GripperMsg>::SharedPtr gripper_states_sub_;

    // Current gripper state
    gripper_interfaces::msg::GripperMsg current_state_;
    bool state_received_ = false;

    // Action server callbacks
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID& uuid,
        std::shared_ptr<const GripperAction::Goal> goal);

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleGripper> goal_handle);

    void handle_accepted(const std::shared_ptr<GoalHandleGripper> goal_handle);

    void execute(const std::shared_ptr<GoalHandleGripper> goal_handle);

    // State callback
    void gripper_state_callback(const gripper_interfaces::msg::GripperMsg::SharedPtr msg);
};

}  // namespace gripper_test
