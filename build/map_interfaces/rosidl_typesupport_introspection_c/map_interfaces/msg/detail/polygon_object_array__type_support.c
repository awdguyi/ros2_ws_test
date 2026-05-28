// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "map_interfaces/msg/detail/polygon_object_array__rosidl_typesupport_introspection_c.h"
#include "map_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "map_interfaces/msg/detail/polygon_object_array__functions.h"
#include "map_interfaces/msg/detail/polygon_object_array__struct.h"


// Include directives for member types
// Member `polygon_objects`
#include "map_interfaces/msg/polygon_object.h"
// Member `polygon_objects`
#include "map_interfaces/msg/detail/polygon_object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  map_interfaces__msg__PolygonObjectArray__init(message_memory);
}

void map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_fini_function(void * message_memory)
{
  map_interfaces__msg__PolygonObjectArray__fini(message_memory);
}

size_t map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__size_function__PolygonObjectArray__polygon_objects(
  const void * untyped_member)
{
  const map_interfaces__msg__PolygonObject__Sequence * member =
    (const map_interfaces__msg__PolygonObject__Sequence *)(untyped_member);
  return member->size;
}

const void * map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__get_const_function__PolygonObjectArray__polygon_objects(
  const void * untyped_member, size_t index)
{
  const map_interfaces__msg__PolygonObject__Sequence * member =
    (const map_interfaces__msg__PolygonObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void * map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__get_function__PolygonObjectArray__polygon_objects(
  void * untyped_member, size_t index)
{
  map_interfaces__msg__PolygonObject__Sequence * member =
    (map_interfaces__msg__PolygonObject__Sequence *)(untyped_member);
  return &member->data[index];
}

void map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__fetch_function__PolygonObjectArray__polygon_objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const map_interfaces__msg__PolygonObject * item =
    ((const map_interfaces__msg__PolygonObject *)
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__get_const_function__PolygonObjectArray__polygon_objects(untyped_member, index));
  map_interfaces__msg__PolygonObject * value =
    (map_interfaces__msg__PolygonObject *)(untyped_value);
  *value = *item;
}

void map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__assign_function__PolygonObjectArray__polygon_objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  map_interfaces__msg__PolygonObject * item =
    ((map_interfaces__msg__PolygonObject *)
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__get_function__PolygonObjectArray__polygon_objects(untyped_member, index));
  const map_interfaces__msg__PolygonObject * value =
    (const map_interfaces__msg__PolygonObject *)(untyped_value);
  *item = *value;
}

bool map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__resize_function__PolygonObjectArray__polygon_objects(
  void * untyped_member, size_t size)
{
  map_interfaces__msg__PolygonObject__Sequence * member =
    (map_interfaces__msg__PolygonObject__Sequence *)(untyped_member);
  map_interfaces__msg__PolygonObject__Sequence__fini(member);
  return map_interfaces__msg__PolygonObject__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_member_array[1] = {
  {
    "polygon_objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObjectArray, polygon_objects),  // bytes offset in struct
    NULL,  // default value
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__size_function__PolygonObjectArray__polygon_objects,  // size() function pointer
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__get_const_function__PolygonObjectArray__polygon_objects,  // get_const(index) function pointer
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__get_function__PolygonObjectArray__polygon_objects,  // get(index) function pointer
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__fetch_function__PolygonObjectArray__polygon_objects,  // fetch(index, &value) function pointer
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__assign_function__PolygonObjectArray__polygon_objects,  // assign(index, value) function pointer
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__resize_function__PolygonObjectArray__polygon_objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_members = {
  "map_interfaces__msg",  // message namespace
  "PolygonObjectArray",  // message name
  1,  // number of fields
  sizeof(map_interfaces__msg__PolygonObjectArray),
  map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_member_array,  // message members
  map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_init_function,  // function to initialize message memory (memory has to be allocated)
  map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_type_support_handle = {
  0,
  &map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_map_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, PolygonObjectArray)() {
  map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, PolygonObject)();
  if (!map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_type_support_handle.typesupport_identifier) {
    map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &map_interfaces__msg__PolygonObjectArray__rosidl_typesupport_introspection_c__PolygonObjectArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
