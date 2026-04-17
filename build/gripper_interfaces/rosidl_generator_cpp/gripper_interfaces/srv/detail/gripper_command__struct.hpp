// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gripper_interfaces:srv/GripperCommand.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__GripperCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__GripperCommand_Request __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GripperCommand_Request_
{
  using Type = GripperCommand_Request_<ContainerAllocator>;

  explicit GripperCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->value = 0;
    }
  }

  explicit GripperCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->value = 0;
    }
  }

  // field types and members
  using _command_type =
    uint8_t;
  _command_type command;
  using _value_type =
    int16_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__command(
    const uint8_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__value(
    const int16_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__GripperCommand_Request
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__GripperCommand_Request
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperCommand_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperCommand_Request_

// alias to use template instance with default allocator
using GripperCommand_Request =
  gripper_interfaces::srv::GripperCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__GripperCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__GripperCommand_Response __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GripperCommand_Response_
{
  using Type = GripperCommand_Response_<ContainerAllocator>;

  explicit GripperCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->successed = false;
    }
  }

  explicit GripperCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->successed = false;
    }
  }

  // field types and members
  using _successed_type =
    bool;
  _successed_type successed;

  // setters for named parameter idiom
  Type & set__successed(
    const bool & _arg)
  {
    this->successed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__GripperCommand_Response
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__GripperCommand_Response
    std::shared_ptr<gripper_interfaces::srv::GripperCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperCommand_Response_ & other) const
  {
    if (this->successed != other.successed) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperCommand_Response_

// alias to use template instance with default allocator
using GripperCommand_Response =
  gripper_interfaces::srv::GripperCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces

namespace gripper_interfaces
{

namespace srv
{

struct GripperCommand
{
  using Request = gripper_interfaces::srv::GripperCommand_Request;
  using Response = gripper_interfaces::srv::GripperCommand_Response;
};

}  // namespace srv

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_HPP_
