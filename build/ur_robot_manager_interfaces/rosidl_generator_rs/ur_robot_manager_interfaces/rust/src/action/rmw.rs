
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_Goal() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_Goal__init(msg: *mut RobotTask_Goal) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Goal>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Goal>);
    fn ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Goal>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub task_id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub positions: rosidl_runtime_rs::Sequence<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tool_type: i32,

}



impl Default for RobotTask_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_Goal__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_Goal() }
  }
}


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_Result() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_Result__init(msg: *mut RobotTask_Result) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Result>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Result>);
    fn ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Result>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error_message: rosidl_runtime_rs::String,

}



impl Default for RobotTask_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_Result__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_Result where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_Result() }
  }
}


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_Feedback__init(msg: *mut RobotTask_Feedback) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Feedback>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Feedback>);
    fn ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_Feedback>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub completion_percentage: f32,

}



impl Default for RobotTask_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_Feedback__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_Feedback() }
  }
}


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init(msg: *mut RobotTask_FeedbackMessage) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_FeedbackMessage>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_FeedbackMessage>);
    fn ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_FeedbackMessage>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::RobotTask_Feedback,

}



impl Default for RobotTask_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage() }
  }
}




#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init(msg: *mut RobotTask_SendGoal_Request) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Request>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Request>);
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Request>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::RobotTask_Goal,

}



impl Default for RobotTask_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request() }
  }
}


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init(msg: *mut RobotTask_SendGoal_Response) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Response>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Response>);
    fn ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_SendGoal_Response>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for RobotTask_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response() }
  }
}


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init(msg: *mut RobotTask_GetResult_Request) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_GetResult_Request>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_GetResult_Request>);
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_GetResult_Request>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for RobotTask_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_GetResult_Request() }
  }
}


#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "ur_robot_manager_interfaces__rosidl_generator_c")]
extern "C" {
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init(msg: *mut RobotTask_GetResult_Response) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_GetResult_Response>, size: usize) -> bool;
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotTask_GetResult_Response>);
    fn ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotTask_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotTask_GetResult_Response>) -> bool;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotTask_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::RobotTask_Result,

}



impl Default for RobotTask_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotTask_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotTask_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotTask_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ur_robot_manager_interfaces/action/RobotTask_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_GetResult_Response() }
  }
}






#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct RobotTask_SendGoal;

impl rosidl_runtime_rs::Service for RobotTask_SendGoal {
    type Request = RobotTask_SendGoal_Request;
    type Response = RobotTask_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_SendGoal() }
    }
}




#[link(name = "ur_robot_manager_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to ur_robot_manager_interfaces__action__RobotTask_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct RobotTask_GetResult;

impl rosidl_runtime_rs::Service for RobotTask_GetResult {
    type Request = RobotTask_GetResult_Request;
    type Response = RobotTask_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur_robot_manager_interfaces__action__RobotTask_GetResult() }
    }
}


