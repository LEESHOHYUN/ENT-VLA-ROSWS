// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__BUILDER_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nurse_interfaces/msg/detail/object_token__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nurse_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectToken_position
{
public:
  explicit Init_ObjectToken_position(::nurse_interfaces::msg::ObjectToken & msg)
  : msg_(msg)
  {}
  ::nurse_interfaces::msg::ObjectToken position(::nurse_interfaces::msg::ObjectToken::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectToken msg_;
};

class Init_ObjectToken_visible
{
public:
  explicit Init_ObjectToken_visible(::nurse_interfaces::msg::ObjectToken & msg)
  : msg_(msg)
  {}
  Init_ObjectToken_position visible(::nurse_interfaces::msg::ObjectToken::_visible_type arg)
  {
    msg_.visible = std::move(arg);
    return Init_ObjectToken_position(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectToken msg_;
};

class Init_ObjectToken_confidence
{
public:
  explicit Init_ObjectToken_confidence(::nurse_interfaces::msg::ObjectToken & msg)
  : msg_(msg)
  {}
  Init_ObjectToken_visible confidence(::nurse_interfaces::msg::ObjectToken::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_ObjectToken_visible(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectToken msg_;
};

class Init_ObjectToken_bbox
{
public:
  explicit Init_ObjectToken_bbox(::nurse_interfaces::msg::ObjectToken & msg)
  : msg_(msg)
  {}
  Init_ObjectToken_confidence bbox(::nurse_interfaces::msg::ObjectToken::_bbox_type arg)
  {
    msg_.bbox = std::move(arg);
    return Init_ObjectToken_confidence(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectToken msg_;
};

class Init_ObjectToken_object_class
{
public:
  explicit Init_ObjectToken_object_class(::nurse_interfaces::msg::ObjectToken & msg)
  : msg_(msg)
  {}
  Init_ObjectToken_bbox object_class(::nurse_interfaces::msg::ObjectToken::_object_class_type arg)
  {
    msg_.object_class = std::move(arg);
    return Init_ObjectToken_bbox(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectToken msg_;
};

class Init_ObjectToken_object_id
{
public:
  Init_ObjectToken_object_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectToken_object_class object_id(::nurse_interfaces::msg::ObjectToken::_object_id_type arg)
  {
    msg_.object_id = std::move(arg);
    return Init_ObjectToken_object_class(msg_);
  }

private:
  ::nurse_interfaces::msg::ObjectToken msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nurse_interfaces::msg::ObjectToken>()
{
  return nurse_interfaces::msg::builder::Init_ObjectToken_object_id();
}

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__BUILDER_HPP_
