// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nurse_interfaces:msg/ToolPrompt.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__STRUCT_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nurse_interfaces__msg__ToolPrompt __attribute__((deprecated))
#else
# define DEPRECATED__nurse_interfaces__msg__ToolPrompt __declspec(deprecated)
#endif

namespace nurse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ToolPrompt_
{
  using Type = ToolPrompt_<ContainerAllocator>;

  explicit ToolPrompt_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tool_name = "";
      this->language_prompt = "";
      this->confidence = 0.0f;
      this->phase = "";
    }
  }

  explicit ToolPrompt_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    tool_name(_alloc),
    language_prompt(_alloc),
    phase(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tool_name = "";
      this->language_prompt = "";
      this->confidence = 0.0f;
      this->phase = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tool_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tool_name_type tool_name;
  using _language_prompt_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _language_prompt_type language_prompt;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _phase_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _phase_type phase;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tool_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tool_name = _arg;
    return *this;
  }
  Type & set__language_prompt(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->language_prompt = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__phase(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->phase = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nurse_interfaces::msg::ToolPrompt_<ContainerAllocator> *;
  using ConstRawPtr =
    const nurse_interfaces::msg::ToolPrompt_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::ToolPrompt_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::ToolPrompt_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nurse_interfaces__msg__ToolPrompt
    std::shared_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nurse_interfaces__msg__ToolPrompt
    std::shared_ptr<nurse_interfaces::msg::ToolPrompt_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ToolPrompt_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tool_name != other.tool_name) {
      return false;
    }
    if (this->language_prompt != other.language_prompt) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->phase != other.phase) {
      return false;
    }
    return true;
  }
  bool operator!=(const ToolPrompt_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ToolPrompt_

// alias to use template instance with default allocator
using ToolPrompt =
  nurse_interfaces::msg::ToolPrompt_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__STRUCT_HPP_
