// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mps_interfaces:srv/GetInflatedMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mps_interfaces/srv/detail/get_inflated_map__rosidl_typesupport_introspection_c.h"
#include "mps_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mps_interfaces/srv/detail/get_inflated_map__functions.h"
#include "mps_interfaces/srv/detail/get_inflated_map__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mps_interfaces__srv__GetInflatedMap_Request__init(message_memory);
}

void mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_fini_function(void * message_memory)
{
  mps_interfaces__srv__GetInflatedMap_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_member_array[1] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__srv__GetInflatedMap_Request, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_members = {
  "mps_interfaces__srv",  // message namespace
  "GetInflatedMap_Request",  // message name
  1,  // number of fields
  sizeof(mps_interfaces__srv__GetInflatedMap_Request),
  mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_member_array,  // message members
  mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_type_support_handle = {
  0,
  &mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mps_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap_Request)() {
  if (!mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_type_support_handle.typesupport_identifier) {
    mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mps_interfaces__srv__GetInflatedMap_Request__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "mps_interfaces/srv/detail/get_inflated_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "mps_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "mps_interfaces/srv/detail/get_inflated_map__functions.h"
// already included above
// #include "mps_interfaces/srv/detail/get_inflated_map__struct.h"


// Include directives for member types
// Member `inflated_map`
#include "map_interfaces/msg/geometric_map.h"
// Member `inflated_map`
#include "map_interfaces/msg/detail/geometric_map__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mps_interfaces__srv__GetInflatedMap_Response__init(message_memory);
}

void mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_fini_function(void * message_memory)
{
  mps_interfaces__srv__GetInflatedMap_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_member_array[1] = {
  {
    "inflated_map",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__srv__GetInflatedMap_Response, inflated_map),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_members = {
  "mps_interfaces__srv",  // message namespace
  "GetInflatedMap_Response",  // message name
  1,  // number of fields
  sizeof(mps_interfaces__srv__GetInflatedMap_Response),
  mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_member_array,  // message members
  mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_type_support_handle = {
  0,
  &mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mps_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap_Response)() {
  mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, GeometricMap)();
  if (!mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_type_support_handle.typesupport_identifier) {
    mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mps_interfaces__srv__GetInflatedMap_Response__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mps_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "mps_interfaces/srv/detail/get_inflated_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_members = {
  "mps_interfaces__srv",  // service namespace
  "GetInflatedMap",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_Request_message_type_support_handle,
  NULL  // response message
  // mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_Response_message_type_support_handle
};

static rosidl_service_type_support_t mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_type_support_handle = {
  0,
  &mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mps_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap)() {
  if (!mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_type_support_handle.typesupport_identifier) {
    mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, srv, GetInflatedMap_Response)()->data;
  }

  return &mps_interfaces__srv__detail__get_inflated_map__rosidl_typesupport_introspection_c__GetInflatedMap_service_type_support_handle;
}
