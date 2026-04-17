// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nurse_interfaces:msg/ToolPrompt.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__BUILDER_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "nurse_interfaces/msg/detail/tool_prompt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace nurse_interfaces
{

namespace msg
{

namespace builder
{

class Init_ToolPrompt_phase
{
public:
  explicit Init_ToolPrompt_phase(::nurse_interfaces::msg::ToolPrompt & msg)
  : msg_(msg)
  {}
  ::nurse_interfaces::msg::ToolPrompt phase(::nurse_interfaces::msg::ToolPrompt::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nurse_interfaces::msg::ToolPrompt msg_;
};

class Init_ToolPrompt_confidence
{
public:
  explicit Init_ToolPrompt_confidence(::nurse_interfaces::msg::ToolPrompt & msg)
  : msg_(msg)
  {}
  Init_ToolPrompt_phase confidence(::nurse_interfaces::msg::ToolPrompt::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_ToolPrompt_phase(msg_);
  }

private:
  ::nurse_interfaces::msg::ToolPrompt msg_;
};

class Init_ToolPrompt_language_prompt
{
public:
  explicit Init_ToolPrompt_language_prompt(::nurse_interfaces::msg::ToolPrompt & msg)
  : msg_(msg)
  {}
  Init_ToolPrompt_confidence language_prompt(::nurse_interfaces::msg::ToolPrompt::_language_prompt_type arg)
  {
    msg_.language_prompt = std::move(arg);
    return Init_ToolPrompt_confidence(msg_);
  }

private:
  ::nurse_interfaces::msg::ToolPrompt msg_;
};

class Init_ToolPrompt_tool_name
{
public:
  explicit Init_ToolPrompt_tool_name(::nurse_interfaces::msg::ToolPrompt & msg)
  : msg_(msg)
  {}
  Init_ToolPrompt_language_prompt tool_name(::nurse_interfaces::msg::ToolPrompt::_tool_name_type arg)
  {
    msg_.tool_name = std::move(arg);
    return Init_ToolPrompt_language_prompt(msg_);
  }

private:
  ::nurse_interfaces::msg::ToolPrompt msg_;
};

class Init_ToolPrompt_header
{
public:
  Init_ToolPrompt_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolPrompt_tool_name header(::nurse_interfaces::msg::ToolPrompt::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ToolPrompt_tool_name(msg_);
  }

private:
  ::nurse_interfaces::msg::ToolPrompt msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nurse_interfaces::msg::ToolPrompt>()
{
  return nurse_interfaces::msg::builder::Init_ToolPrompt_header();
}

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__BUILDER_HPP_
