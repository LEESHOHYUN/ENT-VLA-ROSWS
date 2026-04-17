#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SlaveChange_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__SlaveChange_Request__init(msg: *mut SlaveChange_Request) -> bool;
    fn gripper_interfaces__srv__SlaveChange_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SlaveChange_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__SlaveChange_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SlaveChange_Request>);
    fn gripper_interfaces__srv__SlaveChange_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SlaveChange_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SlaveChange_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__SlaveChange_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SlaveChange_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub slave_address: u8,

}



impl Default for SlaveChange_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__SlaveChange_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__SlaveChange_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SlaveChange_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SlaveChange_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SlaveChange_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SlaveChange_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SlaveChange_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SlaveChange_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/SlaveChange_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SlaveChange_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SlaveChange_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__SlaveChange_Response__init(msg: *mut SlaveChange_Response) -> bool;
    fn gripper_interfaces__srv__SlaveChange_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SlaveChange_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__SlaveChange_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SlaveChange_Response>);
    fn gripper_interfaces__srv__SlaveChange_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SlaveChange_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SlaveChange_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__SlaveChange_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SlaveChange_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for SlaveChange_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__SlaveChange_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__SlaveChange_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SlaveChange_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SlaveChange_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SlaveChange_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SlaveChange_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SlaveChange_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SlaveChange_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/SlaveChange_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SlaveChange_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__PosVelCurCtrl_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__PosVelCurCtrl_Request__init(msg: *mut PosVelCurCtrl_Request) -> bool;
    fn gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PosVelCurCtrl_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PosVelCurCtrl_Request>);
    fn gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PosVelCurCtrl_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<PosVelCurCtrl_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__PosVelCurCtrl_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PosVelCurCtrl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub position: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub acceleration: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration: u16,

}



impl Default for PosVelCurCtrl_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__PosVelCurCtrl_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__PosVelCurCtrl_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PosVelCurCtrl_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PosVelCurCtrl_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PosVelCurCtrl_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/PosVelCurCtrl_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__PosVelCurCtrl_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__PosVelCurCtrl_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__PosVelCurCtrl_Response__init(msg: *mut PosVelCurCtrl_Response) -> bool;
    fn gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PosVelCurCtrl_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PosVelCurCtrl_Response>);
    fn gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PosVelCurCtrl_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<PosVelCurCtrl_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__PosVelCurCtrl_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PosVelCurCtrl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for PosVelCurCtrl_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__PosVelCurCtrl_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__PosVelCurCtrl_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PosVelCurCtrl_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PosVelCurCtrl_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PosVelCurCtrl_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/PosVelCurCtrl_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__PosVelCurCtrl_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__DriverEnable_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__DriverEnable_Request__init(msg: *mut DriverEnable_Request) -> bool;
    fn gripper_interfaces__srv__DriverEnable_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DriverEnable_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__DriverEnable_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DriverEnable_Request>);
    fn gripper_interfaces__srv__DriverEnable_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DriverEnable_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<DriverEnable_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__DriverEnable_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriverEnable_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enable: bool,

}



impl Default for DriverEnable_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__DriverEnable_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__DriverEnable_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DriverEnable_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__DriverEnable_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__DriverEnable_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__DriverEnable_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DriverEnable_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DriverEnable_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/DriverEnable_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__DriverEnable_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__DriverEnable_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__DriverEnable_Response__init(msg: *mut DriverEnable_Response) -> bool;
    fn gripper_interfaces__srv__DriverEnable_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<DriverEnable_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__DriverEnable_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<DriverEnable_Response>);
    fn gripper_interfaces__srv__DriverEnable_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<DriverEnable_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<DriverEnable_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__DriverEnable_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriverEnable_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for DriverEnable_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__DriverEnable_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__DriverEnable_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for DriverEnable_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__DriverEnable_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__DriverEnable_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__DriverEnable_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for DriverEnable_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for DriverEnable_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/DriverEnable_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__DriverEnable_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SetParameter_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__SetParameter_Request__init(msg: *mut SetParameter_Request) -> bool;
    fn gripper_interfaces__srv__SetParameter_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetParameter_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__SetParameter_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetParameter_Request>);
    fn gripper_interfaces__srv__SetParameter_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetParameter_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetParameter_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__SetParameter_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParameter_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub vel_max: u16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub acc_max: u16,

}



