// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__TRAITS_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gripper_interfaces/srv/detail/gripper_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gripper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GripperControl_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << ", ";
  }

  // member: pos_ctrl_param
  {
    if (msg.pos_ctrl_param.size() == 0) {
      out << "pos_ctrl_param: []";
    } else {
      out << "pos_ctrl_param: [";
      size_t pending_items = msg.pos_ctrl_param.size();
      for (auto item : msg.pos_ctrl_param) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: vel_ctrl_param
  {
    if (msg.vel_ctrl_param.size() == 0) {
      out << "vel_ctrl_param: []";
    } else {
      out << "vel_ctrl_param: [";
      size_t pending_items = msg.vel_ctrl_param.size();
      for (auto item : msg.vel_ctrl_param) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: torque_ctrl_param
  {
    if (msg.torque_ctrl_param.size() == 0) {
      out << "torque_ctrl_param: []";
    } else {
      out << "torque_ctrl_param: [";
      size_t pending_items = msg.torque_ctrl_param.size();
      for (auto item : msg.torque_ctrl_param) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: custom_input
  {
    out << "custom_input: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_input, out);
    out << ", ";
  }

  // member: gripper_init
  {
    out << "gripper_init: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_init, out);
    out << ", ";
  }

  // member: grasping_vel
  {
    out << "grasping_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.grasping_vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GripperControl_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }

  // member: pos_ctrl_param
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pos_ctrl_param.size() == 0) {
      out << "pos_ctrl_param: []\n";
    } else {
      out << "pos_ctrl_param:\n";
      for (auto item : msg.pos_ctrl_param) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: vel_ctrl_param
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vel_ctrl_param.size() == 0) {
      out << "vel_ctrl_param: []\n";
    } else {
      out << "vel_ctrl_param:\n";
      for (auto item : msg.vel_ctrl_param) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: torque_ctrl_param
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.torque_ctrl_param.size() == 0) {
      out << "torque_ctrl_param: []\n";
    } else {
      out << "torque_ctrl_param:\n";
      for (auto item : msg.torque_ctrl_param) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: custom_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "custom_input: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_input, out);
    out << "\n";
  }

  // member: gripper_init
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_init: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_init, out);
    out << "\n";
  }

  // member: grasping_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grasping_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.grasping_vel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GripperControl_Request & msg, bool use_flow_style = false)
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
  const gripper_interfaces::srv::GripperControl_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::srv::GripperControl_Request & msg)
{
  return gripper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::srv::GripperControl_Request>()
{
  return "gripper_interfaces::srv::GripperControl_Request";
}

template<>
inline const char * name<gripper_interfaces::srv::GripperControl_Request>()
{
  return "gripper_interfaces/srv/GripperControl_Request";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::GripperControl_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gripper_interfaces::srv::GripperControl_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gripper_interfaces::srv::GripperControl_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gripper_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GripperControl_Response & msg,
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
  const GripperControl_Response & msg,
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

inline std::string to_yaml(const GripperControl_Response & msg, bool use_flow_style = false)
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
  const gripper_interfaces::srv::GripperControl_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gripper_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gripper_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const gripper_interfaces::srv::GripperControl_Response & msg)
{
  return gripper_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gripper_interfaces::srv::GripperControl_Response>()
{
  return "gripper_interfaces::srv::GripperControl_Response";
}

template<>
inline const char * name<gripper_interfaces::srv::GripperControl_Response>()
{
  return "gripper_interfaces/srv/GripperControl_Response";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::GripperControl_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gripper_interfaces::srv::GripperControl_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gripper_interfaces::srv::GripperControl_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gripper_interfaces::srv::GripperControl>()
{
  return "gripper_interfaces::srv::GripperControl";
}

template<>
inline const char * name<gripper_interfaces::srv::GripperControl>()
{
  return "gripper_interfaces/srv/GripperControl";
}

template<>
struct has_fixed_size<gripper_interfaces::srv::GripperControl>
  : std::integral_constant<
    bool,
    has_fixed_size<gripper_interfaces::srv::GripperControl_Request>::value &&
    has_fixed_size<gripper_interfaces::srv::GripperControl_Response>::value
  >
{
};

template<>
struct has_bounded_size<gripper_interfaces::srv::GripperControl>
  : std::integral_constant<
    bool,
    has_bounded_size<gripper_interfaces::srv::GripperControl_Request>::value &&
    has_bounded_size<gripper_interfaces::srv::GripperControl_Response>::value
  >
{
};

template<>
struct is_service<gripper_interfaces::srv::GripperControl>
  : std::true_type
{
};

template<>
struct is_service_request<gripper_interfaces::srv::GripperControl_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gripper_interfaces::srv::GripperControl_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__TRAITS_HPP_
