// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nurse_interfaces:msg/SafetySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__TRAITS_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nurse_interfaces/msg/detail/safety_signal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nurse_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SafetySignal & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: decision
  {
    out << "decision: ";
    rosidl_generator_traits::value_to_yaml(msg.decision, out);
    out << ", ";
  }

  // member: reason
  {
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SafetySignal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: decision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "decision: ";
    rosidl_generator_traits::value_to_yaml(msg.decision, out);
    out << "\n";
  }

  // member: reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reason: ";
    rosidl_generator_traits::value_to_yaml(msg.reason, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SafetySignal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace nurse_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use nurse_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const nurse_interfaces::msg::SafetySignal & msg,
  std::ostream & out, size_t indentation = 0)
{
  nurse_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nurse_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nurse_interfaces::msg::SafetySignal & msg)
{
  return nurse_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nurse_interfaces::msg::SafetySignal>()
{
  return "nurse_interfaces::msg::SafetySignal";
}

template<>
inline const char * name<nurse_interfaces::msg::SafetySignal>()
{
  return "nurse_interfaces/msg/SafetySignal";
}

template<>
struct has_fixed_size<nurse_interfaces::msg::SafetySignal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nurse_interfaces::msg::SafetySignal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nurse_interfaces::msg::SafetySignal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__TRAITS_HPP_
