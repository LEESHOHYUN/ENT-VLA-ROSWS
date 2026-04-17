// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from gripper_interfaces:action/Gripper.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "gripper_interfaces/action/detail/gripper__struct.h"
#include "gripper_interfaces/action/detail/gripper__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_Goal_type_support_ids_t;

static const _Gripper_Goal_type_support_ids_t _Gripper_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_Goal_type_support_symbol_names_t _Gripper_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_Goal)),
  }
};

typedef struct _Gripper_Goal_type_support_data_t
{
  void * data[2];
} _Gripper_Goal_type_support_data_t;

static _Gripper_Goal_type_support_data_t _Gripper_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_Goal_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_Goal)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_Result_type_support_ids_t;

static const _Gripper_Result_type_support_ids_t _Gripper_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_Result_type_support_symbol_names_t _Gripper_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_Result)),
  }
};

typedef struct _Gripper_Result_type_support_data_t
{
  void * data[2];
} _Gripper_Result_type_support_data_t;

static _Gripper_Result_type_support_data_t _Gripper_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_Result_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_Result)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_Feedback_type_support_ids_t;

static const _Gripper_Feedback_type_support_ids_t _Gripper_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_Feedback_type_support_symbol_names_t _Gripper_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_Feedback)),
  }
};

typedef struct _Gripper_Feedback_type_support_data_t
{
  void * data[2];
} _Gripper_Feedback_type_support_data_t;

static _Gripper_Feedback_type_support_data_t _Gripper_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_Feedback_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_Feedback)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_SendGoal_Request_type_support_ids_t;

static const _Gripper_SendGoal_Request_type_support_ids_t _Gripper_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_SendGoal_Request_type_support_symbol_names_t _Gripper_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_SendGoal_Request)),
  }
};

typedef struct _Gripper_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Gripper_SendGoal_Request_type_support_data_t;

static _Gripper_SendGoal_Request_type_support_data_t _Gripper_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_SendGoal_Request_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_SendGoal_Request)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_SendGoal_Response_type_support_ids_t;

static const _Gripper_SendGoal_Response_type_support_ids_t _Gripper_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_SendGoal_Response_type_support_symbol_names_t _Gripper_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_SendGoal_Response)),
  }
};

typedef struct _Gripper_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Gripper_SendGoal_Response_type_support_data_t;

static _Gripper_SendGoal_Response_type_support_data_t _Gripper_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_SendGoal_Response_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_SendGoal_Response)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_SendGoal_type_support_ids_t;

static const _Gripper_SendGoal_type_support_ids_t _Gripper_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_SendGoal_type_support_symbol_names_t _Gripper_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_SendGoal)),
  }
};

typedef struct _Gripper_SendGoal_type_support_data_t
{
  void * data[2];
} _Gripper_SendGoal_type_support_data_t;

static _Gripper_SendGoal_type_support_data_t _Gripper_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_SendGoal_service_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Gripper_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Gripper_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Gripper_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_SendGoal)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_GetResult_Request_type_support_ids_t;

static const _Gripper_GetResult_Request_type_support_ids_t _Gripper_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_GetResult_Request_type_support_symbol_names_t _Gripper_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_GetResult_Request)),
  }
};

typedef struct _Gripper_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Gripper_GetResult_Request_type_support_data_t;

static _Gripper_GetResult_Request_type_support_data_t _Gripper_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_GetResult_Request_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_GetResult_Request)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_GetResult_Response_type_support_ids_t;

static const _Gripper_GetResult_Response_type_support_ids_t _Gripper_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_GetResult_Response_type_support_symbol_names_t _Gripper_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_GetResult_Response)),
  }
};

typedef struct _Gripper_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Gripper_GetResult_Response_type_support_data_t;

static _Gripper_GetResult_Response_type_support_data_t _Gripper_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_GetResult_Response_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_GetResult_Response)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_GetResult_type_support_ids_t;

static const _Gripper_GetResult_type_support_ids_t _Gripper_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_GetResult_type_support_symbol_names_t _Gripper_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_GetResult)),
  }
};

typedef struct _Gripper_GetResult_type_support_data_t
{
  void * data[2];
} _Gripper_GetResult_type_support_data_t;

static _Gripper_GetResult_type_support_data_t _Gripper_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_GetResult_service_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Gripper_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Gripper_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Gripper_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_GetResult)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__struct.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace gripper_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _Gripper_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Gripper_FeedbackMessage_type_support_ids_t;

static const _Gripper_FeedbackMessage_type_support_ids_t _Gripper_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Gripper_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Gripper_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Gripper_FeedbackMessage_type_support_symbol_names_t _Gripper_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gripper_interfaces, action, Gripper_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gripper_interfaces, action, Gripper_FeedbackMessage)),
  }
};

typedef struct _Gripper_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Gripper_FeedbackMessage_type_support_data_t;

static _Gripper_FeedbackMessage_type_support_data_t _Gripper_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Gripper_FeedbackMessage_message_typesupport_map = {
  2,
  "gripper_interfaces",
  &_Gripper_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Gripper_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Gripper_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Gripper_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Gripper_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace gripper_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, gripper_interfaces, action, Gripper_FeedbackMessage)() {
  return &::gripper_interfaces::action::rosidl_typesupport_c::Gripper_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "gripper_interfaces/action/gripper.h"
// already included above
// #include "gripper_interfaces/action/detail/gripper__type_support.h"

static rosidl_action_type_support_t _gripper_interfaces__action__Gripper__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, gripper_interfaces, action, Gripper)()
{
  // Thread-safe by always writing the same values to the static struct
  _gripper_interfaces__action__Gripper__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, gripper_interfaces, action, Gripper_SendGoal)();
  _gripper_interfaces__action__Gripper__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, gripper_interfaces, action, Gripper_GetResult)();
  _gripper_interfaces__action__Gripper__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _gripper_interfaces__action__Gripper__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, gripper_interfaces, action, Gripper_FeedbackMessage)();
  _gripper_interfaces__action__Gripper__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_gripper_interfaces__action__Gripper__typesupport_c;
}

#ifdef __cplusplus
}
#endif
