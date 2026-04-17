// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gripper_interfaces:srv/StopMotor.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__STOP_MOTOR__TRAITS_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__STOP_MOTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gripper_interfaces/srv/detail/stop_motor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gripper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StopMotor_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StopMotor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StopMotor_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gripper_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use gripper_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gripper_interfaces::srv::StopMotor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::srv::StopMotor_Request & msg)
{
  return gripper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::srv::StopMotor_Request>()
{
  return "gripper_interfaces::srv::StopMotor_Request";
}

template<>
inline const char * name<gripper_interfaces::srv::StopMotor_Request>()
{
  return "gripper_interfaces/srv/StopMotor_Request";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::StopMotor_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interfaces::srv::StopMotor_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interfaces::srv::StopMotor_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gripper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StopMotor_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: successed
  {
    out << "successed: ";
    rosidl_generator_traits::value_to_yaml(msg.successed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StopMotor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: successed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "successed: ";
    rosidl_generator_traits::value_to_yaml(msg.successed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StopMotor_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gripper_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use gripper_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gripper_interfaces::srv::StopMotor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::srv::StopMotor_Response & msg)
{
  return gripper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::srv::StopMotor_Response>()
{
  return "gripper_interfaces::srv::StopMotor_Response";
}

template<>
inline const char * name<gripper_interfaces::srv::StopMotor_Response>()
{
  return "gripper_interfaces/srv/StopMotor_Response";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::StopMotor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interfaces::srv::StopMotor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interfaces::srv::StopMotor_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gripper_interfaces::srv::StopMotor>()
{
  return "gripper_interfaces::srv::StopMotor";
}

template<>
inline const char * name<gripper_interfaces::srv::StopMotor>()
{
  return "gripper_interfaces/srv/StopMotor";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::StopMotor>
  : std::integral_constant<
    bool,
    has_fixed_size<gripper_interfaces::srv::StopMotor_Request>::value &&
    has_fixed_size<gripper_interfaces::srv::StopMotor_Response>::value
  >
{
};

template<>
struct has_bounded_size<gripper_interfaces::srv::StopMotor>
  : std::integral_constant<
    bool,
    has_bounded_size<gripper_interfaces::srv::StopMotor_Request>::value &&
    has_bounded_size<gripper_interfaces::srv::StopMotor_Response>::value
  >
{
};

template<>
struct is_service<gripper_interfaces::srv::StopMotor>
  : std::true_type
{
};

template<>
struct is_service_request<gripper_interfaces::srv::StopMotor_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gripper_interfaces::srv::StopMotor_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__STOP_MOTOR__TRAITS_HPP_
