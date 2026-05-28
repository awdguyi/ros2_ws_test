// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:srv/GetRobotSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__STRUCT_H_
#define MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetRobotSchedule in the package mps_interfaces.
typedef struct mps_interfaces__srv__GetRobotSchedule_Request
{
  int64_t robot_id;
  double current_time;
} mps_interfaces__srv__GetRobotSchedule_Request;

// Struct for a sequence of mps_interfaces__srv__GetRobotSchedule_Request.
typedef struct mps_interfaces__srv__GetRobotSchedule_Request__Sequence
{
  mps_interfaces__srv__GetRobotSchedule_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__srv__GetRobotSchedule_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'path_schedule'
#include "mps_interfaces/msg/detail/path_schedule_stamped__struct.h"

/// Struct defined in srv/GetRobotSchedule in the package mps_interfaces.
typedef struct mps_interfaces__srv__GetRobotSchedule_Response
{
  mps_interfaces__msg__PathScheduleStamped path_schedule;
} mps_interfaces__srv__GetRobotSchedule_Response;

// Struct for a sequence of mps_interfaces__srv__GetRobotSchedule_Response.
typedef struct mps_interfaces__srv__GetRobotSchedule_Response__Sequence
{
  mps_interfaces__srv__GetRobotSchedule_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__srv__GetRobotSchedule_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__STRUCT_H_
