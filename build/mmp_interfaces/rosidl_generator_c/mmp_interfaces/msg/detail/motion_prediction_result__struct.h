// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__STRUCT_H_
#define MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__STRUCT_H_

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
// Member 'mu_list_list'
// Member 'std_list_list'
// Member 'conf_list_list'
#include "mmp_interfaces/msg/detail/human_trajectory_array__struct.h"

/// Struct defined in msg/MotionPredictionResult in the package mmp_interfaces.
/**
  * Motion prediction
 */
typedef struct mmp_interfaces__msg__MotionPredictionResult
{
  /// header with frame_id and timestamp
  std_msgs__msg__Header header;
  /// [t1_list, t2_list, ...], t1_list = [mu1, mu2, ...],       mu1 = [x, y]
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence mu_list_list;
  /// [t1_list, t2_list, ...], t1_list = [std1, std2, ...],     std1 = [xx, yy]
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence std_list_list;
  /// [t1_list, t2_list, ...], t1_list = [conf1, conf2, ...],   conf1 = [c, c]
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence conf_list_list;
} mmp_interfaces__msg__MotionPredictionResult;

// Struct for a sequence of mmp_interfaces__msg__MotionPredictionResult.
typedef struct mmp_interfaces__msg__MotionPredictionResult__Sequence
{
  mmp_interfaces__msg__MotionPredictionResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmp_interfaces__msg__MotionPredictionResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__STRUCT_H_
