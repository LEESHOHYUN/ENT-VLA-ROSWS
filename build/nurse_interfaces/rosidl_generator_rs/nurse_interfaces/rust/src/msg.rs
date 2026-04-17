#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to nurse_interfaces__msg__ObjectToken
/// Single tracked object from SAM2S (instrument or hand)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObjectToken {
    /// e.g. "myringotomy_knife", "surgeon_hand_left"
    pub object_id: std::string::String,

    /// instrument type or "hand"
    pub object_class: std::string::String,

    /// [x_min, y_min, x_max, y_max] normalized 0-1
    pub bbox: [f32; 4],

    /// detection confidence
    pub confidence: f32,

    /// currently visible in frame
    pub visible: bool,

    /// 3D position estimate (if depth available)
    pub position: geometry_msgs::msg::Point,

}



impl Default for ObjectToken {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ObjectToken::default())
  }
}

impl rosidl_runtime_rs::Message for ObjectToken {
  type RmwMsg = super::msg::rmw::ObjectToken;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        object_id: msg.object_id.as_str().into(),
        object_class: msg.object_class.as_str().into(),
        bbox: msg.bbox,
        confidence: msg.confidence,
        visible: msg.visible,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        object_id: msg.object_id.as_str().into(),
        object_class: msg.object_class.as_str().into(),
        bbox: msg.bbox,
      confidence: msg.confidence,
      visible: msg.visible,
        position: geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      object_id: msg.object_id.to_string(),
      object_class: msg.object_class.to_string(),
      bbox: msg.bbox,
      confidence: msg.confidence,
      visible: msg.visible,
      position: geometry_msgs::msg::Point::from_rmw_message(msg.position),
    }
  }
}


// Corresponds to nurse_interfaces__msg__ObjectTokenArray
/// Array of tracked objects from SAM2S

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObjectTokenArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tokens: Vec<super::msg::ObjectToken>,

}



impl Default for ObjectTokenArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ObjectTokenArray::default())
  }
}

impl rosidl_runtime_rs::Message for ObjectTokenArray {
  type RmwMsg = super::msg::rmw::ObjectTokenArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        tokens: msg.tokens
          .into_iter()
          .map(|elem| super::msg::ObjectToken::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        tokens: msg.tokens
          .iter()
          .map(|elem| super::msg::ObjectToken::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      tokens: msg.tokens
          .into_iter()
          .map(super::msg::ObjectToken::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to nurse_interfaces__msg__EmergencySignal
/// Emergency classification from endoscope camera

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EmergencySignal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,

    /// optional description
    pub detail: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::EmergencySignal::default())
  }
}

impl rosidl_runtime_rs::Message for EmergencySignal {
  type RmwMsg = super::msg::rmw::EmergencySignal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        status: msg.status,
        confidence: msg.confidence,
        detail: msg.detail.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      status: msg.status,
      confidence: msg.confidence,
        detail: msg.detail.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      status: msg.status,
      confidence: msg.confidence,
      detail: msg.detail.to_string(),
    }
  }
}


// Corresponds to nurse_interfaces__msg__ToolPrompt
/// Planner output: predicted next tool and language prompt for VLA

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ToolPrompt {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// e.g. "suction_tip_3mm"
    pub tool_name: std::string::String,

    /// natural language prompt for VLA executor
    pub language_prompt: std::string::String,

    /// planner confidence
    pub confidence: f32,

    /// current surgical phase
    pub phase: std::string::String,

}



impl Default for ToolPrompt {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ToolPrompt::default())
  }
}

impl rosidl_runtime_rs::Message for ToolPrompt {
  type RmwMsg = super::msg::rmw::ToolPrompt;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        tool_name: msg.tool_name.as_str().into(),
        language_prompt: msg.language_prompt.as_str().into(),
        confidence: msg.confidence,
        phase: msg.phase.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        tool_name: msg.tool_name.as_str().into(),
        language_prompt: msg.language_prompt.as_str().into(),
      confidence: msg.confidence,
        phase: msg.phase.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      tool_name: msg.tool_name.to_string(),
      language_prompt: msg.language_prompt.to_string(),
      confidence: msg.confidence,
      phase: msg.phase.to_string(),
    }
  }
}


// Corresponds to nurse_interfaces__msg__SafetySignal
/// Safety Gate output

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SafetySignal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub decision: u8,

    /// human-readable reason for HOLD/ABORT
    pub reason: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SafetySignal::default())
  }
}

impl rosidl_runtime_rs::Message for SafetySignal {
  type RmwMsg = super::msg::rmw::SafetySignal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        decision: msg.decision,
        reason: msg.reason.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      decision: msg.decision,
        reason: msg.reason.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      decision: msg.decision,
      reason: msg.reason.to_string(),
    }
  }
}


