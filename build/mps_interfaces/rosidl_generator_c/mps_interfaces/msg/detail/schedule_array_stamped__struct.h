// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:msg/ScheduleArrayStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY_STAMPED__STRUCT_H_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY_STAMPED__STRUCT_H_

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
// Member 'schedules'
#include "mps_interfaces/msg/detail/schedule_array__struct.h"

/// Struct defined in msg/ScheduleArrayStamped in the package mps_interfaces.
/**
  * Array of schedules, stamped
 */
typedef struct mps_interfaces__msg__ScheduleArrayStamped
{
  /// Header with frame_id and timestamp
  std_msgs__msg__Header header;
  /// Array of schedules
  mps_interfaces__msg__ScheduleArray schedules;
} mps_interfaces__msg__ScheduleArrayStamped;

// Struct for a sequence of mps_interfaces__msg__ScheduleArrayStamped.
typedef struct mps_interfaces__msg__ScheduleArrayStamped__Sequence
{
  mps_interfaces__msg__ScheduleArrayStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__msg__ScheduleArrayStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY_STAMPED__STRUCT_H_
