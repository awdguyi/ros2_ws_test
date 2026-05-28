// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE__STRUCT_H_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'schedule_name'
// Member 'node_names'
#include "rosidl_runtime_c/string.h"
// Member 'node_ids'
// Member 'etas'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Schedule in the package mps_interfaces.
/**
  * A schedule of a robot indicates the time and location.
 */
typedef struct mps_interfaces__msg__Schedule
{
  /// Identifier of the schedule
  /// XXX not used yet
  rosidl_runtime_c__String schedule_name;
  /// schedule content
  int16_t robot_id;
  rosidl_runtime_c__int16__Sequence node_ids;
  rosidl_runtime_c__String__Sequence node_names;
  rosidl_runtime_c__float__Sequence etas;
} mps_interfaces__msg__Schedule;

// Struct for a sequence of mps_interfaces__msg__Schedule.
typedef struct mps_interfaces__msg__Schedule__Sequence
{
  mps_interfaces__msg__Schedule * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__msg__Schedule__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE__STRUCT_H_
