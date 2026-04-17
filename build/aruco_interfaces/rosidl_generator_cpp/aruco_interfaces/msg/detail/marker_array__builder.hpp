// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from aruco_interfaces:msg/MarkerArray.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACES__MSG__DETAIL__MARKER_ARRAY__BUILDER_HPP_
#define ARUCO_INTERFACES__MSG__DETAIL__MARKER_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "aruco_interfaces/msg/detail/marker_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace aruco_interfaces
{

namespace msg
{

namespace builder
{

class Init_MarkerArray_markers
{
public:
  explicit Init_MarkerArray_markers(::aruco_interfaces::msg::MarkerArray & msg)
  : msg_(msg)
  {}
  ::aruco_interfaces::msg::MarkerArray markers(::aruco_interfaces::msg::MarkerArray::_markers_type arg)
  {
    msg_.markers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::aruco_interfaces::msg::MarkerArray msg_;
};

class Init_MarkerArray_header
{
public:
  Init_MarkerArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MarkerArray_markers header(::aruco_interfaces::msg::MarkerArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MarkerArray_markers(msg_);
  }

private:
  ::aruco_interfaces::msg::MarkerArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::aruco_interfaces::msg::MarkerArray>()
{
  return aruco_interfaces::msg::builder::Init_MarkerArray_header();
}

}  // namespace aruco_interfaces

#endif  // ARUCO_INTERFACES__MSG__DETAIL__MARKER_ARRAY__BUILDER_HPP_
