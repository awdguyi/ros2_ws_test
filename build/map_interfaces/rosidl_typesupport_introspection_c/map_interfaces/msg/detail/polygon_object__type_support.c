// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "map_interfaces/msg/detail/polygon_object__rosidl_typesupport_introspection_c.h"
#include "map_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "map_interfaces/msg/detail/polygon_object__functions.h"
#include "map_interfaces/msg/detail/polygon_object__struct.h"


// Include directives for member types
// Member `object_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `polygon`
#include "geometry_msgs/msg/polygon.h"
// Member `polygon`
#include "geometry_msgs/msg/detail/polygon__rosidl_typesupport_introspection_c.h"
// Member `centroid`
#include "geometry_msgs/msg/point32.h"
// Member `centroid`
#include "geometry_msgs/msg/detail/point32__rosidl_typesupport_introspection_c.h"
// Member `object_shape_t`
#include "map_interfaces/msg/object_shape_type.h"
// Member `object_shape_t`
#include "map_interfaces/msg/detail/object_shape_type__rosidl_typesupport_introspection_c.h"
// Member `object_motion_t`
#include "map_interfaces/msg/object_motion_type.h"
// Member `object_motion_t`
#include "map_interfaces/msg/detail/object_motion_type__rosidl_typesupport_introspection_c.h"
// Member `object_semantic_t`
#include "map_interfaces/msg/object_semantic_type.h"
// Member `object_semantic_t`
#include "map_interfaces/msg/detail/object_semantic_type__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  map_interfaces__msg__PolygonObject__init(message_memory);
}

void map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_fini_function(void * message_memory)
{
  map_interfaces__msg__PolygonObject__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array[7] = {
  {
    "object_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, object_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, object_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "polygon",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, polygon),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "centroid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, centroid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_shape_t",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, object_shape_t),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_motion_t",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, object_motion_t),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_semantic_t",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces__msg__PolygonObject, object_semantic_t),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_members = {
  "map_interfaces__msg",  // message namespace
  "PolygonObject",  // message name
  7,  // number of fields
  sizeof(map_interfaces__msg__PolygonObject),
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array,  // message members
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_init_function,  // function to initialize message memory (memory has to be allocated)
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_type_support_handle = {
  0,
  &map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_map_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, PolygonObject)() {
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Polygon)();
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, ObjectShapeType)();
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, ObjectMotionType)();
  map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, map_interfaces, msg, ObjectSemanticType)();
  if (!map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_type_support_handle.typesupport_identifier) {
    map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &map_interfaces__msg__PolygonObject__rosidl_typesupport_introspection_c__PolygonObject_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
