// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/SlaveChange.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__SLAVE_CHANGE__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__SLAVE_CHANGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/slave_change__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_SlaveChange_Request_slave_address
{
public:
  Init_SlaveChange_Request_slave_address()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::SlaveChange_Request slave_address(::gripper_interfaces::srv::SlaveChange_Request::_slave_address_type arg)
  {
    msg_.slave_address = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::SlaveChange_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::SlaveChange_Request>()
{
  return gripper_interfaces::srv::builder::Init_SlaveChange_Request_slave_address();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_SlaveChange_Response_successed
{
public:
  Init_SlaveChange_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::SlaveChange_Response successed(::gripper_interfaces::srv::SlaveChange_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::SlaveChange_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::SlaveChange_Response>()
{
  return gripper_interfaces::srv::builder::Init_SlaveChange_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__SLAVE_CHANGE__BUILDER_HPP_
