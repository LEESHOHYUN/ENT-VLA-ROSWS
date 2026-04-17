// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nurse_interfaces:msg/EmergencySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__STRUCT_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__STRUCT_HPP_

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
# define DEPRECATED__nurse_interfaces__msg__EmergencySignal __attribute__((deprecated))
#else
# define DEPRECATED__nurse_interfaces__msg__EmergencySignal __declspec(deprecated)
#endif

namespace nurse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EmergencySignal_
{
  using Type = EmergencySignal_<ContainerAllocator>;

  explicit EmergencySignal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->confidence = 0.0f;
      this->detail = "";
    }
  }

  explicit EmergencySignal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    detail(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->confidence = 0.0f;
      this->detail = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _status_type =
    uint8_t;
  _status_type status;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _detail_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _detail_type detail;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__status(
    const uint8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__detail(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->detail = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t NORMAL =
    0u;
  static constexpr uint8_t BLEEDING =
    1u;
  static constexpr uint8_t CONTAMINATION =
    2u;
  static constexpr uint8_t PHASE_COMPLETE =
    3u;
  static constexpr uint8_t UNKNOWN =
    255u;

  // pointer types
  using RawPtr =
    nurse_interfaces::msg::EmergencySignal_<ContainerAllocator> *;
  using ConstRawPtr =
    const nurse_interfaces::msg::EmergencySignal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::EmergencySignal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::EmergencySignal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nurse_interfaces__msg__EmergencySignal
    std::shared_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nurse_interfaces__msg__EmergencySignal
    std::shared_ptr<nurse_interfaces::msg::EmergencySignal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EmergencySignal_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->detail != other.detail) {
      return false;
    }
    return true;
  }
  bool operator!=(const EmergencySignal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EmergencySignal_

// alias to use template instance with default allocator
using EmergencySignal =
  nurse_interfaces::msg::EmergencySignal_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EmergencySignal_<ContainerAllocator>::NORMAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EmergencySignal_<ContainerAllocator>::BLEEDING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EmergencySignal_<ContainerAllocator>::CONTAMINATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EmergencySignal_<ContainerAllocator>::PHASE_COMPLETE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t EmergencySignal_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__STRUCT_HPP_
