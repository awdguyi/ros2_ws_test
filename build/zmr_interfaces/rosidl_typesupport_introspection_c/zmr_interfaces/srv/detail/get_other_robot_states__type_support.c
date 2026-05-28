// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zmr_interfaces:srv/GetOtherRobotStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zmr_interfaces/srv/detail/get_other_robot_states__rosidl_typesupport_introspection_c.h"
#include "zmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zmr_interfaces/srv/detail/get_other_robot_states__functions.h"
#include "zmr_interfaces/srv/detail/get_other_robot_states__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zmr_interfaces__srv__GetOtherRobotStates_Request__init(message_memory);
}

void zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_fini_function(void * message_memory)
{
  zmr_interfaces__srv__GetOtherRobotStates_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_member_array[1] = {
  {
    "ego_robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zmr_interfaces__srv__GetOtherRobotStates_Request, ego_robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_members = {
  "zmr_interfaces__srv",  // message namespace
  "GetOtherRobotStates_Request",  // message name
  1,  // number of fields
  sizeof(zmr_interfaces__srv__GetOtherRobotStates_Request),
  zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_member_array,  // message members
  zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_type_support_handle = {
  0,
  &zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zmr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates_Request)() {
  if (!zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_type_support_handle.typesupport_identifier) {
    zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zmr_interfaces__srv__GetOtherRobotStates_Request__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "zmr_interfaces/srv/detail/get_other_robot_states__rosidl_typesupport_introspection_c.h"
// already included above
// #include "zmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "zmr_interfaces/srv/detail/get_other_robot_states__functions.h"
// already included above
// #include "zmr_interfaces/srv/detail/get_other_robot_states__struct.h"


// Include directives for member types
// Member `other_robot_states_in_order`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zmr_interfaces__srv__GetOtherRobotStates_Response__init(message_memory);
}

void zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_fini_function(void * message_memory)
{
  zmr_interfaces__srv__GetOtherRobotStates_Response__fini(message_memory);
}

size_t zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__size_function__GetOtherRobotStates_Response__other_robot_states_in_order(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__get_const_function__GetOtherRobotStates_Response__other_robot_states_in_order(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__get_function__GetOtherRobotStates_Response__other_robot_states_in_order(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__fetch_function__GetOtherRobotStates_Response__other_robot_states_in_order(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__get_const_function__GetOtherRobotStates_Response__other_robot_states_in_order(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__assign_function__GetOtherRobotStates_Response__other_robot_states_in_order(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__get_function__GetOtherRobotStates_Response__other_robot_states_in_order(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__resize_function__GetOtherRobotStates_Response__other_robot_states_in_order(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_member_array[1] = {
  {
    "other_robot_states_in_order",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zmr_interfaces__srv__GetOtherRobotStates_Response, other_robot_states_in_order),  // bytes offset in struct
    NULL,  // default value
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__size_function__GetOtherRobotStates_Response__other_robot_states_in_order,  // size() function pointer
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__get_const_function__GetOtherRobotStates_Response__other_robot_states_in_order,  // get_const(index) function pointer
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__get_function__GetOtherRobotStates_Response__other_robot_states_in_order,  // get(index) function pointer
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__fetch_function__GetOtherRobotStates_Response__other_robot_states_in_order,  // fetch(index, &value) function pointer
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__assign_function__GetOtherRobotStates_Response__other_robot_states_in_order,  // assign(index, value) function pointer
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__resize_function__GetOtherRobotStates_Response__other_robot_states_in_order  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_members = {
  "zmr_interfaces__srv",  // message namespace
  "GetOtherRobotStates_Response",  // message name
  1,  // number of fields
  sizeof(zmr_interfaces__srv__GetOtherRobotStates_Response),
  zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_member_array,  // message members
  zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_type_support_handle = {
  0,
  &zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zmr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates_Response)() {
  if (!zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_type_support_handle.typesupport_identifier) {
    zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zmr_interfaces__srv__GetOtherRobotStates_Response__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "zmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "zmr_interfaces/srv/detail/get_other_robot_states__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_members = {
  "zmr_interfaces__srv",  // service namespace
  "GetOtherRobotStates",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_Request_message_type_support_handle,
  NULL  // response message
  // zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_Response_message_type_support_handle
};

static rosidl_service_type_support_t zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_type_support_handle = {
  0,
  &zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zmr_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates)() {
  if (!zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_type_support_handle.typesupport_identifier) {
    zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, srv, GetOtherRobotStates_Response)()->data;
  }

  return &zmr_interfaces__srv__detail__get_other_robot_states__rosidl_typesupport_introspection_c__GetOtherRobotStates_service_type_support_handle;
}
