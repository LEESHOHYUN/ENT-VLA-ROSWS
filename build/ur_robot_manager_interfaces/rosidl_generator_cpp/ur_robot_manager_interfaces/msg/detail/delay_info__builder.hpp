// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur_robot_manager_interfaces:msg/DelayInfo.idl
// generated code does not contain a copyright notice

#ifndef UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__BUILDER_HPP_
#define UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur_robot_manager_interfaces/msg/detail/delay_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur_robot_manager_interfaces
{

namespace msg
{

namespace builder
{

class Init_DelayInfo_delay_sec
{
public:
  explicit Init_DelayInfo_delay_sec(::ur_robot_manager_interfaces::msg::DelayInfo & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::msg::DelayInfo delay_sec(::ur_robot_manager_interfaces::msg::DelayInfo::_delay_sec_type arg)
  {
    msg_.delay_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::msg::DelayInfo msg_;
};

class Init_DelayInfo_command
{
public:
  Init_DelayInfo_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DelayInfo_delay_sec command(::ur_robot_manager_interfaces::msg::DelayInfo::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_DelayInfo_delay_sec(msg_);
  }

private:
  ::ur_robot_manager_interfaces::msg::DelayInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::msg::DelayInfo>()
{
  return ur_robot_manager_interfaces::msg::builder::Init_DelayInfo_command();
}

}  // namespace ur_robot_manager_interfaces

#endif  // UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__BUILDER_HPP_
