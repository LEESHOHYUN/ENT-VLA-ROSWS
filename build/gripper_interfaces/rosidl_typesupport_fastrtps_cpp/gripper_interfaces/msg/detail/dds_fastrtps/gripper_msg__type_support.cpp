// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/msg/detail/gripper_msg__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gripper_interfaces/msg/detail/gripper_msg__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: angle
  cdr << ros_message.angle;
  // Member: current
  cdr << ros_message.current;
  // Member: velocity
  cdr << ros_message.velocity;
  // Member: grp_pos
  cdr << ros_message.grp_pos;
  // Member: is_motor_enable
  cdr << (ros_message.is_motor_enable ? true : false);
  // Member: is_grp_init_ongoing
  cdr << (ros_message.is_grp_init_ongoing ? true : false);
  // Member: is_pos_ongoing
  cdr << (ros_message.is_pos_ongoing ? true : false);
  // Member: is_vel_ongoing
  cdr << (ros_message.is_vel_ongoing ? true : false);
  // Member: is_tor_ongoing
  cdr << (ros_message.is_tor_ongoing ? true : false);
  // Member: is_grp_opening
  cdr << (ros_message.is_grp_opening ? true : false);
  // Member: is_grp_closing
  cdr << (ros_message.is_grp_closing ? true : false);
  // Member: grp_direction
  cdr << (ros_message.grp_direction ? true : false);
  // Member: is_object_grasp
  cdr << (ros_message.is_object_grasp ? true : false);
  // Member: is_fault_occured
  cdr << (ros_message.is_fault_occured ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gripper_interfaces::msg::GripperMsg & ros_message)
{
  // Member: angle
  cdr >> ros_message.angle;

  // Member: current
  cdr >> ros_message.current;

  // Member: velocity
  cdr >> ros_message.velocity;

  // Member: grp_pos
  cdr >> ros_message.grp_pos;

  // Member: is_motor_enable
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_motor_enable = tmp ? true : false;
  }

  // Member: is_grp_init_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_grp_init_ongoing = tmp ? true : false;
  }

  // Member: is_pos_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_pos_ongoing = tmp ? true : false;
  }

  // Member: is_vel_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_vel_ongoing = tmp ? true : false;
  }

  // Member: is_tor_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_tor_ongoing = tmp ? true : false;
  }

  // Member: is_grp_opening
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_grp_opening = tmp ? true : false;
  }

  // Member: is_grp_closing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_grp_closing = tmp ? true : false;
  }

  // Member: grp_direction
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.grp_direction = tmp ? true : false;
  }

  // Member: is_object_grasp
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_object_grasp = tmp ? true : false;
  }

  // Member: is_fault_occured
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_fault_occured = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
get_serialized_size(
  const gripper_interfaces::msg::GripperMsg & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: angle
  {
    size_t item_size = sizeof(ros_message.angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current
  {
    size_t item_size = sizeof(ros_message.current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: velocity
  {
    size_t item_size = sizeof(ros_message.velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: grp_pos
  {
    size_t item_size = sizeof(ros_message.grp_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_motor_enable
  {
    size_t item_size = sizeof(ros_message.is_motor_enable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_grp_init_ongoing
  {
    size_t item_size = sizeof(ros_message.is_grp_init_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_pos_ongoing
  {
    size_t item_size = sizeof(ros_message.is_pos_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_vel_ongoing
  {
    size_t item_size = sizeof(ros_message.is_vel_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_tor_ongoing
  {
    size_t item_size = sizeof(ros_message.is_tor_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_grp_opening
  {
    size_t item_size = sizeof(ros_message.is_grp_opening);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_grp_closing
  {
    size_t item_size = sizeof(ros_message.is_grp_closing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: grp_direction
  {
    size_t item_size = sizeof(ros_message.grp_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_object_grasp
  {
    size_t item_size = sizeof(ros_message.is_object_grasp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_fault_occured
  {
    size_t item_size = sizeof(ros_message.is_fault_occured);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
max_serialized_size_GripperMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: grp_pos
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: is_motor_enable
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_grp_init_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_pos_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_vel_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_tor_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_grp_opening
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_grp_closing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: grp_direction
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_object_grasp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_fault_occured
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gripper_interfaces::msg::GripperMsg;
    is_plain =
      (
      offsetof(DataType, is_fault_occured) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GripperMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gripper_interfaces::msg::GripperMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GripperMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gripper_interfaces::msg::GripperMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GripperMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gripper_interfaces::msg::GripperMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GripperMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GripperMsg(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GripperMsg__callbacks = {
  "gripper_interfaces::msg",
  "GripperMsg",
  _GripperMsg__cdr_serialize,
  _GripperMsg__cdr_deserialize,
  _GripperMsg__get_serialized_size,
  _GripperMsg__max_serialized_size
};

static rosidl_message_type_support_t _GripperMsg__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GripperMsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gripper_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gripper_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<gripper_interfaces::msg::GripperMsg>()
{
  return &gripper_interfaces::msg::typesupport_fastrtps_cpp::_GripperMsg__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, msg, GripperMsg)() {
  return &gripper_interfaces::msg::typesupport_fastrtps_cpp::_GripperMsg__handle;
}

#ifdef __cplusplus
}
#endif
