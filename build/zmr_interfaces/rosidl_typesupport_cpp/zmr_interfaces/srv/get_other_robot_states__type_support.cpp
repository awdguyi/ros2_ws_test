// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from zmr_interfaces:srv/GetOtherRobotStates.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "zmr_interfaces/srv/detail/get_other_robot_states__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace zmr_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetOtherRobotStates_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetOtherRobotStates_Request_type_support_ids_t;

static const _GetOtherRobotStates_Request_type_support_ids_t _GetOtherRobotStates_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetOtherRobotStates_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetOtherRobotStates_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetOtherRobotStates_Request_type_support_symbol_names_t _GetOtherRobotStates_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zmr_interfaces, srv, GetOtherRobotStates_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zmr_interfaces, srv, GetOtherRobotStates_Request)),
  }
};

typedef struct _GetOtherRobotStates_Request_type_support_data_t
{
  void * data[2];
} _GetOtherRobotStates_Request_type_support_data_t;

static _GetOtherRobotStates_Request_type_support_data_t _GetOtherRobotStates_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetOtherRobotStates_Request_message_typesupport_map = {
  2,
  "zmr_interfaces",
  &_GetOtherRobotStates_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetOtherRobotStates_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetOtherRobotStates_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetOtherRobotStates_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetOtherRobotStates_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zmr_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zmr_interfaces::srv::GetOtherRobotStates_Request>()
{
  return &::zmr_interfaces::srv::rosidl_typesupport_cpp::GetOtherRobotStates_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zmr_interfaces, srv, GetOtherRobotStates_Request)() {
  return get_message_type_support_handle<zmr_interfaces::srv::GetOtherRobotStates_Request>();
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
// #include "zmr_interfaces/srv/detail/get_other_robot_states__struct.hpp"
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

namespace zmr_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetOtherRobotStates_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetOtherRobotStates_Response_type_support_ids_t;

static const _GetOtherRobotStates_Response_type_support_ids_t _GetOtherRobotStates_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetOtherRobotStates_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetOtherRobotStates_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetOtherRobotStates_Response_type_support_symbol_names_t _GetOtherRobotStates_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zmr_interfaces, srv, GetOtherRobotStates_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zmr_interfaces, srv, GetOtherRobotStates_Response)),
  }
};

typedef struct _GetOtherRobotStates_Response_type_support_data_t
{
  void * data[2];
} _GetOtherRobotStates_Response_type_support_data_t;

static _GetOtherRobotStates_Response_type_support_data_t _GetOtherRobotStates_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetOtherRobotStates_Response_message_typesupport_map = {
  2,
  "zmr_interfaces",
  &_GetOtherRobotStates_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetOtherRobotStates_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetOtherRobotStates_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetOtherRobotStates_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetOtherRobotStates_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zmr_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zmr_interfaces::srv::GetOtherRobotStates_Response>()
{
  return &::zmr_interfaces::srv::rosidl_typesupport_cpp::GetOtherRobotStates_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zmr_interfaces, srv, GetOtherRobotStates_Response)() {
  return get_message_type_support_handle<zmr_interfaces::srv::GetOtherRobotStates_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "zmr_interfaces/srv/detail/get_other_robot_states__struct.hpp"
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

namespace zmr_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _GetOtherRobotStates_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetOtherRobotStates_type_support_ids_t;

static const _GetOtherRobotStates_type_support_ids_t _GetOtherRobotStates_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetOtherRobotStates_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetOtherRobotStates_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetOtherRobotStates_type_support_symbol_names_t _GetOtherRobotStates_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zmr_interfaces, srv, GetOtherRobotStates)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zmr_interfaces, srv, GetOtherRobotStates)),
  }
};

typedef struct _GetOtherRobotStates_type_support_data_t
{
  void * data[2];
} _GetOtherRobotStates_type_support_data_t;

static _GetOtherRobotStates_type_support_data_t _GetOtherRobotStates_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetOtherRobotStates_service_typesupport_map = {
  2,
  "zmr_interfaces",
  &_GetOtherRobotStates_service_typesupport_ids.typesupport_identifier[0],
  &_GetOtherRobotStates_service_typesupport_symbol_names.symbol_name[0],
  &_GetOtherRobotStates_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetOtherRobotStates_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetOtherRobotStates_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace zmr_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<zmr_interfaces::srv::GetOtherRobotStates>()
{
  return &::zmr_interfaces::srv::rosidl_typesupport_cpp::GetOtherRobotStates_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, zmr_interfaces, srv, GetOtherRobotStates)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<zmr_interfaces::srv::GetOtherRobotStates>();
}

#ifdef __cplusplus
}
#endif
