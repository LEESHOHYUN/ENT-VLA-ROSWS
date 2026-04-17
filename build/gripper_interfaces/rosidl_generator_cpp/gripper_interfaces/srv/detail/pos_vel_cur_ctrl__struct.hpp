// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gripper_interfaces:srv/PosVelCurCtrl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__STRUCT_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Request __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Request __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PosVelCurCtrl_Request_
{
  using Type = PosVelCurCtrl_Request_<ContainerAllocator>;

  explicit PosVelCurCtrl_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0;
      this->velocity = 0;
      this->acceleration = 0;
      this->current = 0;
      this->duration = 0;
    }
  }

  explicit PosVelCurCtrl_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0;
      this->velocity = 0;
      this->acceleration = 0;
      this->current = 0;
      this->duration = 0;
    }
  }

  // field types and members
  using _position_type =
    int16_t;
  _position_type position;
  using _velocity_type =
    int16_t;
  _velocity_type velocity;
  using _acceleration_type =
    int16_t;
  _acceleration_type acceleration;
  using _current_type =
    int16_t;
  _current_type current;
  using _duration_type =
    uint16_t;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__position(
    const int16_t & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const int16_t & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__acceleration(
    const int16_t & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__current(
    const int16_t & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__duration(
    const uint16_t & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Request
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Request
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PosVelCurCtrl_Request_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const PosVelCurCtrl_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PosVelCurCtrl_Request_

// alias to use template instance with default allocator
using PosVelCurCtrl_Request =
  gripper_interfaces::srv::PosVelCurCtrl_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Response __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Response __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PosVelCurCtrl_Response_
{
  using Type = PosVelCurCtrl_Response_<ContainerAllocator>;

  explicit PosVelCurCtrl_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->successed = false;
    }
  }

  explicit PosVelCurCtrl_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Response
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__PosVelCurCtrl_Response
    std::shared_ptr<gripper_interfaces::srv::PosVelCurCtrl_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PosVelCurCtrl_Response_ & other) const
  {
    if (this->successed != other.successed) {
      return false;
    }
    return true;
  }
  bool operator!=(const PosVelCurCtrl_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PosVelCurCtrl_Response_

// alias to use template instance with default allocator
using PosVelCurCtrl_Response =
  gripper_interfaces::srv::PosVelCurCtrl_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces

namespace gripper_interfaces
{

namespace srv
{

struct PosVelCurCtrl
{
  using Request = gripper_interfaces::srv::PosVelCurCtrl_Request;
  using Response = gripper_interfaces::srv::PosVelCurCtrl_Response;
};

}  // namespace srv

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__STRUCT_HPP_
