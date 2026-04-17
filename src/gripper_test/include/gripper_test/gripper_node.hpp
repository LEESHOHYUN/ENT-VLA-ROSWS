#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <gripper_interfaces/msg/gripper_msg.hpp>
#include <gripper_interfaces/srv/gripper_command.hpp>
#include <gripper_interfaces/srv/gripper_control.hpp>
#include <gripper_interfaces/srv/pos_vel_cur_ctrl.hpp>
#include <gripper_interfaces/srv/set_parameter.hpp>
#include <gripper_interfaces/srv/driver_enable.hpp>
#include <gripper_interfaces/srv/slave_change.hpp>
#include <gripper_interfaces/srv/arduino_control.hpp>
#include <gripper_interfaces/srv/modbus.hpp>
#include <gripper_interfaces/srv/stop_motor.hpp>
#include <memory>

namespace gripper_test {

class GripperNode : public rclcpp::Node {
public:
    explicit GripperNode(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

private:
    // Parameters
    int slave_number_;
    bool ui_on_;

    // Publisher for gripper states
    rclcpp::Publisher<gripper_interfaces::msg::GripperMsg>::SharedPtr gripper_state_pub_;

    // Subscriber for position commands
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr grp_pos_sub_;

    // Service servers
    rclcpp::Service<gripper_interfaces::srv::GripperCommand>::SharedPtr gripper_cmd_srv_;
    rclcpp::Service<gripper_interfaces::srv::GripperControl>::SharedPtr gripper_ctrl_srv_;
    rclcpp::Service<gripper_interfaces::srv::PosVelCurCtrl>::SharedPtr pos_vel_cur_srv_;
    rclcpp::Service<gripper_interfaces::srv::SetParameter>::SharedPtr set_param_srv_;
    rclcpp::Service<gripper_interfaces::srv::DriverEnable>::SharedPtr driver_enable_srv_;
    rclcpp::Service<gripper_interfaces::srv::SlaveChange>::SharedPtr slave_change_srv_;
    rclcpp::Service<gripper_interfaces::srv::ArduinoControl>::SharedPtr arduino_ctrl_srv_;
    rclcpp::Service<gripper_interfaces::srv::Modbus>::SharedPtr modbus_srv_;
    rclcpp::Service<gripper_interfaces::srv::StopMotor>::SharedPtr stop_motor_srv_;

    // Timer for publishing state
    rclcpp::TimerBase::SharedPtr state_timer_;

    // Current gripper state
    gripper_interfaces::msg::GripperMsg current_state_;

    void publish_state();
    void grp_pos_callback(const std_msgs::msg::Int32::SharedPtr msg);

    // Service callbacks
    void handle_gripper_command(
        const std::shared_ptr<gripper_interfaces::srv::GripperCommand::Request> request,
        std::shared_ptr<gripper_interfaces::srv::GripperCommand::Response> response);
    void handle_gripper_control(
        const std::shared_ptr<gripper_interfaces::srv::GripperControl::Request> request,
        std::shared_ptr<gripper_interfaces::srv::GripperControl::Response> response);
    void handle_pos_vel_cur(
        const std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl::Request> request,
        std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl::Response> response);
    void handle_set_parameter(
        const std::shared_ptr<gripper_interfaces::srv::SetParameter::Request> request,
        std::shared_ptr<gripper_interfaces::srv::SetParameter::Response> response);
    void handle_driver_enable(
        const std::shared_ptr<gripper_interfaces::srv::DriverEnable::Request> request,
        std::shared_ptr<gripper_interfaces::srv::DriverEnable::Response> response);
    void handle_slave_change(
        const std::shared_ptr<gripper_interfaces::srv::SlaveChange::Request> request,
        std::shared_ptr<gripper_interfaces::srv::SlaveChange::Response> response);
    void handle_arduino_control(
        const std::shared_ptr<gripper_interfaces::srv::ArduinoControl::Request> request,
        std::shared_ptr<gripper_interfaces::srv::ArduinoControl::Response> response);
    void handle_modbus(
        const std::shared_ptr<gripper_interfaces::srv::Modbus::Request> request,
        std::shared_ptr<gripper_interfaces::srv::Modbus::Response> response);
    void handle_stop_motor(
        const std::shared_ptr<gripper_interfaces::srv::StopMotor::Request> request,
        std::shared_ptr<gripper_interfaces::srv::StopMotor::Response> response);
};

}  // namespace gripper_test
