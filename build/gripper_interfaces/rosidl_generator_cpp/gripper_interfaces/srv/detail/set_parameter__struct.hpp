// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gripper_interfaces:srv/SetParameter.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__SET_PARAMETER__STRUCT_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__SET_PARAMETER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__SetParameter_Request __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__SetParameter_Request __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetParameter_Request_
{
  using Type = SetParameter_Request_<ContainerAllocator>;

  explicit SetParameter_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_max = 0;
      this->acc_max = 0;
    }
  }

  explicit SetParameter_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vel_max = 0;
      this->acc_max = 0;
    }
  }

  // field types and members
  using _vel_max_type =
    uint16_t;
  _vel_max_type vel_max;
  using _acc_max_type =
    uint16_t;
  _acc_max_type acc_max;

  // setters for named parameter idiom
  Type & set__vel_max(
    const uint16_t & _arg)
  {
    this->vel_max = _arg;
    return *this;
  }
  Type & set__acc_max(
    const uint16_t & _arg)
  {
    this->acc_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__SetParameter_Request
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__SetParameter_Request
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParameter_Request_ & other) const
  {
    if (this->vel_max != other.vel_max) {
      return false;
    }
    if (this->acc_max != other.acc_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParameter_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParameter_Request_

// alias to use template instance with default allocator
using SetParameter_Request =
  gripper_interfaces::srv::SetParameter_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__SetParameter_Response __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__SetParameter_Response __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetParameter_Response_
{
  using Type = SetParameter_Response_<ContainerAllocator>;

  explicit SetParameter_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->successed = false;
    }
  }

  explicit SetParameter_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__SetParameter_Response
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__SetParameter_Response
    std::shared_ptr<gripper_interfaces::srv::SetParameter_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParameter_Response_ & other) const
  {
    if (this->successed != other.successed) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParameter_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParameter_Response_

// alias to use template instance with default allocator
using SetParameter_Response =
  gripper_interfaces::srv::SetParameter_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces

namespace gripper_interfaces
{

namespace srv
{

struct SetParameter
{
  using Request = gripper_interfaces::srv::SetParameter_Request;
  using Response = gripper_interfaces::srv::SetParameter_Response;
};

}  // namespace srv

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__SET_PARAMETER__STRUCT_HPP_
