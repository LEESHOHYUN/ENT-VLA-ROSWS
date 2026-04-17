// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/DriverEnable.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__DRIVER_ENABLE__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__DRIVER_ENABLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/driver_enable__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriverEnable_Request_enable
{
public:
  Init_DriverEnable_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::DriverEnable_Request enable(::gripper_interfaces::srv::DriverEnable_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::DriverEnable_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::DriverEnable_Request>()
{
  return gripper_interfaces::srv::builder::Init_DriverEnable_Request_enable();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_DriverEnable_Response_successed
{
public:
  Init_DriverEnable_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::DriverEnable_Response successed(::gripper_interfaces::srv::DriverEnable_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::DriverEnable_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::DriverEnable_Response>()
{
  return gripper_interfaces::srv::builder::Init_DriverEnable_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__DRIVER_ENABLE__BUILDER_HPP_