impl Default for SetParameter_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__SetParameter_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__SetParameter_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetParameter_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SetParameter_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SetParameter_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SetParameter_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetParameter_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetParameter_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/SetParameter_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SetParameter_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SetParameter_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__SetParameter_Response__init(msg: *mut SetParameter_Response) -> bool;
    fn gripper_interfaces__srv__SetParameter_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetParameter_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__SetParameter_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetParameter_Response>);
    fn gripper_interfaces__srv__SetParameter_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetParameter_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetParameter_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__SetParameter_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParameter_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for SetParameter_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__SetParameter_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__SetParameter_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetParameter_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SetParameter_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SetParameter_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__SetParameter_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetParameter_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetParameter_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/SetParameter_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__SetParameter_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperControl_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__GripperControl_Request__init(msg: *mut GripperControl_Request) -> bool;
    fn gripper_interfaces__srv__GripperControl_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperControl_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__GripperControl_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperControl_Request>);
    fn gripper_interfaces__srv__GripperControl_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperControl_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperControl_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__GripperControl_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperControl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub control_mode: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_ctrl_param: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub vel_ctrl_param: [u16; 3],


    // This member is not documented.
    #[allow(missing_docs)]
    pub torque_ctrl_param: rosidl_runtime_rs::Sequence<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub custom_input: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripper_init: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grasping_vel: rosidl_runtime_rs::String,

}



impl Default for GripperControl_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__GripperControl_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__GripperControl_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperControl_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperControl_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperControl_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperControl_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperControl_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperControl_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/GripperControl_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperControl_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperControl_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__GripperControl_Response__init(msg: *mut GripperControl_Response) -> bool;
    fn gripper_interfaces__srv__GripperControl_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperControl_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__GripperControl_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperControl_Response>);
    fn gripper_interfaces__srv__GripperControl_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperControl_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperControl_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__GripperControl_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperControl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for GripperControl_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__GripperControl_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__GripperControl_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperControl_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperControl_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperControl_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperControl_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperControl_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperControl_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/GripperControl_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperControl_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__ArduinoControl_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__ArduinoControl_Request__init(msg: *mut ArduinoControl_Request) -> bool;
    fn gripper_interfaces__srv__ArduinoControl_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArduinoControl_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__ArduinoControl_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArduinoControl_Request>);
    fn gripper_interfaces__srv__ArduinoControl_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArduinoControl_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ArduinoControl_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__ArduinoControl_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArduinoControl_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub power: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub solenoid_valve: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spare_1: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub spare_2: bool,

}



impl Default for ArduinoControl_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__ArduinoControl_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__ArduinoControl_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArduinoControl_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__ArduinoControl_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__ArduinoControl_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__ArduinoControl_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArduinoControl_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArduinoControl_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/ArduinoControl_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__ArduinoControl_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__ArduinoControl_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__ArduinoControl_Response__init(msg: *mut ArduinoControl_Response) -> bool;
    fn gripper_interfaces__srv__ArduinoControl_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ArduinoControl_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__ArduinoControl_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ArduinoControl_Response>);
    fn gripper_interfaces__srv__ArduinoControl_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ArduinoControl_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ArduinoControl_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__ArduinoControl_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArduinoControl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for ArduinoControl_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__ArduinoControl_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__ArduinoControl_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ArduinoControl_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__ArduinoControl_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__ArduinoControl_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__ArduinoControl_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ArduinoControl_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ArduinoControl_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/ArduinoControl_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__ArduinoControl_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__Modbus_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__Modbus_Request__init(msg: *mut Modbus_Request) -> bool;
    fn gripper_interfaces__srv__Modbus_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Modbus_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__Modbus_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Modbus_Request>);
    fn gripper_interfaces__srv__Modbus_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Modbus_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Modbus_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__Modbus_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Modbus_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enable: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub slave_address: u8,

}



impl Default for Modbus_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__Modbus_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__Modbus_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Modbus_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__Modbus_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__Modbus_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__Modbus_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Modbus_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Modbus_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/Modbus_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__Modbus_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__Modbus_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__Modbus_Response__init(msg: *mut Modbus_Response) -> bool;
    fn gripper_interfaces__srv__Modbus_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Modbus_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__Modbus_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Modbus_Response>);
    fn gripper_interfaces__srv__Modbus_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Modbus_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Modbus_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__Modbus_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Modbus_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for Modbus_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__Modbus_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__Modbus_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Modbus_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__Modbus_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__Modbus_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__Modbus_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Modbus_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Modbus_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/Modbus_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__Modbus_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperCommand_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__GripperCommand_Request__init(msg: *mut GripperCommand_Request) -> bool;
    fn gripper_interfaces__srv__GripperCommand_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperCommand_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__GripperCommand_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperCommand_Request>);
    fn gripper_interfaces__srv__GripperCommand_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperCommand_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperCommand_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__GripperCommand_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperCommand_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: i16,

}



