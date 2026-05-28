// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE__FUNCTIONS_H_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mps_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mps_interfaces/msg/detail/schedule__struct.h"

/// Initialize msg/Schedule message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mps_interfaces__msg__Schedule
 * )) before or use
 * mps_interfaces__msg__Schedule__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__Schedule__init(mps_interfaces__msg__Schedule * msg);

/// Finalize msg/Schedule message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__Schedule__fini(mps_interfaces__msg__Schedule * msg);

/// Create msg/Schedule message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mps_interfaces__msg__Schedule__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
mps_interfaces__msg__Schedule *
mps_interfaces__msg__Schedule__create();

/// Destroy msg/Schedule message.
/**
 * It calls
 * mps_interfaces__msg__Schedule__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__Schedule__destroy(mps_interfaces__msg__Schedule * msg);

/// Check for msg/Schedule message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__Schedule__are_equal(const mps_interfaces__msg__Schedule * lhs, const mps_interfaces__msg__Schedule * rhs);

/// Copy a msg/Schedule message.
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
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__Schedule__copy(
  const mps_interfaces__msg__Schedule * input,
  mps_interfaces__msg__Schedule * output);

/// Initialize array of msg/Schedule messages.
/**
 * It allocates the memory for the number of elements and calls
 * mps_interfaces__msg__Schedule__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__Schedule__Sequence__init(mps_interfaces__msg__Schedule__Sequence * array, size_t size);

/// Finalize array of msg/Schedule messages.
/**
 * It calls
 * mps_interfaces__msg__Schedule__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__Schedule__Sequence__fini(mps_interfaces__msg__Schedule__Sequence * array);

/// Create array of msg/Schedule messages.
/**
 * It allocates the memory for the array and calls
 * mps_interfaces__msg__Schedule__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
mps_interfaces__msg__Schedule__Sequence *
mps_interfaces__msg__Schedule__Sequence__create(size_t size);

/// Destroy array of msg/Schedule messages.
/**
 * It calls
 * mps_interfaces__msg__Schedule__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__Schedule__Sequence__destroy(mps_interfaces__msg__Schedule__Sequence * array);

/// Check for msg/Schedule message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__Schedule__Sequence__are_equal(const mps_interfaces__msg__Schedule__Sequence * lhs, const mps_interfaces__msg__Schedule__Sequence * rhs);

/// Copy an array of msg/Schedule messages.
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
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__Schedule__Sequence__copy(
  const mps_interfaces__msg__Schedule__Sequence * input,
  mps_interfaces__msg__Schedule__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE__FUNCTIONS_H_
