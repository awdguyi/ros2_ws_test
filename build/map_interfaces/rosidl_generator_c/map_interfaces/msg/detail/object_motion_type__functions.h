// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from map_interfaces:msg/ObjectMotionType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__FUNCTIONS_H_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "map_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "map_interfaces/msg/detail/object_motion_type__struct.h"

/// Initialize msg/ObjectMotionType message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * map_interfaces__msg__ObjectMotionType
 * )) before or use
 * map_interfaces__msg__ObjectMotionType__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__ObjectMotionType__init(map_interfaces__msg__ObjectMotionType * msg);

/// Finalize msg/ObjectMotionType message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__ObjectMotionType__fini(map_interfaces__msg__ObjectMotionType * msg);

/// Create msg/ObjectMotionType message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * map_interfaces__msg__ObjectMotionType__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
map_interfaces__msg__ObjectMotionType *
map_interfaces__msg__ObjectMotionType__create();

/// Destroy msg/ObjectMotionType message.
/**
 * It calls
 * map_interfaces__msg__ObjectMotionType__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__ObjectMotionType__destroy(map_interfaces__msg__ObjectMotionType * msg);

/// Check for msg/ObjectMotionType message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__ObjectMotionType__are_equal(const map_interfaces__msg__ObjectMotionType * lhs, const map_interfaces__msg__ObjectMotionType * rhs);

/// Copy a msg/ObjectMotionType message.
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
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__ObjectMotionType__copy(
  const map_interfaces__msg__ObjectMotionType * input,
  map_interfaces__msg__ObjectMotionType * output);

/// Initialize array of msg/ObjectMotionType messages.
/**
 * It allocates the memory for the number of elements and calls
 * map_interfaces__msg__ObjectMotionType__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__ObjectMotionType__Sequence__init(map_interfaces__msg__ObjectMotionType__Sequence * array, size_t size);

/// Finalize array of msg/ObjectMotionType messages.
/**
 * It calls
 * map_interfaces__msg__ObjectMotionType__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__ObjectMotionType__Sequence__fini(map_interfaces__msg__ObjectMotionType__Sequence * array);

/// Create array of msg/ObjectMotionType messages.
/**
 * It allocates the memory for the array and calls
 * map_interfaces__msg__ObjectMotionType__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
map_interfaces__msg__ObjectMotionType__Sequence *
map_interfaces__msg__ObjectMotionType__Sequence__create(size_t size);

/// Destroy array of msg/ObjectMotionType messages.
/**
 * It calls
 * map_interfaces__msg__ObjectMotionType__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__ObjectMotionType__Sequence__destroy(map_interfaces__msg__ObjectMotionType__Sequence * array);

/// Check for msg/ObjectMotionType message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__ObjectMotionType__Sequence__are_equal(const map_interfaces__msg__ObjectMotionType__Sequence * lhs, const map_interfaces__msg__ObjectMotionType__Sequence * rhs);

/// Copy an array of msg/ObjectMotionType messages.
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
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__ObjectMotionType__Sequence__copy(
  const map_interfaces__msg__ObjectMotionType__Sequence * input,
  map_interfaces__msg__ObjectMotionType__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__FUNCTIONS_H_
