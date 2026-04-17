// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__BUILDER_HPP_
#define GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/msg/detail/gripper_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace msg
{

namespace builder
{

class Init_GripperMsg_is_fault_occured
{
public:
  explicit Init_GripperMsg_is_fault_occured(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::msg::GripperMsg is_fault_occured(::gripper_interfaces::msg::GripperMsg::_is_fault_occured_type arg)
  {
    msg_.is_fault_occured = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_object_grasp
{
public:
  explicit Init_GripperMsg_is_object_grasp(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_fault_occured is_object_grasp(::gripper_interfaces::msg::GripperMsg::_is_object_grasp_type arg)
  {
    msg_.is_object_grasp = std::move(arg);
    return Init_GripperMsg_is_fault_occured(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_grp_direction
{
public:
  explicit Init_GripperMsg_grp_direction(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_object_grasp grp_direction(::gripper_interfaces::msg::GripperMsg::_grp_direction_type arg)
  {
    msg_.grp_direction = std::move(arg);
    return Init_GripperMsg_is_object_grasp(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_grp_closing
{
public:
  explicit Init_GripperMsg_is_grp_closing(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_grp_direction is_grp_closing(::gripper_interfaces::msg::GripperMsg::_is_grp_closing_type arg)
  {
    msg_.is_grp_closing = std::move(arg);
    return Init_GripperMsg_grp_direction(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_grp_opening
{
public:
  explicit Init_GripperMsg_is_grp_opening(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_grp_closing is_grp_opening(::gripper_interfaces::msg::GripperMsg::_is_grp_opening_type arg)
  {
    msg_.is_grp_opening = std::move(arg);
    return Init_GripperMsg_is_grp_closing(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_tor_ongoing
{
public:
  explicit Init_GripperMsg_is_tor_ongoing(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_grp_opening is_tor_ongoing(::gripper_interfaces::msg::GripperMsg::_is_tor_ongoing_type arg)
  {
    msg_.is_tor_ongoing = std::move(arg);
    return Init_GripperMsg_is_grp_opening(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_vel_ongoing
{
public:
  explicit Init_GripperMsg_is_vel_ongoing(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_tor_ongoing is_vel_ongoing(::gripper_interfaces::msg::GripperMsg::_is_vel_ongoing_type arg)
  {
    msg_.is_vel_ongoing = std::move(arg);
    return Init_GripperMsg_is_tor_ongoing(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_pos_ongoing
{
public:
  explicit Init_GripperMsg_is_pos_ongoing(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_vel_ongoing is_pos_ongoing(::gripper_interfaces::msg::GripperMsg::_is_pos_ongoing_type arg)
  {
    msg_.is_pos_ongoing = std::move(arg);
    return Init_GripperMsg_is_vel_ongoing(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_grp_init_ongoing
{
public:
  explicit Init_GripperMsg_is_grp_init_ongoing(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_pos_ongoing is_grp_init_ongoing(::gripper_interfaces::msg::GripperMsg::_is_grp_init_ongoing_type arg)
  {
    msg_.is_grp_init_ongoing = std::move(arg);
    return Init_GripperMsg_is_pos_ongoing(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_is_motor_enable
{
public:
  explicit Init_GripperMsg_is_motor_enable(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_grp_init_ongoing is_motor_enable(::gripper_interfaces::msg::GripperMsg::_is_motor_enable_type arg)
  {
    msg_.is_motor_enable = std::move(arg);
    return Init_GripperMsg_is_grp_init_ongoing(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_grp_pos
{
public:
  explicit Init_GripperMsg_grp_pos(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_is_motor_enable grp_pos(::gripper_interfaces::msg::GripperMsg::_grp_pos_type arg)
  {
    msg_.grp_pos = std::move(arg);
    return Init_GripperMsg_is_motor_enable(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_velocity
{
public:
  explicit Init_GripperMsg_velocity(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_grp_pos velocity(::gripper_interfaces::msg::GripperMsg::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_GripperMsg_grp_pos(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_current
{
public:
  explicit Init_GripperMsg_current(::gripper_interfaces::msg::GripperMsg & msg)
  : msg_(msg)
  {}
  Init_GripperMsg_velocity current(::gripper_interfaces::msg::GripperMsg::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_GripperMsg_velocity(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

class Init_GripperMsg_angle
{
public:
  Init_GripperMsg_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperMsg_current angle(::gripper_interfaces::msg::GripperMsg::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_GripperMsg_current(msg_);
  }

private:
  ::gripper_interfaces::msg::GripperMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::msg::GripperMsg>()
{
  return gripper_interfaces::msg::builder::Init_GripperMsg_angle();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__BUILDER_HPP_
