// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__TRAITS_HPP_
#define GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gripper_interfaces/msg/detail/gripper_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gripper_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GripperMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: grp_pos
  {
    out << "grp_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.grp_pos, out);
    out << ", ";
  }

  // member: is_motor_enable
  {
    out << "is_motor_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.is_motor_enable, out);
    out << ", ";
  }

  // member: is_grp_init_ongoing
  {
    out << "is_grp_init_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_grp_init_ongoing, out);
    out << ", ";
  }

  // member: is_pos_ongoing
  {
    out << "is_pos_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_pos_ongoing, out);
    out << ", ";
  }

  // member: is_vel_ongoing
  {
    out << "is_vel_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_vel_ongoing, out);
    out << ", ";
  }

  // member: is_tor_ongoing
  {
    out << "is_tor_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_tor_ongoing, out);
    out << ", ";
  }

  // member: is_grp_opening
  {
    out << "is_grp_opening: ";
    rosidl_generator_traits::value_to_yaml(msg.is_grp_opening, out);
    out << ", ";
  }

  // member: is_grp_closing
  {
    out << "is_grp_closing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_grp_closing, out);
    out << ", ";
  }

  // member: grp_direction
  {
    out << "grp_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.grp_direction, out);
    out << ", ";
  }

  // member: is_object_grasp
  {
    out << "is_object_grasp: ";
    rosidl_generator_traits::value_to_yaml(msg.is_object_grasp, out);
    out << ", ";
  }

  // member: is_fault_occured
  {
    out << "is_fault_occured: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fault_occured, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GripperMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }

  // member: grp_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grp_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.grp_pos, out);
    out << "\n";
  }

  // member: is_motor_enable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_motor_enable: ";
    rosidl_generator_traits::value_to_yaml(msg.is_motor_enable, out);
    out << "\n";
  }

  // member: is_grp_init_ongoing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_grp_init_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_grp_init_ongoing, out);
    out << "\n";
  }

  // member: is_pos_ongoing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_pos_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_pos_ongoing, out);
    out << "\n";
  }

  // member: is_vel_ongoing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_vel_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_vel_ongoing, out);
    out << "\n";
  }

  // member: is_tor_ongoing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_tor_ongoing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_tor_ongoing, out);
    out << "\n";
  }

  // member: is_grp_opening
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_grp_opening: ";
    rosidl_generator_traits::value_to_yaml(msg.is_grp_opening, out);
    out << "\n";
  }

  // member: is_grp_closing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_grp_closing: ";
    rosidl_generator_traits::value_to_yaml(msg.is_grp_closing, out);
    out << "\n";
  }

  // member: grp_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grp_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.grp_direction, out);
    out << "\n";
  }

  // member: is_object_grasp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_object_grasp: ";
    rosidl_generator_traits::value_to_yaml(msg.is_object_grasp, out);
    out << "\n";
  }

  // member: is_fault_occured
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_fault_occured: ";
    rosidl_generator_traits::value_to_yaml(msg.is_fault_occured, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GripperMsg & msg, bool use_flow_style = false)
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

}  // namespace gripper_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use gripper_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gripper_interfaces::msg::GripperMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::msg::GripperMsg & msg)
{
  return gripper_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::msg::GripperMsg>()
{
  return "gripper_interfaces::msg::GripperMsg";
}

template<>
inline const char * name<gripper_interfaces::msg::GripperMsg>()
{
  return "gripper_interfaces/msg/GripperMsg";
}

template<>
struct has_fixed_size<gripper_interfaces::msg::GripperMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interfaces::msg::GripperMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interfaces::msg::GripperMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__TRAITS_HPP_
