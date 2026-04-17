// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/SetParameter.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__SET_PARAMETER__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__SET_PARAMETER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/set_parameter__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetParameter_Request_acc_max
{
public:
  explicit Init_SetParameter_Request_acc_max(::gripper_interfaces::srv::SetParameter_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::srv::SetParameter_Request acc_max(::gripper_interfaces::srv::SetParameter_Request::_acc_max_type arg)
  {
    msg_.acc_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::SetParameter_Request msg_;
};

class Init_SetParameter_Request_vel_max
{
public:
  Init_SetParameter_Request_vel_max()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetParameter_Request_acc_max vel_max(::gripper_interfaces::srv::SetParameter_Request::_vel_max_type arg)
  {
    msg_.vel_max = std::move(arg);
    return Init_SetParameter_Request_acc_max(msg_);
  }

private:
  ::gripper_interfaces::srv::SetParameter_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::SetParameter_Request>()
{
  return gripper_interfaces::srv::builder::Init_SetParameter_Request_vel_max();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetParameter_Response_successed
{
public:
  Init_SetParameter_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::SetParameter_Response successed(::gripper_interfaces::srv::SetParameter_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::SetParameter_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::SetParameter_Response>()
{
  return gripper_interfaces::srv::builder::Init_SetParameter_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__SET_PARAMETER__BUILDER_HPP_
