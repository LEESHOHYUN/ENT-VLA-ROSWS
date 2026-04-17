// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/GripperCommand.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/gripper_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperCommand_Request_value
{
public:
  explicit Init_GripperCommand_Request_value(::gripper_interfaces::srv::GripperCommand_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::srv::GripperCommand_Request value(::gripper_interfaces::srv::GripperCommand_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperCommand_Request msg_;
};

class Init_GripperCommand_Request_command
{
public:
  Init_GripperCommand_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperCommand_Request_value command(::gripper_interfaces::srv::GripperCommand_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_GripperCommand_Request_value(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::GripperCommand_Request>()
{
  return gripper_interfaces::srv::builder::Init_GripperCommand_Request_command();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperCommand_Response_successed
{
public:
  Init_GripperCommand_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::GripperCommand_Response successed(::gripper_interfaces::srv::GripperCommand_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::GripperCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::GripperCommand_Response>()
{
  return gripper_interfaces::srv::builder::Init_GripperCommand_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__BUILDER_HPP_
