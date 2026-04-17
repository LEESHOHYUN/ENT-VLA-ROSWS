#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "nurse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__ObjectToken() -> *const std::ffi::c_void;
}

#[link(name = "nurse_interfaces__rosidl_generator_c")]
extern "C" {
    fn nurse_interfaces__msg__ObjectToken__init(msg: *mut ObjectToken) -> bool;
    fn nurse_interfaces__msg__ObjectToken__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ObjectToken>, size: usize) -> bool;
    fn nurse_interfaces__msg__ObjectToken__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ObjectToken>);
    fn nurse_interfaces__msg__ObjectToken__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ObjectToken>, out_seq: *mut rosidl_runtime_rs::Sequence<ObjectToken>) -> bool;
}

// Corresponds to nurse_interfaces__msg__ObjectToken
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Single tracked object from SAM2S (instrument or hand)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObjectToken {
    /// e.g. "myringotomy_knife", "surgeon_hand_left"
    pub object_id: rosidl_runtime_rs::String,

    /// instrument type or "hand"
    pub object_class: rosidl_runtime_rs::String,

    /// [x_min, y_min, x_max, y_max] normalized 0-1
    pub bbox: [f32; 4],

    /// detection confidence
    pub confidence: f32,

    /// currently visible in frame
    pub visible: bool,

    /// 3D position estimate (if depth available)
    pub position: geometry_msgs::msg::rmw::Point,

}



impl Default for ObjectToken {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nurse_interfaces__msg__ObjectToken__init(&mut msg as *mut _) {
        panic!("Call to nurse_interfaces__msg__ObjectToken__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ObjectToken {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ObjectToken__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ObjectToken__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ObjectToken__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ObjectToken {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ObjectToken where Self: Sized {
  const TYPE_NAME: &'static str = "nurse_interfaces/msg/ObjectToken";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__ObjectToken() }
  }
}


#[link(name = "nurse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__ObjectTokenArray() -> *const std::ffi::c_void;
}

#[link(name = "nurse_interfaces__rosidl_generator_c")]
extern "C" {
    fn nurse_interfaces__msg__ObjectTokenArray__init(msg: *mut ObjectTokenArray) -> bool;
    fn nurse_interfaces__msg__ObjectTokenArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ObjectTokenArray>, size: usize) -> bool;
    fn nurse_interfaces__msg__ObjectTokenArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ObjectTokenArray>);
    fn nurse_interfaces__msg__ObjectTokenArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ObjectTokenArray>, out_seq: *mut rosidl_runtime_rs::Sequence<ObjectTokenArray>) -> bool;
}

// Corresponds to nurse_interfaces__msg__ObjectTokenArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Array of tracked objects from SAM2S

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObjectTokenArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tokens: rosidl_runtime_rs::Sequence<super::super::msg::rmw::ObjectToken>,

}



impl Default for ObjectTokenArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nurse_interfaces__msg__ObjectTokenArray__init(&mut msg as *mut _) {
        panic!("Call to nurse_interfaces__msg__ObjectTokenArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ObjectTokenArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ObjectTokenArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ObjectTokenArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ObjectTokenArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ObjectTokenArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ObjectTokenArray where Self: Sized {
  const TYPE_NAME: &'static str = "nurse_interfaces/msg/ObjectTokenArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__ObjectTokenArray() }
  }
}


#[link(name = "nurse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__EmergencySignal() -> *const std::ffi::c_void;
}

#[link(name = "nurse_interfaces__rosidl_generator_c")]
extern "C" {
    fn nurse_interfaces__msg__EmergencySignal__init(msg: *mut EmergencySignal) -> bool;
    fn nurse_interfaces__msg__EmergencySignal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EmergencySignal>, size: usize) -> bool;
    fn nurse_interfaces__msg__EmergencySignal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EmergencySignal>);
    fn nurse_interfaces__msg__EmergencySignal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EmergencySignal>, out_seq: *mut rosidl_runtime_rs::Sequence<EmergencySignal>) -> bool;
}

