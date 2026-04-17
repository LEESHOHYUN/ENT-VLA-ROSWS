// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur_robot_manager_interfaces:action/RobotTask.idl
// generated code does not contain a copyright notice

#ifndef UR_ROBOT_MANAGER_INTERFACES__ACTION__DETAIL__ROBOT_TASK__BUILDER_HPP_
#define UR_ROBOT_MANAGER_INTERFACES__ACTION__DETAIL__ROBOT_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur_robot_manager_interfaces/action/detail/robot_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_Goal_tool_type
{
public:
  explicit Init_RobotTask_Goal_tool_type(::ur_robot_manager_interfaces::action::RobotTask_Goal & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_Goal tool_type(::ur_robot_manager_interfaces::action::RobotTask_Goal::_tool_type_type arg)
  {
    msg_.tool_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Goal msg_;
};

class Init_RobotTask_Goal_positions
{
public:
  explicit Init_RobotTask_Goal_positions(::ur_robot_manager_interfaces::action::RobotTask_Goal & msg)
  : msg_(msg)
  {}
  Init_RobotTask_Goal_tool_type positions(::ur_robot_manager_interfaces::action::RobotTask_Goal::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return Init_RobotTask_Goal_tool_type(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Goal msg_;
};

class Init_RobotTask_Goal_task_id
{
public:
  Init_RobotTask_Goal_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_Goal_positions task_id(::ur_robot_manager_interfaces::action::RobotTask_Goal::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_RobotTask_Goal_positions(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_Goal>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_Goal_task_id();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_Result_error_message
{
public:
  explicit Init_RobotTask_Result_error_message(::ur_robot_manager_interfaces::action::RobotTask_Result & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_Result error_message(::ur_robot_manager_interfaces::action::RobotTask_Result::_error_message_type arg)
  {
    msg_.error_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Result msg_;
};

class Init_RobotTask_Result_success
{
public:
  Init_RobotTask_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_Result_error_message success(::ur_robot_manager_interfaces::action::RobotTask_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_RobotTask_Result_error_message(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_Result>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_Result_success();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_Feedback_completion_percentage
{
public:
  explicit Init_RobotTask_Feedback_completion_percentage(::ur_robot_manager_interfaces::action::RobotTask_Feedback & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_Feedback completion_percentage(::ur_robot_manager_interfaces::action::RobotTask_Feedback::_completion_percentage_type arg)
  {
    msg_.completion_percentage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Feedback msg_;
};

class Init_RobotTask_Feedback_status
{
public:
  Init_RobotTask_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_Feedback_completion_percentage status(::ur_robot_manager_interfaces::action::RobotTask_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotTask_Feedback_completion_percentage(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_Feedback>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_Feedback_status();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_SendGoal_Request_goal
{
public:
  explicit Init_RobotTask_SendGoal_Request_goal(::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request goal(::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request msg_;
};

class Init_RobotTask_SendGoal_Request_goal_id
{
public:
  Init_RobotTask_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_SendGoal_Request_goal goal_id(::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotTask_SendGoal_Request_goal(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Request>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_SendGoal_Request_goal_id();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_SendGoal_Response_stamp
{
public:
  explicit Init_RobotTask_SendGoal_Response_stamp(::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response stamp(::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response msg_;
};

class Init_RobotTask_SendGoal_Response_accepted
{
public:
  Init_RobotTask_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_SendGoal_Response_stamp accepted(::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_RobotTask_SendGoal_Response_stamp(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_SendGoal_Response>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_SendGoal_Response_accepted();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_GetResult_Request_goal_id
{
public:
  Init_RobotTask_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_GetResult_Request goal_id(::ur_robot_manager_interfaces::action::RobotTask_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_GetResult_Request>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_GetResult_Request_goal_id();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_GetResult_Response_result
{
public:
  explicit Init_RobotTask_GetResult_Response_result(::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response result(::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response msg_;
};

class Init_RobotTask_GetResult_Response_status
{
public:
  Init_RobotTask_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_GetResult_Response_result status(::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_RobotTask_GetResult_Response_result(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_GetResult_Response>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_GetResult_Response_status();
}

}  // namespace ur_robot_manager_interfaces


namespace ur_robot_manager_interfaces
{

namespace action
{

namespace builder
{

class Init_RobotTask_FeedbackMessage_feedback
{
public:
  explicit Init_RobotTask_FeedbackMessage_feedback(::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage feedback(::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage msg_;
};

class Init_RobotTask_FeedbackMessage_goal_id
{
public:
  Init_RobotTask_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTask_FeedbackMessage_feedback goal_id(::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_RobotTask_FeedbackMessage_feedback(msg_);
  }

private:
  ::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur_robot_manager_interfaces::action::RobotTask_FeedbackMessage>()
{
  return ur_robot_manager_interfaces::action::builder::Init_RobotTask_FeedbackMessage_goal_id();
}

}  // namespace ur_robot_manager_interfaces

#endif  // UR_ROBOT_MANAGER_INTERFACES__ACTION__DETAIL__ROBOT_TASK__BUILDER_HPP_
