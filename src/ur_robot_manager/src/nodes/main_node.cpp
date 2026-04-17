/**
 * @file main_node.cpp
 * @brief Entry point for the UR5e robot manager (single robot).
 *
 * Creates the robot manager, action server, and spins a multi-threaded executor.
 */

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include "ur_robot_manager/core/ur_robot_manager.h"
#include "ur_robot_manager/core/ur_robot_action_server.h"
#include "ur_robot_manager/utils/robot_trajectory.h"
#include <ur_robot_manager_interfaces/action/robot_task.hpp>

const std::string DEFAULT_ROBOT_IP = "192.168.10.126";

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("ur_robot_manager_node");

    // Get robot IP from parameter (default: 192.168.10.126)
    node->declare_parameter<std::string>("robot_ip", DEFAULT_ROBOT_IP);
    std::string robot_ip;
    node->get_parameter("robot_ip", robot_ip);

    // Create robot manager
    urRobotManager::URRobotManager robot_manager(node, robot_ip);

    // Create action server
    urRobotManager::URRobotActionServer action_server(
        node, "robot_action", robot_manager);

    // Wait for action server
    using RobotTaskAction = ur_robot_manager_interfaces::action::RobotTask;
    auto action_client = rclcpp_action::create_client<RobotTaskAction>(
        node, "robot_action");

    RCLCPP_INFO(node->get_logger(), "Waiting for action server...");
    action_client->wait_for_action_server();
    RCLCPP_INFO(node->get_logger(), "Action server ready");

    // Joint state publishing timer (10Hz)
    auto timer = node->create_wall_timer(
        std::chrono::milliseconds(100),
        [&]() {
            if (robot_manager.isRobotConnected()) {
                auto joints = robot_manager.getJointPositions();
                robot_manager.publishJointState(joints);
            }
        });

    // Multi-threaded executor for concurrent callbacks
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
