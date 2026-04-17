// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gripper_interfaces:srv/Modbus.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__TRAITS_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gripper_interfaces/srv/detail/modbus__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gripper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Modbus_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: enable
  {
    out << "enable: ";
    rosidl_generator_traits::value_to_yaml(msg.enable, out);
    out << ", ";
  }

  // member: slave_address
  {
    out << "slave_address: ";
    rosidl_generator_traits::value_to_yaml(msg.slave_address, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Modbus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enable: ";
    rosidl_generator_traits::value_to_yaml(msg.enable, out);
    out << "\n";
  }

  // member: slave_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slave_address: ";
    rosidl_generator_traits::value_to_yaml(msg.slave_address, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Modbus_Request & msg, bool use_flow_style = false)
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
  const gripper_interfaces::srv::Modbus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::srv::Modbus_Request & msg)
{
  return gripper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::srv::Modbus_Request>()
{
  return "gripper_interfaces::srv::Modbus_Request";
}

template<>
inline const char * name<gripper_interfaces::srv::Modbus_Request>()
{
  return "gripper_interfaces/srv/Modbus_Request";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::Modbus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interfaces::srv::Modbus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interfaces::srv::Modbus_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gripper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Modbus_Response & msg,
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
  const Modbus_Response & msg,
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

inline std::string to_yaml(const Modbus_Response & msg, bool use_flow_style = false)
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
  const gripper_interfaces::srv::Modbus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::srv::Modbus_Response & msg)
{
  return gripper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::srv::Modbus_Response>()
{
  return "gripper_interfaces::srv::Modbus_Response";
}

template<>
inline const char * name<gripper_interfaces::srv::Modbus_Response>()
{
  return "gripper_interfaces/srv/Modbus_Response";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::Modbus_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interfaces::srv::Modbus_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interfaces::srv::Modbus_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gripper_interfaces::srv::Modbus>()
{
  return "gripper_interfaces::srv::Modbus";
}

template<>
inline const char * name<gripper_interfaces::srv::Modbus>()
{
  return "gripper_interfaces/srv/Modbus";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::Modbus>
  : std::integral_constant<
    bool,
    has_fixed_size<gripper_interfaces::srv::Modbus_Request>::value &&
    has_fixed_size<gripper_interfaces::srv::Modbus_Response>::value
  >
{
};

template<>
struct has_bounded_size<gripper_interfaces::srv::Modbus>
  : std::integral_constant<
    bool,
    has_bounded_size<gripper_interfaces::srv::Modbus_Request>::value &&
    has_bounded_size<gripper_interfaces::srv::Modbus_Response>::value
  >
{
};

template<>
struct is_service<gripper_interfaces::srv::Modbus>
  : std::true_type
{
};

template<>
struct is_service_request<gripper_interfaces::srv::Modbus_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gripper_interfaces::srv::Modbus_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__TRAITS_HPP_
