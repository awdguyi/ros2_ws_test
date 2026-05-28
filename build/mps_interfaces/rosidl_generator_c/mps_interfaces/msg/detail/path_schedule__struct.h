// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__STRUCT_H_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_coords'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'path_times'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/PathSchedule in the package mps_interfaces.
/**
  * A path schedule of a robot indicates the time and real location.
 */
typedef struct mps_interfaces__msg__PathSchedule
{
  /// schedule content
  int16_t robot_id;
  geometry_msgs__msg__Point__Sequence path_coords;
  /// if, it is None
  rosidl_runtime_c__float__Sequence path_times;
} mps_interfaces__msg__PathSchedule;

// Struct for a sequence of mps_interfaces__msg__PathSchedule.
typedef struct mps_interfaces__msg__PathSchedule__Sequence
{
  mps_interfaces__msg__PathSchedule * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__msg__PathSchedule__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__STRUCT_H_
