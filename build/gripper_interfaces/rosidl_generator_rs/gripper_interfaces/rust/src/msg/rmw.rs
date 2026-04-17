#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "gripper_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__msg__GripperMsg() -> *const std::ffi::c_void;
}

#[link(name = "gripper_interfaces__rosidl_generator_c")]
extern "C" {
    fn gripper_interfaces__msg__GripperMsg__init(msg: *mut GripperMsg) -> bool;
    fn gripper_interfaces__msg__GripperMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GripperMsg>, size: usize) -> bool;
    fn gripper_interfaces__msg__GripperMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GripperMsg>);
    fn gripper_interfaces__msg__GripperMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GripperMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<GripperMsg>) -> bool;
}

// Corresponds to gripper_interfaces__msg__GripperMsg
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperMsg {

    // This member is not documented.
    #[allow(missing_docs)]
    pub angle: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub current: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grp_pos: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_motor_enable: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_grp_init_ongoing: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_pos_ongoing: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_vel_ongoing: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_tor_ongoing: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_grp_opening: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_grp_closing: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grp_direction: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_object_grasp: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_fault_occured: bool,

}



impl Default for GripperMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gripper_interfaces__msg__GripperMsg__init(&mut msg as *mut _) {
        panic!("Call to gripper_interfaces__msg__GripperMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GripperMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__msg__GripperMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__msg__GripperMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gripper_interfaces__msg__GripperMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GripperMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GripperMsg where Self: Sized {
  const TYPE_NAME: &'static str = "gripper_interfaces/msg/GripperMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gripper_interfaces__msg__GripperMsg() }
  }
}


