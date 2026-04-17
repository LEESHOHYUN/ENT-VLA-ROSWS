// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gripper_interfaces:srv/ArduinoControl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__ARDUINO_CONTROL__STRUCT_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__ARDUINO_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__ArduinoControl_Request __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__ArduinoControl_Request __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArduinoControl_Request_
{
  using Type = ArduinoControl_Request_<ContainerAllocator>;

  explicit ArduinoControl_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->power = false;
      this->solenoid_valve = false;
      this->spare_1 = false;
      this->spare_2 = false;
    }
  }

  explicit ArduinoControl_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->power = false;
      this->solenoid_valve = false;
      this->spare_1 = false;
      this->spare_2 = false;
    }
  }

  // field types and members
  using _power_type =
    bool;
  _power_type power;
  using _solenoid_valve_type =
    bool;
  _solenoid_valve_type solenoid_valve;
  using _spare_1_type =
    bool;
  _spare_1_type spare_1;
  using _spare_2_type =
    bool;
  _spare_2_type spare_2;

  // setters for named parameter idiom
  Type & set__power(
    const bool & _arg)
  {
    this->power = _arg;
    return *this;
  }
  Type & set__solenoid_valve(
    const bool & _arg)
  {
    this->solenoid_valve = _arg;
    return *this;
  }
  Type & set__spare_1(
    const bool & _arg)
  {
    this->spare_1 = _arg;
    return *this;
  }
  Type & set__spare_2(
    const bool & _arg)
  {
    this->spare_2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__ArduinoControl_Request
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__ArduinoControl_Request
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArduinoControl_Request_ & other) const
  {
    if (this->power != other.power) {
      return false;
    }
    if (this->solenoid_valve != other.solenoid_valve) {
      return false;
    }
    if (this->spare_1 != other.spare_1) {
      return false;
    }
    if (this->spare_2 != other.spare_2) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArduinoControl_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArduinoControl_Request_

// alias to use template instance with default allocator
using ArduinoControl_Request =
  gripper_interfaces::srv::ArduinoControl_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces


#ifndef _WIN32
# define DEPRECATED__gripper_interfaces__srv__ArduinoControl_Response __attribute__((deprecated))
#else
# define DEPRECATED__gripper_interfaces__srv__ArduinoControl_Response __declspec(deprecated)
#endif

namespace gripper_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArduinoControl_Response_
{
  using Type = ArduinoControl_Response_<ContainerAllocator>;

  explicit ArduinoControl_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->successed = false;
    }
  }

  explicit ArduinoControl_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gripper_interfaces__srv__ArduinoControl_Response
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gripper_interfaces__srv__ArduinoControl_Response
    std::shared_ptr<gripper_interfaces::srv::ArduinoControl_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArduinoControl_Response_ & other) const
  {
    if (this->successed != other.successed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArduinoControl_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArduinoControl_Response_

// alias to use template instance with default allocator
using ArduinoControl_Response =
  gripper_interfaces::srv::ArduinoControl_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace gripper_interfaces

namespace gripper_interfaces
{

namespace srv
{

struct ArduinoControl
{
  using Request = gripper_interfaces::srv::ArduinoControl_Request;
  using Response = gripper_interfaces::srv::ArduinoControl_Response;
};

}  // namespace srv

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__ARDUINO_CONTROL__STRUCT_HPP_
