// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/srv/detail/gripper_control__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gripper_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gripper_interfaces/srv/detail/gripper_control__struct.h"
#include "gripper_interfaces/srv/detail/gripper_control__functions.h"
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

#include "rosidl_runtime_c/primitives_sequence.h"  // torque_ctrl_param
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // torque_ctrl_param
#include "rosidl_runtime_c/string.h"  // custom_input, grasping_vel, gripper_init
#include "rosidl_runtime_c/string_functions.h"  // custom_input, grasping_vel, gripper_init

// forward declare type support functions


using _GripperControl_Request__ros_msg_type = gripper_interfaces__srv__GripperControl_Request;

static bool _GripperControl_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GripperControl_Request__ros_msg_type * ros_message = static_cast<const _GripperControl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: control_mode
  {
    cdr << ros_message->control_mode;
  }

  // Field name: pos_ctrl_param
  {
    size_t size = 3;
    auto array_ptr = ros_message->pos_ctrl_param;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: vel_ctrl_param
  {
    size_t size = 3;
    auto array_ptr = ros_message->vel_ctrl_param;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: torque_ctrl_param
  {
    size_t size = ros_message->torque_ctrl_param.size;
    auto array_ptr = ros_message->torque_ctrl_param.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: custom_input
  {
    const rosidl_runtime_c__String * str = &ros_message->custom_input;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: gripper_init
  {
    const rosidl_runtime_c__String * str = &ros_message->gripper_init;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: grasping_vel
  {
    const rosidl_runtime_c__String * str = &ros_message->grasping_vel;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _GripperControl_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GripperControl_Request__ros_msg_type * ros_message = static_cast<_GripperControl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: control_mode
  {
    cdr >> ros_message->control_mode;
  }

  // Field name: pos_ctrl_param
  {
    size_t size = 3;
    auto array_ptr = ros_message->pos_ctrl_param;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: vel_ctrl_param
  {
    size_t size = 3;
    auto array_ptr = ros_message->vel_ctrl_param;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: torque_ctrl_param
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->torque_ctrl_param.data) {
      rosidl_runtime_c__uint32__Sequence__fini(&ros_message->torque_ctrl_param);
    }
    if (!rosidl_runtime_c__uint32__Sequence__init(&ros_message->torque_ctrl_param, size)) {
      fprintf(stderr, "failed to create array for field 'torque_ctrl_param'");
      return false;
    }
    auto array_ptr = ros_message->torque_ctrl_param.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: custom_input
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->custom_input.data) {
      rosidl_runtime_c__String__init(&ros_message->custom_input);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->custom_input,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'custom_input'\n");
      return false;
    }
  }

  // Field name: gripper_init
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->gripper_init.data) {
      rosidl_runtime_c__String__init(&ros_message->gripper_init);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->gripper_init,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'gripper_init'\n");
      return false;
    }
  }

  // Field name: grasping_vel
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->grasping_vel.data) {
      rosidl_runtime_c__String__init(&ros_message->grasping_vel);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->grasping_vel,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'grasping_vel'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t get_serialized_size_gripper_interfaces__srv__GripperControl_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GripperControl_Request__ros_msg_type * ros_message = static_cast<const _GripperControl_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name control_mode
  {
    size_t item_size = sizeof(ros_message->control_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos_ctrl_param
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->pos_ctrl_param;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name vel_ctrl_param
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->vel_ctrl_param;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name torque_ctrl_param
  {
    size_t array_size = ros_message->torque_ctrl_param.size;
    auto array_ptr = ros_message->torque_ctrl_param.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name custom_input
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->custom_input.size + 1);
  // field.name gripper_init
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->gripper_init.size + 1);
  // field.name grasping_vel
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->grasping_vel.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _GripperControl_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gripper_interfaces__srv__GripperControl_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t max_serialized_size_gripper_interfaces__srv__GripperControl_Request(
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

  // member: control_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pos_ctrl_param
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: vel_ctrl_param
  {
    size_t array_size = 3;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: torque_ctrl_param
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: custom_input
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: gripper_init
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: grasping_vel
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = gripper_interfaces__srv__GripperControl_Request;
    is_plain =
      (
      offsetof(DataType, grasping_vel) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GripperControl_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gripper_interfaces__srv__GripperControl_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GripperControl_Request = {
  "gripper_interfaces::srv",
  "GripperControl_Request",
  _GripperControl_Request__cdr_serialize,
  _GripperControl_Request__cdr_deserialize,
  _GripperControl_Request__get_serialized_size,
  _GripperControl_Request__max_serialized_size
};

static rosidl_message_type_support_t _GripperControl_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GripperControl_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, GripperControl_Request)() {
  return &_GripperControl_Request__type_support;
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
// #include "gripper_interfaces/srv/detail/gripper_control__struct.h"
// already included above
// #include "gripper_interfaces/srv/detail/gripper_control__functions.h"
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


using _GripperControl_Response__ros_msg_type = gripper_interfaces__srv__GripperControl_Response;

static bool _GripperControl_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GripperControl_Response__ros_msg_type * ros_message = static_cast<const _GripperControl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: successed
  {
    cdr << (ros_message->successed ? true : false);
  }

  return true;
}

static bool _GripperControl_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GripperControl_Response__ros_msg_type * ros_message = static_cast<_GripperControl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: successed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->successed = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t get_serialized_size_gripper_interfaces__srv__GripperControl_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GripperControl_Response__ros_msg_type * ros_message = static_cast<const _GripperControl_Response__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _GripperControl_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gripper_interfaces__srv__GripperControl_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gripper_interfaces
size_t max_serialized_size_gripper_interfaces__srv__GripperControl_Response(
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
    using DataType = gripper_interfaces__srv__GripperControl_Response;
    is_plain =
      (
      offsetof(DataType, successed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GripperControl_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_gripper_interfaces__srv__GripperControl_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GripperControl_Response = {
  "gripper_interfaces::srv",
  "GripperControl_Response",
  _GripperControl_Response__cdr_serialize,
  _GripperControl_Response__cdr_deserialize,
  _GripperControl_Response__get_serialized_size,
  _GripperControl_Response__max_serialized_size
};

static rosidl_message_type_support_t _GripperControl_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GripperControl_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, GripperControl_Response)() {
  return &_GripperControl_Response__type_support;
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
#include "gripper_interfaces/srv/gripper_control.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GripperControl__callbacks = {
  "gripper_interfaces::srv",
  "GripperControl",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, GripperControl_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, GripperControl_Response)(),
};

static rosidl_service_type_support_t GripperControl__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &GripperControl__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, srv, GripperControl)() {
  return &GripperControl__handle;
}

#if defined(__cplusplus)
}
#endif
