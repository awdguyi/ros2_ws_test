// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmp_interfaces:msg/HumanTrajectoryArray.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__STRUCT_H_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'human_trajectories'
#include "mmp_interfaces/msg/detail/human_trajectory__struct.h"

/// Struct defined in msg/HumanTrajectoryArray in the package mmp_interfaces.
/**
  * Trajectory array
 */
typedef struct mmp_interfaces__msg__HumanTrajectoryArray
{
  mmp_interfaces__msg__HumanTrajectory__Sequence human_trajectories;
} mmp_interfaces__msg__HumanTrajectoryArray;

// Struct for a sequence of mmp_interfaces__msg__HumanTrajectoryArray.
typedef struct mmp_interfaces__msg__HumanTrajectoryArray__Sequence
{
  mmp_interfaces__msg__HumanTrajectoryArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmp_interfaces__msg__HumanTrajectoryArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__STRUCT_H_
