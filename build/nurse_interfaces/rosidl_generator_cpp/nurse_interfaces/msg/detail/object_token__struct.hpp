// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__STRUCT_HPP_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__nurse_interfaces__msg__ObjectToken __attribute__((deprecated))
#else
# define DEPRECATED__nurse_interfaces__msg__ObjectToken __declspec(deprecated)
#endif

namespace nurse_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectToken_
{
  using Type = ObjectToken_<ContainerAllocator>;

  explicit ObjectToken_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_id = "";
      this->object_class = "";
      std::fill<typename std::array<float, 4>::iterator, float>(this->bbox.begin(), this->bbox.end(), 0.0f);
      this->confidence = 0.0f;
      this->visible = false;
    }
  }

  explicit ObjectToken_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object_id(_alloc),
    object_class(_alloc),
    bbox(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_id = "";
      this->object_class = "";
      std::fill<typename std::array<float, 4>::iterator, float>(this->bbox.begin(), this->bbox.end(), 0.0f);
      this->confidence = 0.0f;
      this->visible = false;
    }
  }

  // field types and members
  using _object_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_id_type object_id;
  using _object_class_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_class_type object_class;
  using _bbox_type =
    std::array<float, 4>;
  _bbox_type bbox;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _visible_type =
    bool;
  _visible_type visible;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;

  // setters for named parameter idiom
  Type & set__object_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_id = _arg;
    return *this;
  }
  Type & set__object_class(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_class = _arg;
    return *this;
  }
  Type & set__bbox(
    const std::array<float, 4> & _arg)
  {
    this->bbox = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__visible(
    const bool & _arg)
  {
    this->visible = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nurse_interfaces::msg::ObjectToken_<ContainerAllocator> *;
  using ConstRawPtr =
    const nurse_interfaces::msg::ObjectToken_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nurse_interfaces__msg__ObjectToken
    std::shared_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nurse_interfaces__msg__ObjectToken
    std::shared_ptr<nurse_interfaces::msg::ObjectToken_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectToken_ & other) const
  {
    if (this->object_id != other.object_id) {
      return false;
    }
    if (this->object_class != other.object_class) {
      return false;
    }
    if (this->bbox != other.bbox) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->visible != other.visible) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectToken_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectToken_

// alias to use template instance with default allocator
using ObjectToken =
  nurse_interfaces::msg::ObjectToken_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nurse_interfaces

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__STRUCT_HPP_
