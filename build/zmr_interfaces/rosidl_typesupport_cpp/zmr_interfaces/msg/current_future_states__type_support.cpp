// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "zmr_interfaces/msg/detail/current_future_states__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace zmr_interfaces
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _CurrentFutureStates_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CurrentFutureStates_type_support_ids_t;

static const _CurrentFutureStates_type_support_ids_t _CurrentFutureStates_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _CurrentFutureStates_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CurrentFutureStates_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CurrentFutureStates_type_support_symbol_names_t _CurrentFutureStates_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zmr_interfaces, msg, CurrentFutureStates)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, zmr_interfaces, msg, CurrentFutureStates)),
  }
};

typedef struct _CurrentFutureStates_type_support_data_t
{
  void * data[2];
} _CurrentFutureStates_type_support_data_t;

static _CurrentFutureStates_type_support_data_t _CurrentFutureStates_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CurrentFutureStates_message_typesupport_map = {
  2,
  "zmr_interfaces",
  &_CurrentFutureStates_message_typesupport_ids.typesupport_identifier[0],
  &_CurrentFutureStates_message_typesupport_symbol_names.symbol_name[0],
  &_CurrentFutureStates_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CurrentFutureStates_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CurrentFutureStates_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace zmr_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<zmr_interfaces::msg::CurrentFutureStates>()
{
  return &::zmr_interfaces::msg::rosidl_typesupport_cpp::CurrentFutureStates_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, zmr_interfaces, msg, CurrentFutureStates)() {
  return get_message_type_support_handle<zmr_interfaces::msg::CurrentFutureStates>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
