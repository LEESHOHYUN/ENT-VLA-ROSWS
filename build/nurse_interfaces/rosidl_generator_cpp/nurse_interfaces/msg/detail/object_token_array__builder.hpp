// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__BUILDER_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nurse_interfaces/msg/detail/object_token_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nurse_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectTokenArray_tokens
{
public:
  explicit Init_ObjectTokenArray_tokens(::nurse_interfaces::msg::ObjectTokenArray & msg)
  : msg_(msg)
  {}
  ::nurse_interfaces::msg::ObjectTokenArray tokens(::nurse_interfaces::msg::ObjectTokenArray::_tokens_type arg)
  {
    msg_.tokens = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectTokenArray msg_;
};

class Init_ObjectTokenArray_header
{
public:
  Init_ObjectTokenArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectTokenArray_tokens header(::nurse_interfaces::msg::ObjectTokenArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObjectTokenArray_tokens(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectTokenArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nurse_interfaces::msg::ObjectTokenArray>()
{
  return nurse_interfaces::msg::builder::Init_ObjectTokenArray_header();
}

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__BUILDER_HPP_
