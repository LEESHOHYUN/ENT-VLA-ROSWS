// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nurse_interfaces/msg/detail/object_token_array__rosidl_typesupport_introspection_c.h"
#include "nurse_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nurse_interfaces/msg/detail/object_token_array__functions.h"
#include "nurse_interfaces/msg/detail/object_token_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `tokens`
#include "nurse_interfaces/msg/object_token.h"
// Member `tokens`
#include "nurse_interfaces/msg/detail/object_token__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nurse_interfaces__msg__ObjectTokenArray__init(message_memory);
}

void nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_fini_function(void * message_memory)
{
  nurse_interfaces__msg__ObjectTokenArray__fini(message_memory);
}

size_t nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__size_function__ObjectTokenArray__tokens(
  const void * untyped_member)
{
  const nurse_interfaces__msg__ObjectToken__Sequence * member =
    (const nurse_interfaces__msg__ObjectToken__Sequence *)(untyped_member);
  return member->size;
}

const void * nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__get_const_function__ObjectTokenArray__tokens(
  const void * untyped_member, size_t index)
{
  const nurse_interfaces__msg__ObjectToken__Sequence * member =
    (const nurse_interfaces__msg__ObjectToken__Sequence *)(untyped_member);
  return &member->data[index];
}

void * nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__get_function__ObjectTokenArray__tokens(
  void * untyped_member, size_t index)
{
  nurse_interfaces__msg__ObjectToken__Sequence * member =
    (nurse_interfaces__msg__ObjectToken__Sequence *)(untyped_member);
  return &member->data[index];
}

void nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__fetch_function__ObjectTokenArray__tokens(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const nurse_interfaces__msg__ObjectToken * item =
    ((const nurse_interfaces__msg__ObjectToken *)
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__get_const_function__ObjectTokenArray__tokens(untyped_member, index));
  nurse_interfaces__msg__ObjectToken * value =
    (nurse_interfaces__msg__ObjectToken *)(untyped_value);
  *value = *item;
}

void nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__assign_function__ObjectTokenArray__tokens(
  void * untyped_member, size_t index, const void * untyped_value)
{
  nurse_interfaces__msg__ObjectToken * item =
    ((nurse_interfaces__msg__ObjectToken *)
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__get_function__ObjectTokenArray__tokens(untyped_member, index));
  const nurse_interfaces__msg__ObjectToken * value =
    (const nurse_interfaces__msg__ObjectToken *)(untyped_value);
  *item = *value;
}

bool nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__resize_function__ObjectTokenArray__tokens(
  void * untyped_member, size_t size)
{
  nurse_interfaces__msg__ObjectToken__Sequence * member =
    (nurse_interfaces__msg__ObjectToken__Sequence *)(untyped_member);
  nurse_interfaces__msg__ObjectToken__Sequence__fini(member);
  return nurse_interfaces__msg__ObjectToken__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectTokenArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tokens",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces__msg__ObjectTokenArray, tokens),  // bytes offset in struct
    NULL,  // default value
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__size_function__ObjectTokenArray__tokens,  // size() function pointer
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__get_const_function__ObjectTokenArray__tokens,  // get_const(index) function pointer
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__get_function__ObjectTokenArray__tokens,  // get(index) function pointer
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__fetch_function__ObjectTokenArray__tokens,  // fetch(index, &value) function pointer
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__assign_function__ObjectTokenArray__tokens,  // assign(index, value) function pointer
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__resize_function__ObjectTokenArray__tokens  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_members = {
  "nurse_interfaces__msg",  // message namespace
  "ObjectTokenArray",  // message name
  2,  // number of fields
  sizeof(nurse_interfaces__msg__ObjectTokenArray),
  nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_member_array,  // message members
  nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_init_function,  // function to initialize message memory (memory has to be allocated)
  nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_type_support_handle = {
  0,
  &nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nurse_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nurse_interfaces, msg, ObjectTokenArray)() {
  nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nurse_interfaces, msg, ObjectToken)();
  if (!nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_type_support_handle.typesupport_identifier) {
    nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &nurse_interfaces__msg__ObjectTokenArray__rosidl_typesupport_introspection_c__ObjectTokenArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
