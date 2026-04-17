// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__STRUCT_HPP_
#define GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__msg__GripperMsg __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__msg__GripperMsg __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GripperMsg_
{
  using Type = GripperMsg_<ContainerAllocator>;

  explicit GripperMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0;
      this->current = 0;
      this->velocity = 0;
      this->grp_pos = 0;
      this->is_motor_enable = false;
      this->is_grp_init_ongoing = false;
      this->is_pos_ongoing = false;
      this->is_vel_ongoing = false;
      this->is_tor_ongoing = false;
      this->is_grp_opening = false;
      this->is_grp_closing = false;
      this->grp_direction = false;
      this->is_object_grasp = false;
      this->is_fault_occured = false;
    }
  }

  explicit GripperMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0;
      this->current = 0;
      this->velocity = 0;
      this->grp_pos = 0;
      this->is_motor_enable = false;
      this->is_grp_init_ongoing = false;
      this->is_pos_ongoing = false;
      this->is_vel_ongoing = false;
      this->is_tor_ongoing = false;
      this->is_grp_opening = false;
      this->is_grp_closing = false;
      this->grp_direction = false;
      this->is_object_grasp = false;
      this->is_fault_occured = false;
    }
  }

  // field types and members
  using _angle_type =
    int16_t;
  _angle_type angle;
  using _current_type =
    int16_t;
  _current_type current;
  using _velocity_type =
    int16_t;
  _velocity_type velocity;
  using _grp_pos_type =
    int16_t;
  _grp_pos_type grp_pos;
  using _is_motor_enable_type =
    bool;
  _is_motor_enable_type is_motor_enable;
  using _is_grp_init_ongoing_type =
    bool;
  _is_grp_init_ongoing_type is_grp_init_ongoing;
  using _is_pos_ongoing_type =
    bool;
  _is_pos_ongoing_type is_pos_ongoing;
  using _is_vel_ongoing_type =
    bool;
  _is_vel_ongoing_type is_vel_ongoing;
  using _is_tor_ongoing_type =
    bool;
  _is_tor_ongoing_type is_tor_ongoing;
  using _is_grp_opening_type =
    bool;
  _is_grp_opening_type is_grp_opening;
  using _is_grp_closing_type =
    bool;
  _is_grp_closing_type is_grp_closing;
  using _grp_direction_type =
    bool;
  _grp_direction_type grp_direction;
  using _is_object_grasp_type =
    bool;
  _is_object_grasp_type is_object_grasp;
  using _is_fault_occured_type =
    bool;
  _is_fault_occured_type is_fault_occured;

  // setters for named parameter idiom
  Type & set__angle(
    const int16_t & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__current(
    const int16_t & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__velocity(
    const int16_t & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__grp_pos(
    const int16_t & _arg)
  {
    this->grp_pos = _arg;
    return *this;
  }
  Type & set__is_motor_enable(
    const bool & _arg)
  {
    this->is_motor_enable = _arg;
    return *this;
  }
  Type & set__is_grp_init_ongoing(
    const bool & _arg)
  {
    this->is_grp_init_ongoing = _arg;
    return *this;
  }
  Type & set__is_pos_ongoing(
    const bool & _arg)
  {
    this->is_pos_ongoing = _arg;
    return *this;
  }
  Type & set__is_vel_ongoing(
    const bool & _arg)
  {
    this->is_vel_ongoing = _arg;
    return *this;
  }
  Type & set__is_tor_ongoing(
    const bool & _arg)
  {
    this->is_tor_ongoing = _arg;
    return *this;
  }
  Type & set__is_grp_opening(
    const bool & _arg)
  {
    this->is_grp_opening = _arg;
    return *this;
  }
  Type & set__is_grp_closing(
    const bool & _arg)
  {
    this->is_grp_closing = _arg;
    return *this;
  }
  Type & set__grp_direction(
    const bool & _arg)
  {
    this->grp_direction = _arg;
    return *this;
  }
  Type & set__is_object_grasp(
    const bool & _arg)
  {
    this->is_object_grasp = _arg;
    return *this;
  }
  Type & set__is_fault_occured(
    const bool & _arg)
  {
    this->is_fault_occured = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::msg::GripperMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::msg::GripperMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::msg::GripperMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::msg::GripperMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__msg__GripperMsg
    std::shared_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__msg__GripperMsg
    std::shared_ptr<gripper_interfaces::msg::GripperMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperMsg_ & other) const
  {
    if (this->angle != other.angle) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->grp_pos != other.grp_pos) {
      return false;
    }
    if (this->is_motor_enable != other.is_motor_enable) {
      return false;
    }
    if (this->is_grp_init_ongoing != other.is_grp_init_ongoing) {
      return false;
    }
    if (this->is_pos_ongoing != other.is_pos_ongoing) {
      return false;
    }
    if (this->is_vel_ongoing != other.is_vel_ongoing) {
      return false;
    }
    if (this->is_tor_ongoing != other.is_tor_ongoing) {
      return false;
    }
    if (this->is_grp_opening != other.is_grp_opening) {
      return false;
    }
    if (this->is_grp_closing != other.is_grp_closing) {
      return false;
    }
    if (this->grp_direction != other.grp_direction) {
      return false;
    }
    if (this->is_object_grasp != other.is_object_grasp) {
      return false;
    }
    if (this->is_fault_occured != other.is_fault_occured) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperMsg_

// alias to use template instance with default allocator
using GripperMsg =
  gripper_interfaces::msg::GripperMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__STRUCT_HPP_
