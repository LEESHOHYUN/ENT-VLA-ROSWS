// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__TRAITS_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "nurse_interfaces/msg/detail/object_token__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace nurse_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectToken & msg,
  std::ostream & out)
{
  out << "{";
  // member: object_id
  {
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << ", ";
  }

  // member: object_class
  {
    out << "object_class: ";
    rosidl_generator_traits::value_to_yaml(msg.object_class, out);
    out << ", ";
  }

  // member: bbox
  {
    if (msg.bbox.size() == 0) {
      out << "bbox: []";
    } else {
      out << "bbox: [";
      size_t pending_items = msg.bbox.size();
      for (auto item : msg.bbox) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: visible
  {
    out << "visible: ";
    rosidl_generator_traits::value_to_yaml(msg.visible, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectToken & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: object_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << "\n";
  }

  // member: object_class
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_class: ";
    rosidl_generator_traits::value_to_yaml(msg.object_class, out);
    out << "\n";
  }

  // member: bbox
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bbox.size() == 0) {
      out << "bbox: []\n";
    } else {
      out << "bbox:\n";
      for (auto item : msg.bbox) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "visible: ";
    rosidl_generator_traits::value_to_yaml(msg.visible, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectToken & msg, bool use_flow_style = false)
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
  const nurse_interfaces::msg::ObjectToken & msg,
  std::ostream & out, size_t indentation = 0)
{
  nurse_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use nurse_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const nurse_interfaces::msg::ObjectToken & msg)
{
  return nurse_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<nurse_interfaces::msg::ObjectToken>()
{
  return "nurse_interfaces::msg::ObjectToken";
}

template<>
inline const char * name<nurse_interfaces::msg::ObjectToken>()
{
  return "nurse_interfaces/msg/ObjectToken";
}

template<>
struct has_fixed_size<nurse_interfaces::msg::ObjectToken>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<nurse_interfaces::msg::ObjectToken>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<nurse_interfaces::msg::ObjectToken>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__TRAITS_HPP_