impl Default for GripperCommand_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__GripperCommand_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__GripperCommand_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperCommand_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperCommand_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperCommand_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperCommand_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperCommand_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperCommand_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/GripperCommand_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperCommand_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperCommand_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__GripperCommand_Response__init(msg: *mut GripperCommand_Response) -> bool;
    fn gripper_interfaces__srv__GripperCommand_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperCommand_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__GripperCommand_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperCommand_Response>);
    fn gripper_interfaces__srv__GripperCommand_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperCommand_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperCommand_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__GripperCommand_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperCommand_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for GripperCommand_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__GripperCommand_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__GripperCommand_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperCommand_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperCommand_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperCommand_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__GripperCommand_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperCommand_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperCommand_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/GripperCommand_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__GripperCommand_Response() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__StopMotor_Request() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__StopMotor_Request__init(msg: *mut StopMotor_Request) -> bool;
    fn gripper_interfaces__srv__StopMotor_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StopMotor_Request>, size: usize) -> bool;
    fn gripper_interfaces__srv__StopMotor_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StopMotor_Request>);
    fn gripper_interfaces__srv__StopMotor_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StopMotor_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<StopMotor_Request>) -> bool;
}

// Corresponds to gripper_interfaces__srv__StopMotor_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopMotor_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub duration: u16,

}



impl Default for StopMotor_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__StopMotor_Request__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__StopMotor_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StopMotor_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__StopMotor_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__StopMotor_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__StopMotor_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StopMotor_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StopMotor_Request where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/StopMotor_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__StopMotor_Request() }
  }
}


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__StopMotor_Response() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__srv__StopMotor_Response__init(msg: *mut StopMotor_Response) -> bool;
    fn gripper_interfaces__srv__StopMotor_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StopMotor_Response>, size: usize) -> bool;
    fn gripper_interfaces__srv__StopMotor_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StopMotor_Response>);
    fn gripper_interfaces__srv__StopMotor_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StopMotor_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<StopMotor_Response>) -> bool;
}

// Corresponds to gripper_interfaces__srv__StopMotor_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopMotor_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for StopMotor_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__srv__StopMotor_Response__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__srv__StopMotor_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StopMotor_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__StopMotor_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__StopMotor_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__srv__StopMotor_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StopMotor_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StopMotor_Response where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/srv/StopMotor_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__srv__StopMotor_Response() }
  }
}






#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__SlaveChange() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__SlaveChange
#[allow(missing_docs, non_camel_case_types)]
pub struct SlaveChange;

impl rosidl_runtime_rs::Service for SlaveChange {
    type Request = SlaveChange_Request;
    type Response = SlaveChange_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__SlaveChange() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__PosVelCurCtrl() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__PosVelCurCtrl
#[allow(missing_docs, non_camel_case_types)]
pub struct PosVelCurCtrl;

impl rosidl_runtime_rs::Service for PosVelCurCtrl {
    type Request = PosVelCurCtrl_Request;
    type Response = PosVelCurCtrl_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__PosVelCurCtrl() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__DriverEnable() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__DriverEnable
#[allow(missing_docs, non_camel_case_types)]
pub struct DriverEnable;

impl rosidl_runtime_rs::Service for DriverEnable {
    type Request = DriverEnable_Request;
    type Response = DriverEnable_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__DriverEnable() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__SetParameter() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__SetParameter
#[allow(missing_docs, non_camel_case_types)]
pub struct SetParameter;

impl rosidl_runtime_rs::Service for SetParameter {
    type Request = SetParameter_Request;
    type Response = SetParameter_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__SetParameter() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__GripperControl() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__GripperControl
#[allow(missing_docs, non_camel_case_types)]
pub struct GripperControl;

impl rosidl_runtime_rs::Service for GripperControl {
    type Request = GripperControl_Request;
    type Response = GripperControl_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__GripperControl() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__ArduinoControl() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__ArduinoControl
#[allow(missing_docs, non_camel_case_types)]
pub struct ArduinoControl;

impl rosidl_runtime_rs::Service for ArduinoControl {
    type Request = ArduinoControl_Request;
    type Response = ArduinoControl_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__ArduinoControl() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__Modbus() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__Modbus
#[allow(missing_docs, non_camel_case_types)]
pub struct Modbus;

impl rosidl_runtime_rs::Service for Modbus {
    type Request = Modbus_Request;
    type Response = Modbus_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__Modbus() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__GripperCommand() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__GripperCommand
#[allow(missing_docs, non_camel_case_types)]
pub struct GripperCommand;

impl rosidl_runtime_rs::Service for GripperCommand {
    type Request = GripperCommand_Request;
    type Response = GripperCommand_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__GripperCommand() }
    }
}




#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__StopMotor() -> *const std::ffi::c_void;
}

// Corresponds to gripper_interfaces__srv__StopMotor
#[allow(missing_docs, non_camel_case_types)]
pub struct StopMotor;

impl rosidl_runtime_rs::Service for StopMotor {
    type Request = StopMotor_Request;
    type Response = StopMotor_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__gripper_interfaces__srv__StopMotor() }
    }
}


