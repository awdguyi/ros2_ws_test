// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from mps_interfaces:srv/GetRobotSchedule.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "mps_interfaces/srv/detail/get_robot_schedule__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace mps_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetRobotSchedule_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetRobotSchedule_Request_type_support_ids_t;

static const _GetRobotSchedule_Request_type_support_ids_t _GetRobotSchedule_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetRobotSchedule_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetRobotSchedule_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetRobotSchedule_Request_type_support_symbol_names_t _GetRobotSchedule_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mps_interfaces, srv, GetRobotSchedule_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mps_interfaces, srv, GetRobotSchedule_Request)),
  }
};

typedef struct _GetRobotSchedule_Request_type_support_data_t
{
  void * data[2];
} _GetRobotSchedule_Request_type_support_data_t;

static _GetRobotSchedule_Request_type_support_data_t _GetRobotSchedule_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetRobotSchedule_Request_message_typesupport_map = {
  2,
  "mps_interfaces",
  &_GetRobotSchedule_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetRobotSchedule_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetRobotSchedule_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetRobotSchedule_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetRobotSchedule_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace mps_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mps_interfaces::srv::GetRobotSchedule_Request>()
{
  return &::mps_interfaces::srv::rosidl_typesupport_cpp::GetRobotSchedule_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, mps_interfaces, srv, GetRobotSchedule_Request)() {
  return get_message_type_support_handle<mps_interfaces::srv::GetRobotSchedule_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mps_interfaces/srv/detail/get_robot_schedule__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mps_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetRobotSchedule_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetRobotSchedule_Response_type_support_ids_t;

static const _GetRobotSchedule_Response_type_support_ids_t _GetRobotSchedule_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetRobotSchedule_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetRobotSchedule_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetRobotSchedule_Response_type_support_symbol_names_t _GetRobotSchedule_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mps_interfaces, srv, GetRobotSchedule_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mps_interfaces, srv, GetRobotSchedule_Response)),
  }
};

typedef struct _GetRobotSchedule_Response_type_support_data_t
{
  void * data[2];
} _GetRobotSchedule_Response_type_support_data_t;

static _GetRobotSchedule_Response_type_support_data_t _GetRobotSchedule_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetRobotSchedule_Response_message_typesupport_map = {
  2,
  "mps_interfaces",
  &_GetRobotSchedule_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetRobotSchedule_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetRobotSchedule_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetRobotSchedule_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetRobotSchedule_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace mps_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mps_interfaces::srv::GetRobotSchedule_Response>()
{
  return &::mps_interfaces::srv::rosidl_typesupport_cpp::GetRobotSchedule_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, mps_interfaces, srv, GetRobotSchedule_Response)() {
  return get_message_type_support_handle<mps_interfaces::srv::GetRobotSchedule_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mps_interfaces/srv/detail/get_robot_schedule__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mps_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetRobotSchedule_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetRobotSchedule_type_support_ids_t;

static const _GetRobotSchedule_type_support_ids_t _GetRobotSchedule_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetRobotSchedule_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetRobotSchedule_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetRobotSchedule_type_support_symbol_names_t _GetRobotSchedule_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mps_interfaces, srv, GetRobotSchedule)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mps_interfaces, srv, GetRobotSchedule)),
  }
};

typedef struct _GetRobotSchedule_type_support_data_t
{
  void * data[2];
} _GetRobotSchedule_type_support_data_t;

static _GetRobotSchedule_type_support_data_t _GetRobotSchedule_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetRobotSchedule_service_typesupport_map = {
  2,
  "mps_interfaces",
  &_GetRobotSchedule_service_typesupport_ids.typesupport_identifier[0],
  &_GetRobotSchedule_service_typesupport_symbol_names.symbol_name[0],
  &_GetRobotSchedule_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetRobotSchedule_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetRobotSchedule_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace mps_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<mps_interfaces::srv::GetRobotSchedule>()
{
  return &::mps_interfaces::srv::rosidl_typesupport_cpp::GetRobotSchedule_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, mps_interfaces, srv, GetRobotSchedule)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<mps_interfaces::srv::GetRobotSchedule>();
}

#ifdef __cplusplus
}
#endif
