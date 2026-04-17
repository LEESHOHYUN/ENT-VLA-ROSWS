// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/msg/detail/gripper_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gripper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gripper_interfaces/msg/detail/gripper_msg__struct.h"
#include "gripper_interfaces/msg/detail/gripper_msg__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GripperMsg__ros_msg_type = gripper_interfaces__msg__GripperMsg;

static bool _GripperMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GripperMsg__ros_msg_type * ros_message = static_cast<const _GripperMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: angle
  {
    cdr << ros_message->angle;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  // Field name: velocity
  {
    cdr << ros_message->velocity;
  }

  // Field name: grp_pos
  {
    cdr << ros_message->grp_pos;
  }

  // Field name: is_motor_enable
  {
    cdr << (ros_message->is_motor_enable ? true : false);
  }

  // Field name: is_grp_init_ongoing
  {
    cdr << (ros_message->is_grp_init_ongoing ? true : false);
  }

  // Field name: is_pos_ongoing
  {
    cdr << (ros_message->is_pos_ongoing ? true : false);
  }

  // Field name: is_vel_ongoing
  {
    cdr << (ros_message->is_vel_ongoing ? true : false);
  }

  // Field name: is_tor_ongoing
  {
    cdr << (ros_message->is_tor_ongoing ? true : false);
  }

  // Field name: is_grp_opening
  {
    cdr << (ros_message->is_grp_opening ? true : false);
  }

  // Field name: is_grp_closing
  {
    cdr << (ros_message->is_grp_closing ? true : false);
  }

  // Field name: grp_direction
  {
    cdr << (ros_message->grp_direction ? true : false);
  }

  // Field name: is_object_grasp
  {
    cdr << (ros_message->is_object_grasp ? true : false);
  }

  // Field name: is_fault_occured
  {
    cdr << (ros_message->is_fault_occured ? true : false);
  }

  return true;
}

static bool _GripperMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GripperMsg__ros_msg_type * ros_message = static_cast<_GripperMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: angle
  {
    cdr >> ros_message->angle;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  // Field name: velocity
  {
    cdr >> ros_message->velocity;
  }

  // Field name: grp_pos
  {
    cdr >> ros_message->grp_pos;
  }

  // Field name: is_motor_enable
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_motor_enable = tmp ? true : false;
  }

  // Field name: is_grp_init_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_grp_init_ongoing = tmp ? true : false;
  }

  // Field name: is_pos_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_pos_ongoing = tmp ? true : false;
  }

  // Field name: is_vel_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_vel_ongoing = tmp ? true : false;
  }

  // Field name: is_tor_ongoing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_tor_ongoing = tmp ? true : false;
  }

  // Field name: is_grp_opening
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_grp_opening = tmp ? true : false;
  }

  // Field name: is_grp_closing
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_grp_closing = tmp ? true : false;
  }

  // Field name: grp_direction
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->grp_direction = tmp ? true : false;
  }

  // Field name: is_object_grasp
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_object_grasp = tmp ? true : false;
  }

  // Field name: is_fault_occured
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_fault_occured = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t get_serialized_size_gripper_interfaces__msg__GripperMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GripperMsg__ros_msg_type * ros_message = static_cast<const _GripperMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name angle
  {
    size_t item_size = sizeof(ros_message->angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name velocity
  {
    size_t item_size = sizeof(ros_message->velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name grp_pos
  {
    size_t item_size = sizeof(ros_message->grp_pos);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_motor_enable
  {
    size_t item_size = sizeof(ros_message->is_motor_enable);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_grp_init_ongoing
  {
    size_t item_size = sizeof(ros_message->is_grp_init_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_pos_ongoing
  {
    size_t item_size = sizeof(ros_message->is_pos_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_vel_ongoing
  {
    size_t item_size = sizeof(ros_message->is_vel_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_tor_ongoing
  {
    size_t item_size = sizeof(ros_message->is_tor_ongoing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_grp_opening
  {
    size_t item_size = sizeof(ros_message->is_grp_opening);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_grp_closing
  {
    size_t item_size = sizeof(ros_message->is_grp_closing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name grp_direction
  {
    size_t item_size = sizeof(ros_message->grp_direction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_object_grasp
  {
    size_t item_size = sizeof(ros_message->is_object_grasp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_fault_occured
  {
    size_t item_size = sizeof(ros_message->is_fault_occured);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GripperMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gripper_interfaces__msg__GripperMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t max_serialized_size_gripper_interfaces__msg__GripperMsg(
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

  // member: angle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: velocity
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: grp_pos
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: is_motor_enable
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_grp_init_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_pos_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_vel_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_tor_ongoing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_grp_opening
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_grp_closing
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: grp_direction
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_object_grasp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_fault_occured
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
    using DataType = gripper_interfaces__msg__GripperMsg;
    is_plain =
      (
      offsetof(DataType, is_fault_occured) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GripperMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gripper_interfaces__msg__GripperMsg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GripperMsg = {
  "gripper_interfaces::msg",
  "GripperMsg",
  _GripperMsg__cdr_serialize,
  _GripperMsg__cdr_deserialize,
  _GripperMsg__get_serialized_size,
  _GripperMsg__max_serialized_size
};

static rosidl_message_type_support_t _GripperMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GripperMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, msg, GripperMsg)() {
  return &_GripperMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
