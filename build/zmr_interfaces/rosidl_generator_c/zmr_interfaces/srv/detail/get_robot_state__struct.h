// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zmr_interfaces:srv/GetRobotState.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_H_
#define ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetRobotState in the package zmr_interfaces.
typedef struct zmr_interfaces__srv__GetRobotState_Request
{
  int64_t robot_id;
} zmr_interfaces__srv__GetRobotState_Request;

// Struct for a sequence of zmr_interfaces__srv__GetRobotState_Request.
typedef struct zmr_interfaces__srv__GetRobotState_Request__Sequence
{
  zmr_interfaces__srv__GetRobotState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zmr_interfaces__srv__GetRobotState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'robot_state'
// Member 'future_states'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetRobotState in the package zmr_interfaces.
typedef struct zmr_interfaces__srv__GetRobotState_Response
{
  rosidl_runtime_c__float__Sequence robot_state;
  rosidl_runtime_c__float__Sequence future_states;
} zmr_interfaces__srv__GetRobotState_Response;

// Struct for a sequence of zmr_interfaces__srv__GetRobotState_Response.
typedef struct zmr_interfaces__srv__GetRobotState_Response__Sequence
{
  zmr_interfaces__srv__GetRobotState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zmr_interfaces__srv__GetRobotState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_H_
