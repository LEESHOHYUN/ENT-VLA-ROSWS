// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gripper_interfaces:srv/ArduinoControl.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/srv/detail/arduino_control__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gripper_interfaces/srv/detail/arduino_control__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_serialize(
  const gripper_interfaces::srv::ArduinoControl_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: power
  cdr << (ros_message.power ? true : false);
  // Member: solenoid_valve
  cdr << (ros_message.solenoid_valve ? true : false);
  // Member: spare_1
  cdr << (ros_message.spare_1 ? true : false);
  // Member: spare_2
  cdr << (ros_message.spare_2 ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gripper_interfaces::srv::ArduinoControl_Request & ros_message)
{
  // Member: power
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.power = tmp ? true : false;
  }

  // Member: solenoid_valve
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.solenoid_valve = tmp ? true : false;
  }

  // Member: spare_1
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.spare_1 = tmp ? true : false;
  }

  // Member: spare_2
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.spare_2 = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
get_serialized_size(
  const gripper_interfaces::srv::ArduinoControl_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: power
  {
    size_t item_size = sizeof(ros_message.power);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: solenoid_valve
  {
    size_t item_size = sizeof(ros_message.solenoid_valve);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: spare_1
  {
    size_t item_size = sizeof(ros_message.spare_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: spare_2
  {
    size_t item_size = sizeof(ros_message.spare_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
max_serialized_size_ArduinoControl_Request(
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


  // Member: power
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: solenoid_valve
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: spare_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: spare_2
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
    using DataType = gripper_interfaces::srv::ArduinoControl_Request;
    is_plain =
      (
      offsetof(DataType, spare_2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ArduinoControl_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gripper_interfaces::srv::ArduinoControl_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArduinoControl_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gripper_interfaces::srv::ArduinoControl_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArduinoControl_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gripper_interfaces::srv::ArduinoControl_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArduinoControl_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ArduinoControl_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ArduinoControl_Request__callbacks = {
  "gripper_interfaces::srv",
  "ArduinoControl_Request",
  _ArduinoControl_Request__cdr_serialize,
  _ArduinoControl_Request__cdr_deserialize,
  _ArduinoControl_Request__get_serialized_size,
  _ArduinoControl_Request__max_serialized_size
};

static rosidl_message_type_support_t _ArduinoControl_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArduinoControl_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace gripper_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gripper_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<gripper_interfaces::srv::ArduinoControl_Request>()
{
  return &gripper_interfaces::srv::typesupport_fastrtps_cpp::_ArduinoControl_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, srv, ArduinoControl_Request)() {
  return &gripper_interfaces::srv::typesupport_fastrtps_cpp::_ArduinoControl_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace gripper_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_serialize(
  const gripper_interfaces::srv::ArduinoControl_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: successed
  cdr << (ros_message.successed ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gripper_interfaces::srv::ArduinoControl_Response & ros_message)
{
  // Member: successed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.successed = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
get_serialized_size(
  const gripper_interfaces::srv::ArduinoControl_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: successed
  {
    size_t item_size = sizeof(ros_message.successed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gripper_interfaces
max_serialized_size_ArduinoControl_Response(
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


  // Member: successed
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
    using DataType = gripper_interfaces::srv::ArduinoControl_Response;
    is_plain =
      (
      offsetof(DataType, successed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ArduinoControl_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gripper_interfaces::srv::ArduinoControl_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArduinoControl_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gripper_interfaces::srv::ArduinoControl_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArduinoControl_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gripper_interfaces::srv::ArduinoControl_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArduinoControl_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ArduinoControl_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ArduinoControl_Response__callbacks = {
  "gripper_interfaces::srv",
  "ArduinoControl_Response",
  _ArduinoControl_Response__cdr_serialize,
  _ArduinoControl_Response__cdr_deserialize,
  _ArduinoControl_Response__get_serialized_size,
  _ArduinoControl_Response__max_serialized_size
};

static rosidl_message_type_support_t _ArduinoControl_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArduinoControl_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace gripper_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gripper_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<gripper_interfaces::srv::ArduinoControl_Response>()
{
  return &gripper_interfaces::srv::typesupport_fastrtps_cpp::_ArduinoControl_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, srv, ArduinoControl_Response)() {
  return &gripper_interfaces::srv::typesupport_fastrtps_cpp::_ArduinoControl_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace gripper_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ArduinoControl__callbacks = {
  "gripper_interfaces::srv",
  "ArduinoControl",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, srv, ArduinoControl_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, srv, ArduinoControl_Response)(),
};

static rosidl_service_type_support_t _ArduinoControl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArduinoControl__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace gripper_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gripper_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<gripper_interfaces::srv::ArduinoControl>()
{
  return &gripper_interfaces::srv::typesupport_fastrtps_cpp::_ArduinoControl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gripper_interfaces, srv, ArduinoControl)() {
  return &gripper_interfaces::srv::typesupport_fastrtps_cpp::_ArduinoControl__handle;
}

#ifdef __cplusplus
}
#endif
