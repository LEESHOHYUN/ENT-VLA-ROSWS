#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to gripper_interfaces__srv__SlaveChange_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SlaveChange_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub slave_address: u8,

}



impl Default for SlaveChange_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SlaveChange_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SlaveChange_Request {
  type RmwMsg = super::srv::rmw::SlaveChange_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        slave_address: msg.slave_address,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      slave_address: msg.slave_address,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      slave_address: msg.slave_address,
    }
  }
}


// Corresponds to gripper_interfaces__srv__SlaveChange_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SlaveChange_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for SlaveChange_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SlaveChange_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SlaveChange_Response {
  type RmwMsg = super::srv::rmw::SlaveChange_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__PosVelCurCtrl_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PosVelCurCtrl_Request::default())
  }
}

impl rosidl_runtime_rs::Message for PosVelCurCtrl_Request {
  type RmwMsg = super::srv::rmw::PosVelCurCtrl_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: msg.position,
        velocity: msg.velocity,
        acceleration: msg.acceleration,
        current: msg.current,
        duration: msg.duration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      position: msg.position,
      velocity: msg.velocity,
      acceleration: msg.acceleration,
      current: msg.current,
      duration: msg.duration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position: msg.position,
      velocity: msg.velocity,
      acceleration: msg.acceleration,
      current: msg.current,
      duration: msg.duration,
    }
  }
}


// Corresponds to gripper_interfaces__srv__PosVelCurCtrl_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PosVelCurCtrl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for PosVelCurCtrl_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::PosVelCurCtrl_Response::default())
  }
}

impl rosidl_runtime_rs::Message for PosVelCurCtrl_Response {
  type RmwMsg = super::srv::rmw::PosVelCurCtrl_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__DriverEnable_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriverEnable_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enable: bool,

}



impl Default for DriverEnable_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DriverEnable_Request::default())
  }
}

impl rosidl_runtime_rs::Message for DriverEnable_Request {
  type RmwMsg = super::srv::rmw::DriverEnable_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        enable: msg.enable,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      enable: msg.enable,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      enable: msg.enable,
    }
  }
}


// Corresponds to gripper_interfaces__srv__DriverEnable_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct DriverEnable_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for DriverEnable_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::DriverEnable_Response::default())
  }
}

impl rosidl_runtime_rs::Message for DriverEnable_Response {
  type RmwMsg = super::srv::rmw::DriverEnable_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__SetParameter_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetParameter_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetParameter_Request {
  type RmwMsg = super::srv::rmw::SetParameter_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vel_max: msg.vel_max,
        acc_max: msg.acc_max,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      vel_max: msg.vel_max,
      acc_max: msg.acc_max,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vel_max: msg.vel_max,
      acc_max: msg.acc_max,
    }
  }
}


// Corresponds to gripper_interfaces__srv__SetParameter_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetParameter_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for SetParameter_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetParameter_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetParameter_Response {
  type RmwMsg = super::srv::rmw::SetParameter_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__GripperControl_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub torque_ctrl_param: Vec<u32>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub custom_input: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripper_init: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub grasping_vel: std::string::String,

}



impl Default for GripperControl_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GripperControl_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GripperControl_Request {
  type RmwMsg = super::srv::rmw::GripperControl_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        control_mode: msg.control_mode,
        pos_ctrl_param: msg.pos_ctrl_param,
        vel_ctrl_param: msg.vel_ctrl_param,
        torque_ctrl_param: msg.torque_ctrl_param.into(),
        custom_input: msg.custom_input.as_str().into(),
        gripper_init: msg.gripper_init.as_str().into(),
        grasping_vel: msg.grasping_vel.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      control_mode: msg.control_mode,
        pos_ctrl_param: msg.pos_ctrl_param,
        vel_ctrl_param: msg.vel_ctrl_param,
        torque_ctrl_param: msg.torque_ctrl_param.as_slice().into(),
        custom_input: msg.custom_input.as_str().into(),
        gripper_init: msg.gripper_init.as_str().into(),
        grasping_vel: msg.grasping_vel.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      control_mode: msg.control_mode,
      pos_ctrl_param: msg.pos_ctrl_param,
      vel_ctrl_param: msg.vel_ctrl_param,
      torque_ctrl_param: msg.torque_ctrl_param
          .into_iter()
          .collect(),
      custom_input: msg.custom_input.to_string(),
      gripper_init: msg.gripper_init.to_string(),
      grasping_vel: msg.grasping_vel.to_string(),
    }
  }
}


// Corresponds to gripper_interfaces__srv__GripperControl_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperControl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for GripperControl_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GripperControl_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GripperControl_Response {
  type RmwMsg = super::srv::rmw::GripperControl_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__ArduinoControl_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ArduinoControl_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ArduinoControl_Request {
  type RmwMsg = super::srv::rmw::ArduinoControl_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        power: msg.power,
        solenoid_valve: msg.solenoid_valve,
        spare_1: msg.spare_1,
        spare_2: msg.spare_2,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      power: msg.power,
      solenoid_valve: msg.solenoid_valve,
      spare_1: msg.spare_1,
      spare_2: msg.spare_2,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      power: msg.power,
      solenoid_valve: msg.solenoid_valve,
      spare_1: msg.spare_1,
      spare_2: msg.spare_2,
    }
  }
}


// Corresponds to gripper_interfaces__srv__ArduinoControl_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ArduinoControl_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for ArduinoControl_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ArduinoControl_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ArduinoControl_Response {
  type RmwMsg = super::srv::rmw::ArduinoControl_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__Modbus_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Modbus_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Modbus_Request {
  type RmwMsg = super::srv::rmw::Modbus_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        enable: msg.enable,
        slave_address: msg.slave_address,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      enable: msg.enable,
      slave_address: msg.slave_address,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      enable: msg.enable,
      slave_address: msg.slave_address,
    }
  }
}


// Corresponds to gripper_interfaces__srv__Modbus_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Modbus_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for Modbus_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Modbus_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Modbus_Response {
  type RmwMsg = super::srv::rmw::Modbus_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__GripperCommand_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GripperCommand_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GripperCommand_Request {
  type RmwMsg = super::srv::rmw::GripperCommand_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command,
        value: msg.value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      command: msg.command,
      value: msg.value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command,
      value: msg.value,
    }
  }
}


// Corresponds to gripper_interfaces__srv__GripperCommand_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GripperCommand_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for GripperCommand_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GripperCommand_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GripperCommand_Response {
  type RmwMsg = super::srv::rmw::GripperCommand_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
  }
}


// Corresponds to gripper_interfaces__srv__StopMotor_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopMotor_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub duration: u16,

}



impl Default for StopMotor_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StopMotor_Request::default())
  }
}

impl rosidl_runtime_rs::Message for StopMotor_Request {
  type RmwMsg = super::srv::rmw::StopMotor_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        duration: msg.duration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      duration: msg.duration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      duration: msg.duration,
    }
  }
}


// Corresponds to gripper_interfaces__srv__StopMotor_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StopMotor_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub successed: bool,

}



impl Default for StopMotor_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::StopMotor_Response::default())
  }
}

impl rosidl_runtime_rs::Message for StopMotor_Response {
  type RmwMsg = super::srv::rmw::StopMotor_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        successed: msg.successed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      successed: msg.successed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      successed: msg.successed,
    }
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


