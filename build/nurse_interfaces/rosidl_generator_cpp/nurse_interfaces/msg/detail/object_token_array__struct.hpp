// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__STRUCT_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__STRUCT_HPP_

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
// Member 'tokens'
#include "nurse_interfaces/msg/detail/object_token__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nurse_interfaces__msg__ObjectTokenArray __attribute__((deprecated))
#else
# define DEPRECATED__nurse_interfaces__msg__ObjectTokenArray __declspec(deprecated)
#endif

namespace nurse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectTokenArray_
{
  using Type = ObjectTokenArray_<ContainerAllocator>;

  explicit ObjectTokenArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit ObjectTokenArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tokens_type =
    std::vector<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>>;
  _tokens_type tokens;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tokens(
    const std::vector<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>> & _arg)
  {
    this->tokens = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nurse_interfaces__msg__ObjectTokenArray
    std::shared_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nurse_interfaces__msg__ObjectTokenArray
    std::shared_ptr<nurse_interfaces::msg::ObjectTokenArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectTokenArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tokens != other.tokens) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectTokenArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectTokenArray_

// alias to use template instance with default allocator
using ObjectTokenArray =
  nurse_interfaces::msg::ObjectTokenArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__STRUCT_HPP_
