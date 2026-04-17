// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gripper_interfaces:srv/ArduinoControl.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/srv/detail/arduino_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gripper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gripper_interfaces/srv/detail/arduino_control__struct.h"
#include "gripper_interfaces/srv/detail/arduino_control__functions.h"
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


using _ArduinoControl_Request__ros_msg_type = gripper_interfaces__srv__ArduinoControl_Request;

static bool _ArduinoControl_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ArduinoControl_Request__ros_msg_type * ros_message = static_cast<const _ArduinoControl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: power
  {
    cdr << (ros_message->power ? true : false);
  }

  // Field name: solenoid_valve
  {
    cdr << (ros_message->solenoid_valve ? true : false);
  }

  // Field name: spare_1
  {
    cdr << (ros_message->spare_1 ? true : false);
  }

  // Field name: spare_2
  {
    cdr << (ros_message->spare_2 ? true : false);
  }

  return true;
}

static bool _ArduinoControl_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ArduinoControl_Request__ros_msg_type * ros_message = static_cast<_ArduinoControl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: power
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->power = tmp ? true : false;
  }

  // Field name: solenoid_valve
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->solenoid_valve = tmp ? true : false;
  }

  // Field name: spare_1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->spare_1 = tmp ? true : false;
  }

  // Field name: spare_2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->spare_2 = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t get_serialized_size_gripper_interfaces__srv__ArduinoControl_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ArduinoControl_Request__ros_msg_type * ros_message = static_cast<const _ArduinoControl_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name power
  {
    size_t item_size = sizeof(ros_message->power);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name solenoid_valve
  {
    size_t item_size = sizeof(ros_message->solenoid_valve);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name spare_1
  {
    size_t item_size = sizeof(ros_message->spare_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name spare_2
  {
    size_t item_size = sizeof(ros_message->spare_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ArduinoControl_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gripper_interfaces__srv__ArduinoControl_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t max_serialized_size_gripper_interfaces__srv__ArduinoControl_Request(
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

  // member: power
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: solenoid_valve
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: spare_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: spare_2
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
    using DataType = gripper_interfaces__srv__ArduinoControl_Request;
    is_plain =
      (
      offsetof(DataType, spare_2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ArduinoControl_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gripper_interfaces__srv__ArduinoControl_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ArduinoControl_Request = {
  "gripper_interfaces::srv",
  "ArduinoControl_Request",
  _ArduinoControl_Request__cdr_serialize,
  _ArduinoControl_Request__cdr_deserialize,
  _ArduinoControl_Request__get_serialized_size,
  _ArduinoControl_Request__max_serialized_size
};

static rosidl_message_type_support_t _ArduinoControl_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ArduinoControl_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, ArduinoControl_Request)() {
  return &_ArduinoControl_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "gripper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "gripper_interfaces/srv/detail/arduino_control__struct.h"
// already included above
// #include "gripper_interfaces/srv/detail/arduino_control__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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


using _ArduinoControl_Response__ros_msg_type = gripper_interfaces__srv__ArduinoControl_Response;

static bool _ArduinoControl_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ArduinoControl_Response__ros_msg_type * ros_message = static_cast<const _ArduinoControl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: successed
  {
    cdr << (ros_message->successed ? true : false);
  }

  return true;
}

static bool _ArduinoControl_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ArduinoControl_Response__ros_msg_type * ros_message = static_cast<_ArduinoControl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: successed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->successed = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t get_serialized_size_gripper_interfaces__srv__ArduinoControl_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ArduinoControl_Response__ros_msg_type * ros_message = static_cast<const _ArduinoControl_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name successed
  {
    size_t item_size = sizeof(ros_message->successed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ArduinoControl_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gripper_interfaces__srv__ArduinoControl_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t max_serialized_size_gripper_interfaces__srv__ArduinoControl_Response(
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

  // member: successed
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
    using DataType = gripper_interfaces__srv__ArduinoControl_Response;
    is_plain =
      (
      offsetof(DataType, successed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ArduinoControl_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gripper_interfaces__srv__ArduinoControl_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ArduinoControl_Response = {
  "gripper_interfaces::srv",
  "ArduinoControl_Response",
  _ArduinoControl_Response__cdr_serialize,
  _ArduinoControl_Response__cdr_deserialize,
  _ArduinoControl_Response__get_serialized_size,
  _ArduinoControl_Response__max_serialized_size
};

static rosidl_message_type_support_t _ArduinoControl_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ArduinoControl_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, ArduinoControl_Response)() {
  return &_ArduinoControl_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "gripper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gripper_interfaces/srv/arduino_control.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ArduinoControl__callbacks = {
  "gripper_interfaces::srv",
  "ArduinoControl",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, ArduinoControl_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, ArduinoControl_Response)(),
};

static rosidl_service_type_support_t ArduinoControl__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ArduinoControl__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, ArduinoControl)() {
  return &ArduinoControl__handle;
}

#if defined(__cplusplus)
}
#endif
