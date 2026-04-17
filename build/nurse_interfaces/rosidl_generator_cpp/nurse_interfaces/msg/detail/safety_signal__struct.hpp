// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nurse_interfaces:msg/SafetySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__STRUCT_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__STRUCT_HPP_

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
# define DEPRECATED__nurse_interfaces__msg__SafetySignal __attribute__((deprecated))
#else
# define DEPRECATED__nurse_interfaces__msg__SafetySignal __declspec(deprecated)
#endif

namespace nurse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SafetySignal_
{
  using Type = SafetySignal_<ContainerAllocator>;

  explicit SafetySignal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->decision = 0;
      this->reason = "";
    }
  }

  explicit SafetySignal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->decision = 0;
      this->reason = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _decision_type =
    uint8_t;
  _decision_type decision;
  using _reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _reason_type reason;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__decision(
    const uint8_t & _arg)
  {
    this->decision = _arg;
    return *this;
  }
  Type & set__reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->reason = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t GO =
    0u;
  static constexpr uint8_t HOLD =
    1u;
  static constexpr uint8_t ABORT =
    2u;

  // pointer types
  using RawPtr =
    nurse_interfaces::msg::SafetySignal_<ContainerAllocator> *;
  using ConstRawPtr =
    const nurse_interfaces::msg::SafetySignal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::SafetySignal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::SafetySignal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nurse_interfaces__msg__SafetySignal
    std::shared_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nurse_interfaces__msg__SafetySignal
    std::shared_ptr<nurse_interfaces::msg::SafetySignal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SafetySignal_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->decision != other.decision) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const SafetySignal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SafetySignal_

// alias to use template instance with default allocator
using SafetySignal =
  nurse_interfaces::msg::SafetySignal_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SafetySignal_<ContainerAllocator>::GO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SafetySignal_<ContainerAllocator>::HOLD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SafetySignal_<ContainerAllocator>::ABORT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__STRUCT_HPP_
