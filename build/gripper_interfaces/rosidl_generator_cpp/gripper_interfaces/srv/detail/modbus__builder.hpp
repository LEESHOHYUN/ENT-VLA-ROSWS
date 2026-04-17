// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/Modbus.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/modbus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_Modbus_Request_slave_address
{
public:
  explicit Init_Modbus_Request_slave_address(::gripper_interfaces::srv::Modbus_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::srv::Modbus_Request slave_address(::gripper_interfaces::srv::Modbus_Request::_slave_address_type arg)
  {
    msg_.slave_address = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::Modbus_Request msg_;
};

class Init_Modbus_Request_enable
{
public:
  Init_Modbus_Request_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Modbus_Request_slave_address enable(::gripper_interfaces::srv::Modbus_Request::_enable_type arg)
  {
    msg_.enable = std::move(arg);
    return Init_Modbus_Request_slave_address(msg_);
  }

private:
  ::gripper_interfaces::srv::Modbus_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::Modbus_Request>()
{
  return gripper_interfaces::srv::builder::Init_Modbus_Request_enable();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_Modbus_Response_successed
{
public:
  Init_Modbus_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::Modbus_Response successed(::gripper_interfaces::srv::Modbus_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::Modbus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::Modbus_Response>()
{
  return gripper_interfaces::srv::builder::Init_Modbus_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__BUILDER_HPP_
