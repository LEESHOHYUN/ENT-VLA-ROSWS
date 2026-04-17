// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nurse_interfaces:msg/EmergencySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__BUILDER_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nurse_interfaces/msg/detail/emergency_signal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nurse_interfaces
{

namespace msg
{

namespace builder
{

class Init_EmergencySignal_detail
{
public:
  explicit Init_EmergencySignal_detail(::nurse_interfaces::msg::EmergencySignal & msg)
  : msg_(msg)
  {}
  ::nurse_interfaces::msg::EmergencySignal detail(::nurse_interfaces::msg::EmergencySignal::_detail_type arg)
  {
    msg_.detail = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nurse_interfaces::msg::EmergencySignal msg_;
};

class Init_EmergencySignal_confidence
{
public:
  explicit Init_EmergencySignal_confidence(::nurse_interfaces::msg::EmergencySignal & msg)
  : msg_(msg)
  {}
  Init_EmergencySignal_detail confidence(::nurse_interfaces::msg::EmergencySignal::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_EmergencySignal_detail(msg_);
  }

private:
  ::nurse_interfaces::msg::EmergencySignal msg_;
};

class Init_EmergencySignal_status
{
public:
  explicit Init_EmergencySignal_status(::nurse_interfaces::msg::EmergencySignal & msg)
  : msg_(msg)
  {}
  Init_EmergencySignal_confidence status(::nurse_interfaces::msg::EmergencySignal::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_EmergencySignal_confidence(msg_);
  }

private:
  ::nurse_interfaces::msg::EmergencySignal msg_;
};

class Init_EmergencySignal_header
{
public:
  Init_EmergencySignal_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EmergencySignal_status header(::nurse_interfaces::msg::EmergencySignal::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EmergencySignal_status(msg_);
  }

private:
  ::nurse_interfaces::msg::EmergencySignal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nurse_interfaces::msg::EmergencySignal>()
{
  return nurse_interfaces::msg::builder::Init_EmergencySignal_header();
}

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__BUILDER_HPP_