// Corresponds to nurse_interfaces__msg__EmergencySignal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Emergency classification from endoscope camera

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EmergencySignal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,

    /// optional description
    pub detail: rosidl_runtime_rs::String,

}

impl EmergencySignal {
    /// Status codes
    pub const NORMAL: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BLEEDING: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONTAMINATION: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PHASE_COMPLETE: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UNKNOWN: u8 = 255;

}


impl Default for EmergencySignal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nurse_interfaces__msg__EmergencySignal__init(&mut msg as *mut _) {
        panic!("Call to nurse_interfaces__msg__EmergencySignal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EmergencySignal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__EmergencySignal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__EmergencySignal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__EmergencySignal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EmergencySignal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EmergencySignal where Self: Sized {
  const TYPE_NAME: &'static str = "nurse_interfaces/msg/EmergencySignal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__EmergencySignal() }
  }
}


#[link(name = "nurse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__ToolPrompt() -> *const std::ffi::c_void;
}

#[link(name = "nurse_interfaces__rosidl_generator_c")]
extern "C" {
    fn nurse_interfaces__msg__ToolPrompt__init(msg: *mut ToolPrompt) -> bool;
    fn nurse_interfaces__msg__ToolPrompt__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ToolPrompt>, size: usize) -> bool;
    fn nurse_interfaces__msg__ToolPrompt__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ToolPrompt>);
    fn nurse_interfaces__msg__ToolPrompt__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ToolPrompt>, out_seq: *mut rosidl_runtime_rs::Sequence<ToolPrompt>) -> bool;
}

// Corresponds to nurse_interfaces__msg__ToolPrompt
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Planner output: predicted next tool and language prompt for VLA

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ToolPrompt {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// e.g. "suction_tip_3mm"
    pub tool_name: rosidl_runtime_rs::String,

    /// natural language prompt for VLA executor
    pub language_prompt: rosidl_runtime_rs::String,

    /// planner confidence
    pub confidence: f32,

    /// current surgical phase
    pub phase: rosidl_runtime_rs::String,

}



impl Default for ToolPrompt {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nurse_interfaces__msg__ToolPrompt__init(&mut msg as *mut _) {
        panic!("Call to nurse_interfaces__msg__ToolPrompt__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ToolPrompt {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ToolPrompt__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ToolPrompt__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__ToolPrompt__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ToolPrompt {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ToolPrompt where Self: Sized {
  const TYPE_NAME: &'static str = "nurse_interfaces/msg/ToolPrompt";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__ToolPrompt() }
  }
}


#[link(name = "nurse_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__SafetySignal() -> *const std::ffi::c_void;
}

#[link(name = "nurse_interfaces__rosidl_generator_c")]
extern "C" {
    fn nurse_interfaces__msg__SafetySignal__init(msg: *mut SafetySignal) -> bool;
    fn nurse_interfaces__msg__SafetySignal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SafetySignal>, size: usize) -> bool;
    fn nurse_interfaces__msg__SafetySignal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SafetySignal>);
    fn nurse_interfaces__msg__SafetySignal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SafetySignal>, out_seq: *mut rosidl_runtime_rs::Sequence<SafetySignal>) -> bool;
}

// Corresponds to nurse_interfaces__msg__SafetySignal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Safety Gate output

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SafetySignal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub decision: u8,

    /// human-readable reason for HOLD/ABORT
    pub reason: rosidl_runtime_rs::String,

}

impl SafetySignal {
    /// Decision codes
    pub const GO: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const HOLD: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ABORT: u8 = 2;

}


impl Default for SafetySignal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !nurse_interfaces__msg__SafetySignal__init(&mut msg as *mut _) {
        panic!("Call to nurse_interfaces__msg__SafetySignal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SafetySignal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__SafetySignal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__SafetySignal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { nurse_interfaces__msg__SafetySignal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SafetySignal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SafetySignal where Self: Sized {
  const TYPE_NAME: &'static str = "nurse_interfaces/msg/SafetySignal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__nurse_interfaces__msg__SafetySignal() }
  }
}


