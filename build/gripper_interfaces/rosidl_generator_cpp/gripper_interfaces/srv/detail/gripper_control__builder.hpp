// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/gripper_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperControl_Request_grasping_vel
{
public:
  explicit Init_GripperControl_Request_grasping_vel(::gripper_interfaces::srv::GripperControl_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::srv::GripperControl_Request grasping_vel(::gripper_interfaces::srv::GripperControl_Request::_grasping_vel_type arg)
  {
    msg_.grasping_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

class Init_GripperControl_Request_gripper_init
{
public:
  explicit Init_GripperControl_Request_gripper_init(::gripper_interfaces::srv::GripperControl_Request & msg)
  : msg_(msg)
  {}
  Init_GripperControl_Request_grasping_vel gripper_init(::gripper_interfaces::srv::GripperControl_Request::_gripper_init_type arg)
  {
    msg_.gripper_init = std::move(arg);
    return Init_GripperControl_Request_grasping_vel(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

class Init_GripperControl_Request_custom_input
{
public:
  explicit Init_GripperControl_Request_custom_input(::gripper_interfaces::srv::GripperControl_Request & msg)
  : msg_(msg)
  {}
  Init_GripperControl_Request_gripper_init custom_input(::gripper_interfaces::srv::GripperControl_Request::_custom_input_type arg)
  {
    msg_.custom_input = std::move(arg);
    return Init_GripperControl_Request_gripper_init(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

class Init_GripperControl_Request_torque_ctrl_param
{
public:
  explicit Init_GripperControl_Request_torque_ctrl_param(::gripper_interfaces::srv::GripperControl_Request & msg)
  : msg_(msg)
  {}
  Init_GripperControl_Request_custom_input torque_ctrl_param(::gripper_interfaces::srv::GripperControl_Request::_torque_ctrl_param_type arg)
  {
    msg_.torque_ctrl_param = std::move(arg);
    return Init_GripperControl_Request_custom_input(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

class Init_GripperControl_Request_vel_ctrl_param
{
public:
  explicit Init_GripperControl_Request_vel_ctrl_param(::gripper_interfaces::srv::GripperControl_Request & msg)
  : msg_(msg)
  {}
  Init_GripperControl_Request_torque_ctrl_param vel_ctrl_param(::gripper_interfaces::srv::GripperControl_Request::_vel_ctrl_param_type arg)
  {
    msg_.vel_ctrl_param = std::move(arg);
    return Init_GripperControl_Request_torque_ctrl_param(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

class Init_GripperControl_Request_pos_ctrl_param
{
public:
  explicit Init_GripperControl_Request_pos_ctrl_param(::gripper_interfaces::srv::GripperControl_Request & msg)
  : msg_(msg)
  {}
  Init_GripperControl_Request_vel_ctrl_param pos_ctrl_param(::gripper_interfaces::srv::GripperControl_Request::_pos_ctrl_param_type arg)
  {
    msg_.pos_ctrl_param = std::move(arg);
    return Init_GripperControl_Request_vel_ctrl_param(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

class Init_GripperControl_Request_control_mode
{
public:
  Init_GripperControl_Request_control_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperControl_Request_pos_ctrl_param control_mode(::gripper_interfaces::srv::GripperControl_Request::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_GripperControl_Request_pos_ctrl_param(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::GripperControl_Request>()
{
  return gripper_interfaces::srv::builder::Init_GripperControl_Request_control_mode();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperControl_Response_successed
{
public:
  Init_GripperControl_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::GripperControl_Response successed(::gripper_interfaces::srv::GripperControl_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::GripperControl_Response>()
{
  return gripper_interfaces::srv::builder::Init_GripperControl_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__BUILDER_HPP_
