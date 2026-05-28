// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mps_interfaces:msg/PathScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__FUNCTIONS_H_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mps_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mps_interfaces/msg/detail/path_schedule_stamped__struct.h"

/// Initialize msg/PathScheduleStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mps_interfaces__msg__PathScheduleStamped
 * )) before or use
 * mps_interfaces__msg__PathScheduleStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__PathScheduleStamped__init(mps_interfaces__msg__PathScheduleStamped * msg);

/// Finalize msg/PathScheduleStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__PathScheduleStamped__fini(mps_interfaces__msg__PathScheduleStamped * msg);

/// Create msg/PathScheduleStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mps_interfaces__msg__PathScheduleStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
mps_interfaces__msg__PathScheduleStamped *
mps_interfaces__msg__PathScheduleStamped__create();

/// Destroy msg/PathScheduleStamped message.
/**
 * It calls
 * mps_interfaces__msg__PathScheduleStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__PathScheduleStamped__destroy(mps_interfaces__msg__PathScheduleStamped * msg);

/// Check for msg/PathScheduleStamped message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__PathScheduleStamped__are_equal(const mps_interfaces__msg__PathScheduleStamped * lhs, const mps_interfaces__msg__PathScheduleStamped * rhs);

/// Copy a msg/PathScheduleStamped message.
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
mps_interfaces__msg__PathScheduleStamped__copy(
  const mps_interfaces__msg__PathScheduleStamped * input,
  mps_interfaces__msg__PathScheduleStamped * output);

/// Initialize array of msg/PathScheduleStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * mps_interfaces__msg__PathScheduleStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__PathScheduleStamped__Sequence__init(mps_interfaces__msg__PathScheduleStamped__Sequence * array, size_t size);

/// Finalize array of msg/PathScheduleStamped messages.
/**
 * It calls
 * mps_interfaces__msg__PathScheduleStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__PathScheduleStamped__Sequence__fini(mps_interfaces__msg__PathScheduleStamped__Sequence * array);

/// Create array of msg/PathScheduleStamped messages.
/**
 * It allocates the memory for the array and calls
 * mps_interfaces__msg__PathScheduleStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
mps_interfaces__msg__PathScheduleStamped__Sequence *
mps_interfaces__msg__PathScheduleStamped__Sequence__create(size_t size);

/// Destroy array of msg/PathScheduleStamped messages.
/**
 * It calls
 * mps_interfaces__msg__PathScheduleStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__PathScheduleStamped__Sequence__destroy(mps_interfaces__msg__PathScheduleStamped__Sequence * array);

/// Check for msg/PathScheduleStamped message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__PathScheduleStamped__Sequence__are_equal(const mps_interfaces__msg__PathScheduleStamped__Sequence * lhs, const mps_interfaces__msg__PathScheduleStamped__Sequence * rhs);

/// Copy an array of msg/PathScheduleStamped messages.
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
mps_interfaces__msg__PathScheduleStamped__Sequence__copy(
  const mps_interfaces__msg__PathScheduleStamped__Sequence * input,
  mps_interfaces__msg__PathScheduleStamped__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__FUNCTIONS_H_
