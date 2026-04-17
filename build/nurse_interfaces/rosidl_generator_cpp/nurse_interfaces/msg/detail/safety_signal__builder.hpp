// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nurse_interfaces:msg/SafetySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__BUILDER_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nurse_interfaces/msg/detail/safety_signal__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nurse_interfaces
{

namespace msg
{

namespace builder
{

class Init_SafetySignal_reason
{
public:
  explicit Init_SafetySignal_reason(::nurse_interfaces::msg::SafetySignal & msg)
  : msg_(msg)
  {}
  ::nurse_interfaces::msg::SafetySignal reason(::nurse_interfaces::msg::SafetySignal::_reason_type arg)
  {
    msg_.reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nurse_interfaces::msg::SafetySignal msg_;
};

class Init_SafetySignal_decision
{
public:
  explicit Init_SafetySignal_decision(::nurse_interfaces::msg::SafetySignal & msg)
  : msg_(msg)
  {}
  Init_SafetySignal_reason decision(::nurse_interfaces::msg::SafetySignal::_decision_type arg)
  {
    msg_.decision = std::move(arg);
    return Init_SafetySignal_reason(msg_);
  }

private:
  ::nurse_interfaces::msg::SafetySignal msg_;
};

class Init_SafetySignal_header
{
public:
  Init_SafetySignal_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SafetySignal_decision header(::nurse_interfaces::msg::SafetySignal::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SafetySignal_decision(msg_);
  }

private:
  ::nurse_interfaces::msg::SafetySignal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nurse_interfaces::msg::SafetySignal>()
{
  return nurse_interfaces::msg::builder::Init_SafetySignal_header();
}

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__BUILDER_HPP_
