// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nurse_interfaces:msg/EmergencySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__TRAITS_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nurse_interfaces/msg/detail/emergency_signal__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace nurse_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const EmergencySignal & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: detail
  {
    out << "detail: ";
    rosidl_generator_traits::value_to_yaml(msg.detail, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EmergencySignal & msg,
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

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: detail
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detail: ";
    rosidl_generator_traits::value_to_yaml(msg.detail, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EmergencySignal & msg, bool use_flow_style = false)
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
  const nurse_interfaces::msg::EmergencySignal & msg,
  std::ostream & out, size_t indentation = 0)
{
  nurse_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nurse_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nurse_interfaces::msg::EmergencySignal & msg)
{
  return nurse_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nurse_interfaces::msg::EmergencySignal>()
{
  return "nurse_interfaces::msg::EmergencySignal";
}

template<>
inline const char * name<nurse_interfaces::msg::EmergencySignal>()
{
  return "nurse_interfaces/msg/EmergencySignal";
}

template<>
struct has_fixed_size<nurse_interfaces::msg::EmergencySignal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nurse_interfaces::msg::EmergencySignal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nurse_interfaces::msg::EmergencySignal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__TRAITS_HPP_
