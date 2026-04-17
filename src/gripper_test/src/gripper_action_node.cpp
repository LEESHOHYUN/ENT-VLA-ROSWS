#include "gripper_test/gripper_action_node.hpp"

using namespace std::placeholders;

namespace gripper_test {

GripperActionNode::GripperActionNode(const rclcpp::NodeOptions& options)
    : Node("gripper_action", options)
{
    // Create action server
    action_server_ = rclcpp_action::create_server<GripperAction>(
        this,
        "gripper_action",
        std::bind(&GripperActionNode::handle_goal, this, _1, _2),
        std::bind(&GripperActionNode::handle_cancel, this, _1),
        std::bind(&GripperActionNode::handle_accepted, this, _1));

    // Publisher for position commands
    grp_pos_pub_ = this->create_publisher<std_msgs::msg::Int32>("/grp_pos", 10);

    // Subscriber for gripper states
    gripper_states_sub_ = this->create_subscription<gripper_interfaces::msg::GripperMsg>(
        "/gripper_states", 10,
        std::bind(&GripperActionNode::gripper_state_callback, this, _1));

    RCLCPP_INFO(this->get_logger(), "Gripper action server started");
}

rclcpp_action::GoalResponse GripperActionNode::handle_goal(
    const rclcpp_action::GoalUUID& /*uuid*/,
    std::shared_ptr<const GripperAction::Goal> goal)
{
    RCLCPP_INFO(this->get_logger(), "Received goal: position=%d", goal->goal_pose);
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse GripperActionNode::handle_cancel(
    const std::shared_ptr<GoalHandleGripper> /*goal_handle*/)
{
    RCLCPP_INFO(this->get_logger(), "Received cancel request");
    return rclcpp_action::CancelResponse::ACCEPT;
}

void GripperActionNode::handle_accepted(const std::shared_ptr<GoalHandleGripper> goal_handle)
{
    std::thread{std::bind(&GripperActionNode::execute, this, _1), goal_handle}.detach();
}

void GripperActionNode::execute(const std::shared_ptr<GoalHandleGripper> goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Executing goal");
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<GripperAction::Feedback>();
    auto result = std::make_shared<GripperAction::Result>();

    // Send position command
    auto pos_msg = std_msgs::msg::Int32();
    pos_msg.data = goal->goal_pose;
    grp_pos_pub_->publish(pos_msg);

    // Wait for gripper to reach target (with timeout)
    rclcpp::Rate rate(10.0);
    auto start_time = this->now();
    double timeout_sec = 15.0;

    while (rclcpp::ok()) {
        // Check for cancel
        if (goal_handle->is_canceling()) {
            result->final_pose = current_state_.grp_pos;
            goal_handle->canceled(result);
            RCLCPP_INFO(this->get_logger(), "Goal canceled");
            return;
        }

        // Check timeout
        if ((this->now() - start_time).seconds() > timeout_sec) {
            result->final_pose = current_state_.grp_pos;
            goal_handle->abort(result);
            RCLCPP_WARN(this->get_logger(), "Goal timed out");
            return;
        }

        // Publish feedback
        feedback->current_pose = current_state_.grp_pos;
        goal_handle->publish_feedback(feedback);

        // Check if position reached (within tolerance)
        if (state_received_ && !current_state_.is_pos_ongoing) {
            result->final_pose = current_state_.grp_pos;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal succeeded: final_pose=%d", result->final_pose);
            return;
        }

        rate.sleep();
    }
}

void GripperActionNode::gripper_state_callback(
    const gripper_interfaces::msg::GripperMsg::SharedPtr msg)
{
    current_state_ = *msg;
    state_received_ = true;
}

}  // namespace gripper_test

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<gripper_test::GripperActionNode>());
    rclcpp::shutdown();
    return 0;
}
