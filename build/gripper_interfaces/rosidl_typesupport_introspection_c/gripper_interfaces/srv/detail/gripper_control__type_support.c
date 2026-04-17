// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gripper_interfaces/srv/detail/gripper_control__rosidl_typesupport_introspection_c.h"
#include "gripper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gripper_interfaces/srv/detail/gripper_control__functions.h"
#include "gripper_interfaces/srv/detail/gripper_control__struct.h"


// Include directives for member types
// Member `torque_ctrl_param`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `custom_input`
// Member `gripper_init`
// Member `grasping_vel`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gripper_interfaces__srv__GripperControl_Request__init(message_memory);
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_fini_function(void * message_memory)
{
  gripper_interfaces__srv__GripperControl_Request__fini(message_memory);
}

size_t gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__size_function__GripperControl_Request__pos_ctrl_param(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__pos_ctrl_param(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__pos_ctrl_param(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__fetch_function__GripperControl_Request__pos_ctrl_param(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__pos_ctrl_param(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__assign_function__GripperControl_Request__pos_ctrl_param(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__pos_ctrl_param(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__size_function__GripperControl_Request__vel_ctrl_param(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__vel_ctrl_param(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__vel_ctrl_param(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__fetch_function__GripperControl_Request__vel_ctrl_param(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__vel_ctrl_param(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__assign_function__GripperControl_Request__vel_ctrl_param(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__vel_ctrl_param(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

size_t gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__size_function__GripperControl_Request__torque_ctrl_param(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return member->size;
}

const void * gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__torque_ctrl_param(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint32__Sequence * member =
    (const rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__torque_ctrl_param(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  return &member->data[index];
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__fetch_function__GripperControl_Request__torque_ctrl_param(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__torque_ctrl_param(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__assign_function__GripperControl_Request__torque_ctrl_param(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__torque_ctrl_param(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

bool gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__resize_function__GripperControl_Request__torque_ctrl_param(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint32__Sequence * member =
    (rosidl_runtime_c__uint32__Sequence *)(untyped_member);
  rosidl_runtime_c__uint32__Sequence__fini(member);
  return rosidl_runtime_c__uint32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_member_array[7] = {
  {
    "control_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, control_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos_ctrl_param",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, pos_ctrl_param),  // bytes offset in struct
    NULL,  // default value
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__size_function__GripperControl_Request__pos_ctrl_param,  // size() function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__pos_ctrl_param,  // get_const(index) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__pos_ctrl_param,  // get(index) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__fetch_function__GripperControl_Request__pos_ctrl_param,  // fetch(index, &value) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__assign_function__GripperControl_Request__pos_ctrl_param,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel_ctrl_param",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, vel_ctrl_param),  // bytes offset in struct
    NULL,  // default value
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__size_function__GripperControl_Request__vel_ctrl_param,  // size() function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__vel_ctrl_param,  // get_const(index) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__vel_ctrl_param,  // get(index) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__fetch_function__GripperControl_Request__vel_ctrl_param,  // fetch(index, &value) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__assign_function__GripperControl_Request__vel_ctrl_param,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "torque_ctrl_param",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, torque_ctrl_param),  // bytes offset in struct
    NULL,  // default value
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__size_function__GripperControl_Request__torque_ctrl_param,  // size() function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_const_function__GripperControl_Request__torque_ctrl_param,  // get_const(index) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__get_function__GripperControl_Request__torque_ctrl_param,  // get(index) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__fetch_function__GripperControl_Request__torque_ctrl_param,  // fetch(index, &value) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__assign_function__GripperControl_Request__torque_ctrl_param,  // assign(index, value) function pointer
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__resize_function__GripperControl_Request__torque_ctrl_param  // resize(index) function pointer
  },
  {
    "custom_input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, custom_input),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_init",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, gripper_init),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "grasping_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Request, grasping_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_members = {
  "gripper_interfaces__srv",  // message namespace
  "GripperControl_Request",  // message name
  7,  // number of fields
  sizeof(gripper_interfaces__srv__GripperControl_Request),
  gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_member_array,  // message members
  gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_type_support_handle = {
  0,
  &gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gripper_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl_Request)() {
  if (!gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_type_support_handle.typesupport_identifier) {
    gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gripper_interfaces__srv__GripperControl_Request__rosidl_typesupport_introspection_c__GripperControl_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "gripper_interfaces/srv/detail/gripper_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "gripper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "gripper_interfaces/srv/detail/gripper_control__functions.h"
// already included above
// #include "gripper_interfaces/srv/detail/gripper_control__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gripper_interfaces__srv__GripperControl_Response__init(message_memory);
}

void gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_fini_function(void * message_memory)
{
  gripper_interfaces__srv__GripperControl_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_member_array[1] = {
  {
    "successed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gripper_interfaces__srv__GripperControl_Response, successed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_members = {
  "gripper_interfaces__srv",  // message namespace
  "GripperControl_Response",  // message name
  1,  // number of fields
  sizeof(gripper_interfaces__srv__GripperControl_Response),
  gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_member_array,  // message members
  gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_type_support_handle = {
  0,
  &gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gripper_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl_Response)() {
  if (!gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_type_support_handle.typesupport_identifier) {
    gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gripper_interfaces__srv__GripperControl_Response__rosidl_typesupport_introspection_c__GripperControl_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "gripper_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "gripper_interfaces/srv/detail/gripper_control__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_members = {
  "gripper_interfaces__srv",  // service namespace
  "GripperControl",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_Request_message_type_support_handle,
  NULL  // response message
  // gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_Response_message_type_support_handle
};

static rosidl_service_type_support_t gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_type_support_handle = {
  0,
  &gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gripper_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl)() {
  if (!gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_type_support_handle.typesupport_identifier) {
    gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, srv, GripperControl_Response)()->data;
  }

  return &gripper_interfaces__srv__detail__gripper_control__rosidl_typesupport_introspection_c__GripperControl_service_type_support_handle;
}
