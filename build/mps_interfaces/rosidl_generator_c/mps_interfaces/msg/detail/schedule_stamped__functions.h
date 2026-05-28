// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mps_interfaces:msg/ScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__FUNCTIONS_H_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mps_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mps_interfaces/msg/detail/schedule_stamped__struct.h"

/// Initialize msg/ScheduleStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mps_interfaces__msg__ScheduleStamped
 * )) before or use
 * mps_interfaces__msg__ScheduleStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__ScheduleStamped__init(mps_interfaces__msg__ScheduleStamped * msg);

/// Finalize msg/ScheduleStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__ScheduleStamped__fini(mps_interfaces__msg__ScheduleStamped * msg);

/// Create msg/ScheduleStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mps_interfaces__msg__ScheduleStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
mps_interfaces__msg__ScheduleStamped *
mps_interfaces__msg__ScheduleStamped__create();

/// Destroy msg/ScheduleStamped message.
/**
 * It calls
 * mps_interfaces__msg__ScheduleStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__ScheduleStamped__destroy(mps_interfaces__msg__ScheduleStamped * msg);

/// Check for msg/ScheduleStamped message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__ScheduleStamped__are_equal(const mps_interfaces__msg__ScheduleStamped * lhs, const mps_interfaces__msg__ScheduleStamped * rhs);

/// Copy a msg/ScheduleStamped message.
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
mps_interfaces__msg__ScheduleStamped__copy(
  const mps_interfaces__msg__ScheduleStamped * input,
  mps_interfaces__msg__ScheduleStamped * output);

/// Initialize array of msg/ScheduleStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * mps_interfaces__msg__ScheduleStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__ScheduleStamped__Sequence__init(mps_interfaces__msg__ScheduleStamped__Sequence * array, size_t size);

/// Finalize array of msg/ScheduleStamped messages.
/**
 * It calls
 * mps_interfaces__msg__ScheduleStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__ScheduleStamped__Sequence__fini(mps_interfaces__msg__ScheduleStamped__Sequence * array);

/// Create array of msg/ScheduleStamped messages.
/**
 * It allocates the memory for the array and calls
 * mps_interfaces__msg__ScheduleStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
mps_interfaces__msg__ScheduleStamped__Sequence *
mps_interfaces__msg__ScheduleStamped__Sequence__create(size_t size);

/// Destroy array of msg/ScheduleStamped messages.
/**
 * It calls
 * mps_interfaces__msg__ScheduleStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
void
mps_interfaces__msg__ScheduleStamped__Sequence__destroy(mps_interfaces__msg__ScheduleStamped__Sequence * array);

/// Check for msg/ScheduleStamped message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mps_interfaces
bool
mps_interfaces__msg__ScheduleStamped__Sequence__are_equal(const mps_interfaces__msg__ScheduleStamped__Sequence * lhs, const mps_interfaces__msg__ScheduleStamped__Sequence * rhs);

/// Copy an array of msg/ScheduleStamped messages.
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
mps_interfaces__msg__ScheduleStamped__Sequence__copy(
  const mps_interfaces__msg__ScheduleStamped__Sequence * input,
  mps_interfaces__msg__ScheduleStamped__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__FUNCTIONS_H_
