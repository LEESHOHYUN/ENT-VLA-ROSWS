// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ur_robot_manager_interfaces:msg/DelayInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ur_robot_manager_interfaces/msg/detail/delay_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ur_robot_manager_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void DelayInfo_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ur_robot_manager_interfaces::msg::DelayInfo(_init);
}

void DelayInfo_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ur_robot_manager_interfaces::msg::DelayInfo *>(message_memory);
  typed_message->~DelayInfo();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DelayInfo_message_member_array[2] = {
  {
    "command",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ur_robot_manager_interfaces::msg::DelayInfo, command),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "delay_sec",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ur_robot_manager_interfaces::msg::DelayInfo, delay_sec),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DelayInfo_message_members = {
  "ur_robot_manager_interfaces::msg",  // message namespace
  "DelayInfo",  // message name
  2,  // number of fields
  sizeof(ur_robot_manager_interfaces::msg::DelayInfo),
  DelayInfo_message_member_array,  // message members
  DelayInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  DelayInfo_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DelayInfo_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DelayInfo_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ur_robot_manager_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ur_robot_manager_interfaces::msg::DelayInfo>()
{
  return &::ur_robot_manager_interfaces::msg::rosidl_typesupport_introspection_cpp::DelayInfo_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ur_robot_manager_interfaces, msg, DelayInfo)() {
  return &::ur_robot_manager_interfaces::msg::rosidl_typesupport_introspection_cpp::DelayInfo_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
