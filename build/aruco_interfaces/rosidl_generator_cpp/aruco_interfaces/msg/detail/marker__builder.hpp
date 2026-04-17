// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aruco_interfaces:msg/Marker.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACES__MSG__DETAIL__MARKER__BUILDER_HPP_
#define ARUCO_INTERFACES__MSG__DETAIL__MARKER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aruco_interfaces/msg/detail/marker__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aruco_interfaces
{

namespace msg
{

namespace builder
{

class Init_Marker_confidence
{
public:
  explicit Init_Marker_confidence(::aruco_interfaces::msg::Marker & msg)
  : msg_(msg)
  {}
  ::aruco_interfaces::msg::Marker confidence(::aruco_interfaces::msg::Marker::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interfaces::msg::Marker msg_;
};

class Init_Marker_pose
{
public:
  explicit Init_Marker_pose(::aruco_interfaces::msg::Marker & msg)
  : msg_(msg)
  {}
  Init_Marker_confidence pose(::aruco_interfaces::msg::Marker::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_Marker_confidence(msg_);
  }

private:
  ::aruco_interfaces::msg::Marker msg_;
};

class Init_Marker_id
{
public:
  explicit Init_Marker_id(::aruco_interfaces::msg::Marker & msg)
  : msg_(msg)
  {}
  Init_Marker_pose id(::aruco_interfaces::msg::Marker::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Marker_pose(msg_);
  }

private:
  ::aruco_interfaces::msg::Marker msg_;
};

class Init_Marker_header
{
public:
  Init_Marker_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Marker_id header(::aruco_interfaces::msg::Marker::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Marker_id(msg_);
  }

private:
  ::aruco_interfaces::msg::Marker msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interfaces::msg::Marker>()
{
  return aruco_interfaces::msg::builder::Init_Marker_header();
}

}  // namespace aruco_interfaces

#endif  // ARUCO_INTERFACES__MSG__DETAIL__MARKER__BUILDER_HPP_
