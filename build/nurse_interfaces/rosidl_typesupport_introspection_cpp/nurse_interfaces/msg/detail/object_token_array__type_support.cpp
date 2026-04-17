// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "nurse_interfaces/msg/detail/object_token_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace nurse_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ObjectTokenArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) nurse_interfaces::msg::ObjectTokenArray(_init);
}

void ObjectTokenArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<nurse_interfaces::msg::ObjectTokenArray *>(message_memory);
  typed_message->~ObjectTokenArray();
}

size_t size_function__ObjectTokenArray__tokens(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<nurse_interfaces::msg::ObjectToken> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ObjectTokenArray__tokens(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<nurse_interfaces::msg::ObjectToken> *>(untyped_member);
  return &member[index];
}

void * get_function__ObjectTokenArray__tokens(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<nurse_interfaces::msg::ObjectToken> *>(untyped_member);
  return &member[index];
}

void fetch_function__ObjectTokenArray__tokens(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const nurse_interfaces::msg::ObjectToken *>(
    get_const_function__ObjectTokenArray__tokens(untyped_member, index));
  auto & value = *reinterpret_cast<nurse_interfaces::msg::ObjectToken *>(untyped_value);
  value = item;
}

void assign_function__ObjectTokenArray__tokens(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<nurse_interfaces::msg::ObjectToken *>(
    get_function__ObjectTokenArray__tokens(untyped_member, index));
  const auto & value = *reinterpret_cast<const nurse_interfaces::msg::ObjectToken *>(untyped_value);
  item = value;
}

void resize_function__ObjectTokenArray__tokens(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<nurse_interfaces::msg::ObjectToken> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ObjectTokenArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces::msg::ObjectTokenArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tokens",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<nurse_interfaces::msg::ObjectToken>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nurse_interfaces::msg::ObjectTokenArray, tokens),  // bytes offset in struct
    nullptr,  // default value
    size_function__ObjectTokenArray__tokens,  // size() function pointer
    get_const_function__ObjectTokenArray__tokens,  // get_const(index) function pointer
    get_function__ObjectTokenArray__tokens,  // get(index) function pointer
    fetch_function__ObjectTokenArray__tokens,  // fetch(index, &value) function pointer
    assign_function__ObjectTokenArray__tokens,  // assign(index, value) function pointer
    resize_function__ObjectTokenArray__tokens  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ObjectTokenArray_message_members = {
  "nurse_interfaces::msg",  // message namespace
  "ObjectTokenArray",  // message name
  2,  // number of fields
  sizeof(nurse_interfaces::msg::ObjectTokenArray),
  ObjectTokenArray_message_member_array,  // message members
  ObjectTokenArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ObjectTokenArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ObjectTokenArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ObjectTokenArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace nurse_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<nurse_interfaces::msg::ObjectTokenArray>()
{
  return &::nurse_interfaces::msg::rosidl_typesupport_introspection_cpp::ObjectTokenArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, nurse_interfaces, msg, ObjectTokenArray)() {
  return &::nurse_interfaces::msg::rosidl_typesupport_introspection_cpp::ObjectTokenArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
