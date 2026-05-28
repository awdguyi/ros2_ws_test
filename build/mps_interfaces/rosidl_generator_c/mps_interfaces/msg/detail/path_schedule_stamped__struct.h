// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:msg/PathScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__STRUCT_H_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'path_schedule'
#include "mps_interfaces/msg/detail/path_schedule__struct.h"

/// Struct defined in msg/PathScheduleStamped in the package mps_interfaces.
/**
  * A path schedule of a robot indicates the time and real location, stamped 
 */
typedef struct mps_interfaces__msg__PathScheduleStamped
{
  /// Header with frame_id and timestamp
  std_msgs__msg__Header header;
  mps_interfaces__msg__PathSchedule path_schedule;
} mps_interfaces__msg__PathScheduleStamped;

// Struct for a sequence of mps_interfaces__msg__PathScheduleStamped.
typedef struct mps_interfaces__msg__PathScheduleStamped__Sequence
{
  mps_interfaces__msg__PathScheduleStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__msg__PathScheduleStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__STRUCT_H_
