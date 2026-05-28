// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__FUNCTIONS_H_
#define ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "zmr_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "zmr_interfaces/msg/detail/current_future_states__struct.h"

/// Initialize msg/CurrentFutureStates message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * zmr_interfaces__msg__CurrentFutureStates
 * )) before or use
 * zmr_interfaces__msg__CurrentFutureStates__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
bool
zmr_interfaces__msg__CurrentFutureStates__init(zmr_interfaces__msg__CurrentFutureStates * msg);

/// Finalize msg/CurrentFutureStates message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
void
zmr_interfaces__msg__CurrentFutureStates__fini(zmr_interfaces__msg__CurrentFutureStates * msg);

/// Create msg/CurrentFutureStates message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * zmr_interfaces__msg__CurrentFutureStates__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
zmr_interfaces__msg__CurrentFutureStates *
zmr_interfaces__msg__CurrentFutureStates__create();

/// Destroy msg/CurrentFutureStates message.
/**
 * It calls
 * zmr_interfaces__msg__CurrentFutureStates__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
void
zmr_interfaces__msg__CurrentFutureStates__destroy(zmr_interfaces__msg__CurrentFutureStates * msg);

/// Check for msg/CurrentFutureStates message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
bool
zmr_interfaces__msg__CurrentFutureStates__are_equal(const zmr_interfaces__msg__CurrentFutureStates * lhs, const zmr_interfaces__msg__CurrentFutureStates * rhs);

/// Copy a msg/CurrentFutureStates message.
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
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
bool
zmr_interfaces__msg__CurrentFutureStates__copy(
  const zmr_interfaces__msg__CurrentFutureStates * input,
  zmr_interfaces__msg__CurrentFutureStates * output);

/// Initialize array of msg/CurrentFutureStates messages.
/**
 * It allocates the memory for the number of elements and calls
 * zmr_interfaces__msg__CurrentFutureStates__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
bool
zmr_interfaces__msg__CurrentFutureStates__Sequence__init(zmr_interfaces__msg__CurrentFutureStates__Sequence * array, size_t size);

/// Finalize array of msg/CurrentFutureStates messages.
/**
 * It calls
 * zmr_interfaces__msg__CurrentFutureStates__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
void
zmr_interfaces__msg__CurrentFutureStates__Sequence__fini(zmr_interfaces__msg__CurrentFutureStates__Sequence * array);

/// Create array of msg/CurrentFutureStates messages.
/**
 * It allocates the memory for the array and calls
 * zmr_interfaces__msg__CurrentFutureStates__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
zmr_interfaces__msg__CurrentFutureStates__Sequence *
zmr_interfaces__msg__CurrentFutureStates__Sequence__create(size_t size);

/// Destroy array of msg/CurrentFutureStates messages.
/**
 * It calls
 * zmr_interfaces__msg__CurrentFutureStates__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
void
zmr_interfaces__msg__CurrentFutureStates__Sequence__destroy(zmr_interfaces__msg__CurrentFutureStates__Sequence * array);

/// Check for msg/CurrentFutureStates message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
bool
zmr_interfaces__msg__CurrentFutureStates__Sequence__are_equal(const zmr_interfaces__msg__CurrentFutureStates__Sequence * lhs, const zmr_interfaces__msg__CurrentFutureStates__Sequence * rhs);

/// Copy an array of msg/CurrentFutureStates messages.
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
ROSIDL_GENERATOR_C_PUBLIC_zmr_interfaces
bool
zmr_interfaces__msg__CurrentFutureStates__Sequence__copy(
  const zmr_interfaces__msg__CurrentFutureStates__Sequence * input,
  zmr_interfaces__msg__CurrentFutureStates__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__FUNCTIONS_H_
