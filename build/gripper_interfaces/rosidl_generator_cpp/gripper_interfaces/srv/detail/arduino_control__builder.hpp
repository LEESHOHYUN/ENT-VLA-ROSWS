// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/ArduinoControl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__ARDUINO_CONTROL__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__ARDUINO_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/arduino_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArduinoControl_Request_spare_2
{
public:
  explicit Init_ArduinoControl_Request_spare_2(::gripper_interfaces::srv::ArduinoControl_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::srv::ArduinoControl_Request spare_2(::gripper_interfaces::srv::ArduinoControl_Request::_spare_2_type arg)
  {
    msg_.spare_2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::ArduinoControl_Request msg_;
};

class Init_ArduinoControl_Request_spare_1
{
public:
  explicit Init_ArduinoControl_Request_spare_1(::gripper_interfaces::srv::ArduinoControl_Request & msg)
  : msg_(msg)
  {}
  Init_ArduinoControl_Request_spare_2 spare_1(::gripper_interfaces::srv::ArduinoControl_Request::_spare_1_type arg)
  {
    msg_.spare_1 = std::move(arg);
    return Init_ArduinoControl_Request_spare_2(msg_);
  }

private:
  ::gripper_interfaces::srv::ArduinoControl_Request msg_;
};

class Init_ArduinoControl_Request_solenoid_valve
{
public:
  explicit Init_ArduinoControl_Request_solenoid_valve(::gripper_interfaces::srv::ArduinoControl_Request & msg)
  : msg_(msg)
  {}
  Init_ArduinoControl_Request_spare_1 solenoid_valve(::gripper_interfaces::srv::ArduinoControl_Request::_solenoid_valve_type arg)
  {
    msg_.solenoid_valve = std::move(arg);
    return Init_ArduinoControl_Request_spare_1(msg_);
  }

private:
  ::gripper_interfaces::srv::ArduinoControl_Request msg_;
};

class Init_ArduinoControl_Request_power
{
public:
  Init_ArduinoControl_Request_power()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArduinoControl_Request_solenoid_valve power(::gripper_interfaces::srv::ArduinoControl_Request::_power_type arg)
  {
    msg_.power = std::move(arg);
    return Init_ArduinoControl_Request_solenoid_valve(msg_);
  }

private:
  ::gripper_interfaces::srv::ArduinoControl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::ArduinoControl_Request>()
{
  return gripper_interfaces::srv::builder::Init_ArduinoControl_Request_power();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArduinoControl_Response_successed
{
public:
  Init_ArduinoControl_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::ArduinoControl_Response successed(::gripper_interfaces::srv::ArduinoControl_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::ArduinoControl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::ArduinoControl_Response>()
{
  return gripper_interfaces::srv::builder::Init_ArduinoControl_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__ARDUINO_CONTROL__BUILDER_HPP_
