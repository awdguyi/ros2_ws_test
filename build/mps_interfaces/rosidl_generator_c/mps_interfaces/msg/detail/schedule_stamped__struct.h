// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:msg/ScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__STRUCT_H_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__STRUCT_H_

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
// Member 'schedule'
#include "mps_interfaces/msg/detail/schedule__struct.h"

/// Struct defined in msg/ScheduleStamped in the package mps_interfaces.
/**
  * A schedule of a robot indicates the time and location, stamped
 */
typedef struct mps_interfaces__msg__ScheduleStamped
{
  /// Header with frame_id and timestamp
  std_msgs__msg__Header header;
  mps_interfaces__msg__Schedule schedule;
} mps_interfaces__msg__ScheduleStamped;

// Struct for a sequence of mps_interfaces__msg__ScheduleStamped.
typedef struct mps_interfaces__msg__ScheduleStamped__Sequence
{
  mps_interfaces__msg__ScheduleStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__msg__ScheduleStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__STRUCT_H_
