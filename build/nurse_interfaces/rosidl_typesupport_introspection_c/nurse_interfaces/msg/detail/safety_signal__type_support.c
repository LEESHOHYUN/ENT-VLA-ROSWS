// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nurse_interfaces:msg/SafetySignal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nurse_interfaces/msg/detail/safety_signal__rosidl_typesupport_introspection_c.h"
#include "nurse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nurse_interfaces/msg/detail/safety_signal__functions.h"
#include "nurse_interfaces/msg/detail/safety_signal__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `reason`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nurse_interfaces__msg__SafetySignal__init(message_memory);
}

void nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_fini_function(void * message_memory)
{
  nurse_interfaces__msg__SafetySignal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__SafetySignal, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "decision",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__SafetySignal, decision),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__SafetySignal, reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_members = {
  "nurse_interfaces__msg",  // message namespace
  "SafetySignal",  // message name
  3,  // number of fields
  sizeof(nurse_interfaces__msg__SafetySignal),
  nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_member_array,  // message members
  nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_init_function,  // function to initialize message memory (memory has to be allocated)
  nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_type_support_handle = {
  0,
  &nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nurse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nurse_interfaces, msg, SafetySignal)() {
  nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_type_support_handle.typesupport_identifier) {
    nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nurse_interfaces__msg__SafetySignal__rosidl_typesupport_introspection_c__SafetySignal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
