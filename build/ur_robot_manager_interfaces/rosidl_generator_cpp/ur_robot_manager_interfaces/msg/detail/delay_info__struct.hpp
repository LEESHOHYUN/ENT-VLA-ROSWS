// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ur_robot_manager_interfaces:msg/DelayInfo.idl
// generated code does not contain a copyright notice

#ifndef UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__STRUCT_HPP_
#define UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ur_robot_manager_interfaces__msg__DelayInfo __attribute__((deprecated))
#else
# define DEPRECATED__ur_robot_manager_interfaces__msg__DelayInfo __declspec(deprecated)
#endif

namespace ur_robot_manager_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DelayInfo_
{
  using Type = DelayInfo_<ContainerAllocator>;

  explicit DelayInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->delay_sec = 0.0;
    }
  }

  explicit DelayInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->delay_sec = 0.0;
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;
  using _delay_sec_type =
    double;
  _delay_sec_type delay_sec;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__delay_sec(
    const double & _arg)
  {
    this->delay_sec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ur_robot_manager_interfaces__msg__DelayInfo
    std::shared_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ur_robot_manager_interfaces__msg__DelayInfo
    std::shared_ptr<ur_robot_manager_interfaces::msg::DelayInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DelayInfo_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->delay_sec != other.delay_sec) {
      return false;
    }
    return true;
  }
  bool operator!=(const DelayInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DelayInfo_

// alias to use template instance with default allocator
using DelayInfo =
  ur_robot_manager_interfaces::msg::DelayInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ur_robot_manager_interfaces

#endif  // UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__STRUCT_HPP_
