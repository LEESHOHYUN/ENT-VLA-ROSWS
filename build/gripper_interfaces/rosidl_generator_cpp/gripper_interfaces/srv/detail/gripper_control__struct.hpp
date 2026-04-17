// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__STRUCT_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__GripperControl_Request __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__GripperControl_Request __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GripperControl_Request_
{
  using Type = GripperControl_Request_<ContainerAllocator>;

  explicit GripperControl_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->control_mode = 0;
      std::fill<typename std::array<uint16_t, 3>::iterator, uint16_t>(this->pos_ctrl_param.begin(), this->pos_ctrl_param.end(), 0);
      std::fill<typename std::array<uint16_t, 3>::iterator, uint16_t>(this->vel_ctrl_param.begin(), this->vel_ctrl_param.end(), 0);
      this->custom_input = "";
      this->gripper_init = "";
      this->grasping_vel = "";
    }
  }

  explicit GripperControl_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos_ctrl_param(_alloc),
    vel_ctrl_param(_alloc),
    custom_input(_alloc),
    gripper_init(_alloc),
    grasping_vel(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->control_mode = 0;
      std::fill<typename std::array<uint16_t, 3>::iterator, uint16_t>(this->pos_ctrl_param.begin(), this->pos_ctrl_param.end(), 0);
      std::fill<typename std::array<uint16_t, 3>::iterator, uint16_t>(this->vel_ctrl_param.begin(), this->vel_ctrl_param.end(), 0);
      this->custom_input = "";
      this->gripper_init = "";
      this->grasping_vel = "";
    }
  }

  // field types and members
  using _control_mode_type =
    int8_t;
  _control_mode_type control_mode;
  using _pos_ctrl_param_type =
    std::array<uint16_t, 3>;
  _pos_ctrl_param_type pos_ctrl_param;
  using _vel_ctrl_param_type =
    std::array<uint16_t, 3>;
  _vel_ctrl_param_type vel_ctrl_param;
  using _torque_ctrl_param_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _torque_ctrl_param_type torque_ctrl_param;
  using _custom_input_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _custom_input_type custom_input;
  using _gripper_init_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gripper_init_type gripper_init;
  using _grasping_vel_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _grasping_vel_type grasping_vel;

  // setters for named parameter idiom
  Type & set__control_mode(
    const int8_t & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__pos_ctrl_param(
    const std::array<uint16_t, 3> & _arg)
  {
    this->pos_ctrl_param = _arg;
    return *this;
  }
  Type & set__vel_ctrl_param(
    const std::array<uint16_t, 3> & _arg)
  {
    this->vel_ctrl_param = _arg;
    return *this;
  }
  Type & set__torque_ctrl_param(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->torque_ctrl_param = _arg;
    return *this;
  }
  Type & set__custom_input(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->custom_input = _arg;
    return *this;
  }
  Type & set__gripper_init(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gripper_init = _arg;
    return *this;
  }
  Type & set__grasping_vel(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->grasping_vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__GripperControl_Request
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__GripperControl_Request
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperControl_Request_ & other) const
  {
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->pos_ctrl_param != other.pos_ctrl_param) {
      return false;
    }
    if (this->vel_ctrl_param != other.vel_ctrl_param) {
      return false;
    }
    if (this->torque_ctrl_param != other.torque_ctrl_param) {
      return false;
    }
    if (this->custom_input != other.custom_input) {
      return false;
    }
    if (this->gripper_init != other.gripper_init) {
      return false;
    }
    if (this->grasping_vel != other.grasping_vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperControl_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperControl_Request_

// alias to use template instance with default allocator
using GripperControl_Request =
  gripper_interfaces::srv::GripperControl_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__GripperControl_Response __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__GripperControl_Response __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GripperControl_Response_
{
  using Type = GripperControl_Response_<ContainerAllocator>;

  explicit GripperControl_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->successed = false;
    }
  }

  explicit GripperControl_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__GripperControl_Response
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__GripperControl_Response
    std::shared_ptr<gripper_interfaces::srv::GripperControl_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GripperControl_Response_ & other) const
  {
    if (this->successed != other.successed) {
      return false;
    }
    return true;
  }
  bool operator!=(const GripperControl_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GripperControl_Response_

// alias to use template instance with default allocator
using GripperControl_Response =
  gripper_interfaces::srv::GripperControl_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces

namespace gripper_interfaces
{

namespace srv
{

struct GripperControl
{
  using Request = gripper_interfaces::srv::GripperControl_Request;
  using Response = gripper_interfaces::srv::GripperControl_Response;
};

}  // namespace srv

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__STRUCT_HPP_
