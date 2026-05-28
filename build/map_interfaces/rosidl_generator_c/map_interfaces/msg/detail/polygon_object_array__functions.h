// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__FUNCTIONS_H_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "map_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "map_interfaces/msg/detail/polygon_object_array__struct.h"

/// Initialize msg/PolygonObjectArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * map_interfaces__msg__PolygonObjectArray
 * )) before or use
 * map_interfaces__msg__PolygonObjectArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__PolygonObjectArray__init(map_interfaces__msg__PolygonObjectArray * msg);

/// Finalize msg/PolygonObjectArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__PolygonObjectArray__fini(map_interfaces__msg__PolygonObjectArray * msg);

/// Create msg/PolygonObjectArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * map_interfaces__msg__PolygonObjectArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
map_interfaces__msg__PolygonObjectArray *
map_interfaces__msg__PolygonObjectArray__create();

/// Destroy msg/PolygonObjectArray message.
/**
 * It calls
 * map_interfaces__msg__PolygonObjectArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__PolygonObjectArray__destroy(map_interfaces__msg__PolygonObjectArray * msg);

/// Check for msg/PolygonObjectArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__PolygonObjectArray__are_equal(const map_interfaces__msg__PolygonObjectArray * lhs, const map_interfaces__msg__PolygonObjectArray * rhs);

/// Copy a msg/PolygonObjectArray message.
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
map_interfaces__msg__PolygonObjectArray__copy(
  const map_interfaces__msg__PolygonObjectArray * input,
  map_interfaces__msg__PolygonObjectArray * output);

/// Initialize array of msg/PolygonObjectArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * map_interfaces__msg__PolygonObjectArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__PolygonObjectArray__Sequence__init(map_interfaces__msg__PolygonObjectArray__Sequence * array, size_t size);

/// Finalize array of msg/PolygonObjectArray messages.
/**
 * It calls
 * map_interfaces__msg__PolygonObjectArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__PolygonObjectArray__Sequence__fini(map_interfaces__msg__PolygonObjectArray__Sequence * array);

/// Create array of msg/PolygonObjectArray messages.
/**
 * It allocates the memory for the array and calls
 * map_interfaces__msg__PolygonObjectArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
map_interfaces__msg__PolygonObjectArray__Sequence *
map_interfaces__msg__PolygonObjectArray__Sequence__create(size_t size);

/// Destroy array of msg/PolygonObjectArray messages.
/**
 * It calls
 * map_interfaces__msg__PolygonObjectArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
void
map_interfaces__msg__PolygonObjectArray__Sequence__destroy(map_interfaces__msg__PolygonObjectArray__Sequence * array);

/// Check for msg/PolygonObjectArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_interfaces
bool
map_interfaces__msg__PolygonObjectArray__Sequence__are_equal(const map_interfaces__msg__PolygonObjectArray__Sequence * lhs, const map_interfaces__msg__PolygonObjectArray__Sequence * rhs);

/// Copy an array of msg/PolygonObjectArray messages.
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
map_interfaces__msg__PolygonObjectArray__Sequence__copy(
  const map_interfaces__msg__PolygonObjectArray__Sequence * input,
  map_interfaces__msg__PolygonObjectArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__FUNCTIONS_H_
