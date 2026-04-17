// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gripper_interfaces:action/Gripper.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__ACTION__DETAIL__GRIPPER__BUILDER_HPP_
#define GRIPPER_INTERFACES__ACTION__DETAIL__GRIPPER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gripper_interfaces/action/detail/gripper__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_Goal_goal_pose
{
public:
  Init_Gripper_Goal_goal_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::action::Gripper_Goal goal_pose(::gripper_interfaces::action::Gripper_Goal::_goal_pose_type arg)
  {
    msg_.goal_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_Goal>()
{
  return gripper_interfaces::action::builder::Init_Gripper_Goal_goal_pose();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_Result_final_pose
{
public:
  Init_Gripper_Result_final_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::action::Gripper_Result final_pose(::gripper_interfaces::action::Gripper_Result::_final_pose_type arg)
  {
    msg_.final_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_Result>()
{
  return gripper_interfaces::action::builder::Init_Gripper_Result_final_pose();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_Feedback_current_pose
{
public:
  Init_Gripper_Feedback_current_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::action::Gripper_Feedback current_pose(::gripper_interfaces::action::Gripper_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_Feedback>()
{
  return gripper_interfaces::action::builder::Init_Gripper_Feedback_current_pose();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_SendGoal_Request_goal
{
public:
  explicit Init_Gripper_SendGoal_Request_goal(::gripper_interfaces::action::Gripper_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::action::Gripper_SendGoal_Request goal(::gripper_interfaces::action::Gripper_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_SendGoal_Request msg_;
};

class Init_Gripper_SendGoal_Request_goal_id
{
public:
  Init_Gripper_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gripper_SendGoal_Request_goal goal_id(::gripper_interfaces::action::Gripper_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Gripper_SendGoal_Request_goal(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_SendGoal_Request>()
{
  return gripper_interfaces::action::builder::Init_Gripper_SendGoal_Request_goal_id();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_SendGoal_Response_stamp
{
public:
  explicit Init_Gripper_SendGoal_Response_stamp(::gripper_interfaces::action::Gripper_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::action::Gripper_SendGoal_Response stamp(::gripper_interfaces::action::Gripper_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_SendGoal_Response msg_;
};

class Init_Gripper_SendGoal_Response_accepted
{
public:
  Init_Gripper_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gripper_SendGoal_Response_stamp accepted(::gripper_interfaces::action::Gripper_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Gripper_SendGoal_Response_stamp(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_SendGoal_Response>()
{
  return gripper_interfaces::action::builder::Init_Gripper_SendGoal_Response_accepted();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_GetResult_Request_goal_id
{
public:
  Init_Gripper_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gripper_interfaces::action::Gripper_GetResult_Request goal_id(::gripper_interfaces::action::Gripper_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_GetResult_Request>()
{
  return gripper_interfaces::action::builder::Init_Gripper_GetResult_Request_goal_id();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_GetResult_Response_result
{
public:
  explicit Init_Gripper_GetResult_Response_result(::gripper_interfaces::action::Gripper_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::action::Gripper_GetResult_Response result(::gripper_interfaces::action::Gripper_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_GetResult_Response msg_;
};

class Init_Gripper_GetResult_Response_status
{
public:
  Init_Gripper_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gripper_GetResult_Response_result status(::gripper_interfaces::action::Gripper_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Gripper_GetResult_Response_result(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_GetResult_Response>()
{
  return gripper_interfaces::action::builder::Init_Gripper_GetResult_Response_status();
}

}  // namespace gripper_interfaces


namespace gripper_interfaces
{

namespace action
{

namespace builder
{

class Init_Gripper_FeedbackMessage_feedback
{
public:
  explicit Init_Gripper_FeedbackMessage_feedback(::gripper_interfaces::action::Gripper_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::gripper_interfaces::action::Gripper_FeedbackMessage feedback(::gripper_interfaces::action::Gripper_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_FeedbackMessage msg_;
};

class Init_Gripper_FeedbackMessage_goal_id
{
public:
  Init_Gripper_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gripper_FeedbackMessage_feedback goal_id(::gripper_interfaces::action::Gripper_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Gripper_FeedbackMessage_feedback(msg_);
  }

private:
  ::gripper_interfaces::action::Gripper_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::gripper_interfaces::action::Gripper_FeedbackMessage>()
{
  return gripper_interfaces::action::builder::Init_Gripper_FeedbackMessage_goal_id();
}

}  // namespace gripper_interfaces

#endif  // GRIPPER_INTERFACES__ACTION__DETAIL__GRIPPER__BUILDER_HPP_
