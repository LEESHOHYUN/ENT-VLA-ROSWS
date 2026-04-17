// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nurse_interfaces/msg/detail/object_token__rosidl_typesupport_introspection_c.h"
#include "nurse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nurse_interfaces/msg/detail/object_token__functions.h"
#include "nurse_interfaces/msg/detail/object_token__struct.h"


// Include directives for member types
// Member `object_id`
// Member `object_class`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nurse_interfaces__msg__ObjectToken__init(message_memory);
}

void nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_fini_function(void * message_memory)
{
  nurse_interfaces__msg__ObjectToken__fini(message_memory);
}

size_t nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__size_function__ObjectToken__bbox(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__get_const_function__ObjectToken__bbox(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__get_function__ObjectToken__bbox(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__fetch_function__ObjectToken__bbox(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__get_const_function__ObjectToken__bbox(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__assign_function__ObjectToken__bbox(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__get_function__ObjectToken__bbox(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_member_array[6] = {
  {
    "object_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectToken, object_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_class",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectToken, object_class),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectToken, bbox),  // bytes offset in struct
    NULL,  // default value
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__size_function__ObjectToken__bbox,  // size() function pointer
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__get_const_function__ObjectToken__bbox,  // get_const(index) function pointer
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__get_function__ObjectToken__bbox,  // get(index) function pointer
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__fetch_function__ObjectToken__bbox,  // fetch(index, &value) function pointer
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__assign_function__ObjectToken__bbox,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectToken, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "visible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectToken, visible),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectToken, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_members = {
  "nurse_interfaces__msg",  // message namespace
  "ObjectToken",  // message name
  6,  // number of fields
  sizeof(nurse_interfaces__msg__ObjectToken),
  nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_member_array,  // message members
  nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_init_function,  // function to initialize message memory (memory has to be allocated)
  nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_type_support_handle = {
  0,
  &nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nurse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nurse_interfaces, msg, ObjectToken)() {
  nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_type_support_handle.typesupport_identifier) {
    nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nurse_interfaces__msg__ObjectToken__rosidl_typesupport_introspection_c__ObjectToken_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
