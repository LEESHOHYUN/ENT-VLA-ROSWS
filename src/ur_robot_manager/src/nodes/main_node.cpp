/**
 * @file main_node.cpp
 * @brief Entry point for the UR5e robot manager (single robot).
 *
 * Creates the ROS node, URRobotManager (ROS adapter wrapping URHardware),
 * URRobotActionServer, and spins on a MultiThreadedExecutor.
 *
 * State publishing + safety checks run at 100Hz inside URRobotManager.
 */

#include <rclcpp/rclcpp.hpp>
#include "ur_robot_manager/core/ur_robot_manager.h"
#include "ur_robot_manager/core/ur_robot_action_server.h"

const std::string DEFAULT_ROBOT_IP = "192.168.10.126";

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("ur_robot_manager_node");

    node->declare_parameter<std::string>("robot_ip", DEFAULT_ROBOT_IP);
    std::string robot_ip;
    node->get_parameter("robot_ip", robot_ip);

    urRobotManager::URRobotManager robot_manager(node, robot_ip);
    urRobotManager::URRobotActionServer action_server(
        node, "robot_action", robot_manager);

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
