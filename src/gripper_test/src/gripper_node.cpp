#include "gripper_test/gripper_node.hpp"

using namespace std::placeholders;
using namespace std::chrono_literals;

namespace gripper_test {

GripperNode::GripperNode(const rclcpp::NodeOptions& options)
    : Node("gripper_node", options)
{
    // Declare parameters
    this->declare_parameter<int>("slave_number", 1);
    this->declare_parameter<bool>("ui_on", false);
    slave_number_ = this->get_parameter("slave_number").as_int();
    ui_on_ = this->get_parameter("ui_on").as_bool();

    RCLCPP_INFO(this->get_logger(), "Gripper node starting with slave=%d, ui=%s",
                slave_number_, ui_on_ ? "on" : "off");

    // Publisher
    gripper_state_pub_ = this->create_publisher<gripper_interfaces::msg::GripperMsg>(
        "/gripper_states", 10);

    // Subscriber
    grp_pos_sub_ = this->create_subscription<std_msgs::msg::Int32>(
        "/grp_pos", 10, std::bind(&GripperNode::grp_pos_callback, this, _1));

    // Service servers
    gripper_cmd_srv_ = this->create_service<gripper_interfaces::srv::GripperCommand>(
        "gripper_command", std::bind(&GripperNode::handle_gripper_command, this, _1, _2));
    gripper_ctrl_srv_ = this->create_service<gripper_interfaces::srv::GripperControl>(
        "gripper_control", std::bind(&GripperNode::handle_gripper_control, this, _1, _2));
    pos_vel_cur_srv_ = this->create_service<gripper_interfaces::srv::PosVelCurCtrl>(
        "pos_vel_cur_ctrl", std::bind(&GripperNode::handle_pos_vel_cur, this, _1, _2));
    set_param_srv_ = this->create_service<gripper_interfaces::srv::SetParameter>(
        "set_parameter_gripper", std::bind(&GripperNode::handle_set_parameter, this, _1, _2));
    driver_enable_srv_ = this->create_service<gripper_interfaces::srv::DriverEnable>(
        "driver_enable", std::bind(&GripperNode::handle_driver_enable, this, _1, _2));
    slave_change_srv_ = this->create_service<gripper_interfaces::srv::SlaveChange>(
        "slave_change", std::bind(&GripperNode::handle_slave_change, this, _1, _2));
    arduino_ctrl_srv_ = this->create_service<gripper_interfaces::srv::ArduinoControl>(
        "arduino_control", std::bind(&GripperNode::handle_arduino_control, this, _1, _2));
    modbus_srv_ = this->create_service<gripper_interfaces::srv::Modbus>(
        "modbus", std::bind(&GripperNode::handle_modbus, this, _1, _2));
    stop_motor_srv_ = this->create_service<gripper_interfaces::srv::StopMotor>(
        "stop_motor", std::bind(&GripperNode::handle_stop_motor, this, _1, _2));

    // Timer for publishing state at 10Hz
    state_timer_ = this->create_wall_timer(100ms, std::bind(&GripperNode::publish_state, this));

    RCLCPP_INFO(this->get_logger(), "Gripper node initialized");
}

void GripperNode::publish_state()
{
    // TODO: Read actual hardware state via Modbus
    // Port the Modbus communication code from the original gripper_test
    // The original code uses direct serial/Modbus communication with the Faulhaber motor
    gripper_state_pub_->publish(current_state_);
}

void GripperNode::grp_pos_callback(const std_msgs::msg::Int32::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received position command: %d", msg->data);
    // TODO: Send position command to motor via Modbus
    // Port from original gripper_test motor communication code
}

void GripperNode::handle_gripper_command(
    const std::shared_ptr<gripper_interfaces::srv::GripperCommand::Request> request,
    std::shared_ptr<gripper_interfaces::srv::GripperCommand::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Gripper command: cmd=%d, val=%d", request->command, request->value);
    // TODO: Port motor command handling from original gripper_test
    response->successed = true;
}

void GripperNode::handle_gripper_control(
    const std::shared_ptr<gripper_interfaces::srv::GripperControl::Request> request,
    std::shared_ptr<gripper_interfaces::srv::GripperControl::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Gripper control: mode=%d", request->control_mode);
    // TODO: Port motor control mode handling from original gripper_test
    response->successed = true;
}

void GripperNode::handle_pos_vel_cur(
    const std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl::Request> request,
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "PVC ctrl: pos=%d vel=%d acc=%d cur=%d dur=%d",
                request->position, request->velocity, request->acceleration,
                request->current, request->duration);
    // TODO: Port from original gripper_test
    response->successed = true;
}

void GripperNode::handle_set_parameter(
    const std::shared_ptr<gripper_interfaces::srv::SetParameter::Request> request,
    std::shared_ptr<gripper_interfaces::srv::SetParameter::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Set param: velMax=%d accMax=%d", request->vel_max, request->acc_max);
    // TODO: Port from original gripper_test
    response->successed = true;
}

void GripperNode::handle_driver_enable(
    const std::shared_ptr<gripper_interfaces::srv::DriverEnable::Request> request,
    std::shared_ptr<gripper_interfaces::srv::DriverEnable::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Driver enable: %s", request->enable ? "true" : "false");
    // TODO: Port from original gripper_test
    response->successed = true;
}

void GripperNode::handle_slave_change(
    const std::shared_ptr<gripper_interfaces::srv::SlaveChange::Request> request,
    std::shared_ptr<gripper_interfaces::srv::SlaveChange::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Slave change: addr=%d", request->slave_address);
    // TODO: Port from original gripper_test
    response->successed = true;
}

void GripperNode::handle_arduino_control(
    const std::shared_ptr<gripper_interfaces::srv::ArduinoControl::Request> request,
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Arduino: power=%d solenoid=%d",
                request->power, request->solenoid_valve);
    // TODO: Port from original gripper_test
    response->successed = true;
}

void GripperNode::handle_modbus(
    const std::shared_ptr<gripper_interfaces::srv::Modbus::Request> request,
    std::shared_ptr<gripper_interfaces::srv::Modbus::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Modbus: enable=%d addr=%d", request->enable, request->slave_address);
    // TODO: Port from original gripper_test
    response->successed = true;
}

void GripperNode::handle_stop_motor(
    const std::shared_ptr<gripper_interfaces::srv::StopMotor::Request> request,
    std::shared_ptr<gripper_interfaces::srv::StopMotor::Response> response)
{
    RCLCPP_INFO(this->get_logger(), "Stop motor: duration=%d", request->duration);
    // TODO: Port from original gripper_test
    response->successed = true;
}

}  // namespace gripper_test

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<gripper_test::GripperNode>());
    rclcpp::shutdown();
    return 0;
}
