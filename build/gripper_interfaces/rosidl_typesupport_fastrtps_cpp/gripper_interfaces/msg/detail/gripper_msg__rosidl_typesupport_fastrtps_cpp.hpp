// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gripper_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "gripper_interfaces/msg/detail/gripper_msg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace gripper_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_serialize(
  const gripper_interfaces::msg::GripperMsg & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gripper_interfaces::msg::GripperMsg & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
get_serialized_size(
  const gripper_interfaces::msg::GripperMsg & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
max_serialized_size_GripperMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, msg, GripperMsg)();

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
