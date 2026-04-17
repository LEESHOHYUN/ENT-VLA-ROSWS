
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_Goal() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_Goal__init(msg: *mut Gripper_Goal) -> bool;
    fn gripper_interfaces__action__Gripper_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_Goal>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_Goal>);
    fn gripper_interfaces__action__Gripper_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_Goal>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_pose: i32,

}



impl Default for Gripper_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_Goal__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_Goal() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_Result() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_Result__init(msg: *mut Gripper_Result) -> bool;
    fn gripper_interfaces__action__Gripper_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_Result>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_Result>);
    fn gripper_interfaces__action__Gripper_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_Result>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub final_pose: i32,

}



impl Default for Gripper_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_Result__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_Result where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_Result() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_Feedback__init(msg: *mut Gripper_Feedback) -> bool;
    fn gripper_interfaces__action__Gripper_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_Feedback>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_Feedback>);
    fn gripper_interfaces__action__Gripper_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_Feedback>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_pose: i32,

}



impl Default for Gripper_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_Feedback__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_Feedback() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_FeedbackMessage__init(msg: *mut Gripper_FeedbackMessage) -> bool;
    fn gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_FeedbackMessage>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_FeedbackMessage>);
    fn gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_FeedbackMessage>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Gripper_Feedback,

}



impl Default for Gripper_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_FeedbackMessage() }
  }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_SendGoal_Request__init(msg: *mut Gripper_SendGoal_Request) -> bool;
    fn gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_SendGoal_Request>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_SendGoal_Request>);
    fn gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_SendGoal_Request>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Gripper_Goal,

}



impl Default for Gripper_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_SendGoal_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_SendGoal_Response__init(msg: *mut Gripper_SendGoal_Response) -> bool;
    fn gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_SendGoal_Response>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_SendGoal_Response>);
    fn gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_SendGoal_Response>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Gripper_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_SendGoal_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_GetResult_Request__init(msg: *mut Gripper_GetResult_Request) -> bool;
    fn gripper_interfaces__action__Gripper_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_GetResult_Request>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_GetResult_Request>);
    fn gripper_interfaces__action__Gripper_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_GetResult_Request>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Gripper_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_GetResult_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__action__Gripper_GetResult_Response__init(msg: *mut Gripper_GetResult_Response) -> bool;
    fn gripper_interfaces__action__Gripper_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Gripper_GetResult_Response>, size: usize) -> bool;
    fn gripper_interfaces__action__Gripper_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Gripper_GetResult_Response>);
    fn gripper_interfaces__action__Gripper_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Gripper_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Gripper_GetResult_Response>) -> bool;
}

// Corresponds to gripper_interfaces__action__Gripper_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Gripper_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Gripper_Result,

}



impl Default for Gripper_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__action__Gripper_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__action__Gripper_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Gripper_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__action__Gripper_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Gripper_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Gripper_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/action/Gripper_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__action__Gripper_GetResult_Response() }
  }
}






#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__action__Gripper_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__action__Gripper_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Gripper_SendGoal;

impl rosidl_runtime_rs::Service for Gripper_SendGoal {
    type Request = Gripper_SendGoal_Request;
    type Response = Gripper_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__action__Gripper_SendGoal() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__action__Gripper_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__action__Gripper_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Gripper_GetResult;

impl rosidl_runtime_rs::Service for Gripper_GetResult {
    type Request = Gripper_GetResult_Request;
    type Response = Gripper_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__action__Gripper_GetResult() }
    }
}


