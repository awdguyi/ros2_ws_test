// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__STRUCT_H_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'schedules'
#include "mps_interfaces/msg/detail/schedule__struct.h"

/// Struct defined in msg/ScheduleArray in the package mps_interfaces.
/**
  * Array of schedules
 */
typedef struct mps_interfaces__msg__ScheduleArray
{
  mps_interfaces__msg__Schedule__Sequence schedules;
} mps_interfaces__msg__ScheduleArray;

// Struct for a sequence of mps_interfaces__msg__ScheduleArray.
typedef struct mps_interfaces__msg__ScheduleArray__Sequence
{
  mps_interfaces__msg__ScheduleArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__msg__ScheduleArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__STRUCT_H_
