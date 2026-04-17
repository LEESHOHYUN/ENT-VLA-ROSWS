// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:srv/PosVelCurCtrl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__BUILDER_HPP_
#define GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/srv/detail/pos_vel_cur_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_PosVelCurCtrl_Request_duration
{
public:
  explicit Init_PosVelCurCtrl_Request_duration(::gripper_interfaces::srv::PosVelCurCtrl_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::srv::PosVelCurCtrl_Request duration(::gripper_interfaces::srv::PosVelCurCtrl_Request::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::PosVelCurCtrl_Request msg_;
};

class Init_PosVelCurCtrl_Request_current
{
public:
  explicit Init_PosVelCurCtrl_Request_current(::gripper_interfaces::srv::PosVelCurCtrl_Request & msg)
  : msg_(msg)
  {}
  Init_PosVelCurCtrl_Request_duration current(::gripper_interfaces::srv::PosVelCurCtrl_Request::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_PosVelCurCtrl_Request_duration(msg_);
  }

private:
  ::gripper_interfaces::srv::PosVelCurCtrl_Request msg_;
};

class Init_PosVelCurCtrl_Request_acceleration
{
public:
  explicit Init_PosVelCurCtrl_Request_acceleration(::gripper_interfaces::srv::PosVelCurCtrl_Request & msg)
  : msg_(msg)
  {}
  Init_PosVelCurCtrl_Request_current acceleration(::gripper_interfaces::srv::PosVelCurCtrl_Request::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_PosVelCurCtrl_Request_current(msg_);
  }

private:
  ::gripper_interfaces::srv::PosVelCurCtrl_Request msg_;
};

class Init_PosVelCurCtrl_Request_velocity
{
public:
  explicit Init_PosVelCurCtrl_Request_velocity(::gripper_interfaces::srv::PosVelCurCtrl_Request & msg)
  : msg_(msg)
  {}
  Init_PosVelCurCtrl_Request_acceleration velocity(::gripper_interfaces::srv::PosVelCurCtrl_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_PosVelCurCtrl_Request_acceleration(msg_);
  }

private:
  ::gripper_interfaces::srv::PosVelCurCtrl_Request msg_;
};

class Init_PosVelCurCtrl_Request_position
{
public:
  Init_PosVelCurCtrl_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PosVelCurCtrl_Request_velocity position(::gripper_interfaces::srv::PosVelCurCtrl_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_PosVelCurCtrl_Request_velocity(msg_);
  }

private:
  ::gripper_interfaces::srv::PosVelCurCtrl_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::PosVelCurCtrl_Request>()
{
  return gripper_interfaces::srv::builder::Init_PosVelCurCtrl_Request_position();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace srv
{

namespace builder
{

class Init_PosVelCurCtrl_Response_successed
{
public:
  Init_PosVelCurCtrl_Response_successed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::srv::PosVelCurCtrl_Response successed(::gripper_interfaces::srv::PosVelCurCtrl_Response::_successed_type arg)
  {
    msg_.successed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::srv::PosVelCurCtrl_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::srv::PosVelCurCtrl_Response>()
{
  return gripper_interfaces::srv::builder::Init_PosVelCurCtrl_Response_successed();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__BUILDER_HPP_
