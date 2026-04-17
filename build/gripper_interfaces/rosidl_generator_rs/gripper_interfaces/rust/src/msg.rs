#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to gripper_interfaces__msg__GripperMsg

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GripperMsg::default())
  }
}

impl rosidl_runtime_rs::Message for GripperMsg {
  type RmwMsg = super::msg::rmw::GripperMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        angle: msg.angle,
        current: msg.current,
        velocity: msg.velocity,
        grp_pos: msg.grp_pos,
        is_motor_enable: msg.is_motor_enable,
        is_grp_init_ongoing: msg.is_grp_init_ongoing,
        is_pos_ongoing: msg.is_pos_ongoing,
        is_vel_ongoing: msg.is_vel_ongoing,
        is_tor_ongoing: msg.is_tor_ongoing,
        is_grp_opening: msg.is_grp_opening,
        is_grp_closing: msg.is_grp_closing,
        grp_direction: msg.grp_direction,
        is_object_grasp: msg.is_object_grasp,
        is_fault_occured: msg.is_fault_occured,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      angle: msg.angle,
      current: msg.current,
      velocity: msg.velocity,
      grp_pos: msg.grp_pos,
      is_motor_enable: msg.is_motor_enable,
      is_grp_init_ongoing: msg.is_grp_init_ongoing,
      is_pos_ongoing: msg.is_pos_ongoing,
      is_vel_ongoing: msg.is_vel_ongoing,
      is_tor_ongoing: msg.is_tor_ongoing,
      is_grp_opening: msg.is_grp_opening,
      is_grp_closing: msg.is_grp_closing,
      grp_direction: msg.grp_direction,
      is_object_grasp: msg.is_object_grasp,
      is_fault_occured: msg.is_fault_occured,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      angle: msg.angle,
      current: msg.current,
      velocity: msg.velocity,
      grp_pos: msg.grp_pos,
      is_motor_enable: msg.is_motor_enable,
      is_grp_init_ongoing: msg.is_grp_init_ongoing,
      is_pos_ongoing: msg.is_pos_ongoing,
      is_vel_ongoing: msg.is_vel_ongoing,
      is_tor_ongoing: msg.is_tor_ongoing,
      is_grp_opening: msg.is_grp_opening,
      is_grp_closing: msg.is_grp_closing,
      grp_direction: msg.grp_direction,
      is_object_grasp: msg.is_object_grasp,
      is_fault_occured: msg.is_fault_occured,
    }
  }
}


