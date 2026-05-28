// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__FUNCTIONS_H_
#define MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mmp_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mmp_interfaces/msg/detail/motion_prediction_result__struct.h"

/// Initialize msg/MotionPredictionResult message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmp_interfaces__msg__MotionPredictionResult
 * )) before or use
 * mmp_interfaces__msg__MotionPredictionResult__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
bool
mmp_interfaces__msg__MotionPredictionResult__init(mmp_interfaces__msg__MotionPredictionResult * msg);

/// Finalize msg/MotionPredictionResult message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
void
mmp_interfaces__msg__MotionPredictionResult__fini(mmp_interfaces__msg__MotionPredictionResult * msg);

/// Create msg/MotionPredictionResult message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmp_interfaces__msg__MotionPredictionResult__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
mmp_interfaces__msg__MotionPredictionResult *
mmp_interfaces__msg__MotionPredictionResult__create();

/// Destroy msg/MotionPredictionResult message.
/**
 * It calls
 * mmp_interfaces__msg__MotionPredictionResult__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
void
mmp_interfaces__msg__MotionPredictionResult__destroy(mmp_interfaces__msg__MotionPredictionResult * msg);

/// Check for msg/MotionPredictionResult message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
bool
mmp_interfaces__msg__MotionPredictionResult__are_equal(const mmp_interfaces__msg__MotionPredictionResult * lhs, const mmp_interfaces__msg__MotionPredictionResult * rhs);

/// Copy a msg/MotionPredictionResult message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
bool
mmp_interfaces__msg__MotionPredictionResult__copy(
  const mmp_interfaces__msg__MotionPredictionResult * input,
  mmp_interfaces__msg__MotionPredictionResult * output);

/// Initialize array of msg/MotionPredictionResult messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmp_interfaces__msg__MotionPredictionResult__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
bool
mmp_interfaces__msg__MotionPredictionResult__Sequence__init(mmp_interfaces__msg__MotionPredictionResult__Sequence * array, size_t size);

/// Finalize array of msg/MotionPredictionResult messages.
/**
 * It calls
 * mmp_interfaces__msg__MotionPredictionResult__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
void
mmp_interfaces__msg__MotionPredictionResult__Sequence__fini(mmp_interfaces__msg__MotionPredictionResult__Sequence * array);

/// Create array of msg/MotionPredictionResult messages.
/**
 * It allocates the memory for the array and calls
 * mmp_interfaces__msg__MotionPredictionResult__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
mmp_interfaces__msg__MotionPredictionResult__Sequence *
mmp_interfaces__msg__MotionPredictionResult__Sequence__create(size_t size);

/// Destroy array of msg/MotionPredictionResult messages.
/**
 * It calls
 * mmp_interfaces__msg__MotionPredictionResult__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
void
mmp_interfaces__msg__MotionPredictionResult__Sequence__destroy(mmp_interfaces__msg__MotionPredictionResult__Sequence * array);

/// Check for msg/MotionPredictionResult message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
bool
mmp_interfaces__msg__MotionPredictionResult__Sequence__are_equal(const mmp_interfaces__msg__MotionPredictionResult__Sequence * lhs, const mmp_interfaces__msg__MotionPredictionResult__Sequence * rhs);

/// Copy an array of msg/MotionPredictionResult messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmp_interfaces
bool
mmp_interfaces__msg__MotionPredictionResult__Sequence__copy(
  const mmp_interfaces__msg__MotionPredictionResult__Sequence * input,
  mmp_interfaces__msg__MotionPredictionResult__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__FUNCTIONS_H_
