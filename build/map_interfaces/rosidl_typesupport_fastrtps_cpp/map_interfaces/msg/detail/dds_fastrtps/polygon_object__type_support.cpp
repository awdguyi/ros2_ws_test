// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice
#include "map_interfaces/msg/detail/polygon_object__rosidl_typesupport_fastrtps_cpp.hpp"
#include "map_interfaces/msg/detail/polygon_object__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Polygon &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Polygon &);
size_t get_serialized_size(
  const geometry_msgs::msg::Polygon &,
  size_t current_alignment);
size_t
max_serialized_size_Polygon(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Point32 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Point32 &);
size_t get_serialized_size(
  const geometry_msgs::msg::Point32 &,
  size_t current_alignment);
size_t
max_serialized_size_Point32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace map_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const map_interfaces::msg::ObjectShapeType &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  map_interfaces::msg::ObjectShapeType &);
size_t get_serialized_size(
  const map_interfaces::msg::ObjectShapeType &,
  size_t current_alignment);
size_t
max_serialized_size_ObjectShapeType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace map_interfaces

namespace map_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const map_interfaces::msg::ObjectMotionType &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  map_interfaces::msg::ObjectMotionType &);
size_t get_serialized_size(
  const map_interfaces::msg::ObjectMotionType &,
  size_t current_alignment);
size_t
max_serialized_size_ObjectMotionType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace map_interfaces

namespace map_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const map_interfaces::msg::ObjectSemanticType &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  map_interfaces::msg::ObjectSemanticType &);
size_t get_serialized_size(
  const map_interfaces::msg::ObjectSemanticType &,
  size_t current_alignment);
size_t
max_serialized_size_ObjectSemanticType(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace map_interfaces


namespace map_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
cdr_serialize(
  const map_interfaces::msg::PolygonObject & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: object_id
  cdr << ros_message.object_id;
  // Member: object_name
  cdr << ros_message.object_name;
  // Member: polygon
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.polygon,
    cdr);
  // Member: centroid
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.centroid,
    cdr);
  // Member: object_shape_t
  map_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.object_shape_t,
    cdr);
  // Member: object_motion_t
  map_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.object_motion_t,
    cdr);
  // Member: object_semantic_t
  map_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.object_semantic_t,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  map_interfaces::msg::PolygonObject & ros_message)
{
  // Member: object_id
  cdr >> ros_message.object_id;

  // Member: object_name
  cdr >> ros_message.object_name;

  // Member: polygon
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.polygon);

  // Member: centroid
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.centroid);

  // Member: object_shape_t
  map_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.object_shape_t);

  // Member: object_motion_t
  map_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.object_motion_t);

  // Member: object_semantic_t
  map_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.object_semantic_t);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
get_serialized_size(
  const map_interfaces::msg::PolygonObject & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: object_id
  {
    size_t item_size = sizeof(ros_message.object_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: object_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.object_name.size() + 1);
  // Member: polygon

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.polygon, current_alignment);
  // Member: centroid

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.centroid, current_alignment);
  // Member: object_shape_t

  current_alignment +=
    map_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.object_shape_t, current_alignment);
  // Member: object_motion_t

  current_alignment +=
    map_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.object_motion_t, current_alignment);
  // Member: object_semantic_t

  current_alignment +=
    map_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.object_semantic_t, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
max_serialized_size_PolygonObject(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: object_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: object_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: polygon
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Polygon(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: centroid
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Point32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: object_shape_t
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        map_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_ObjectShapeType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: object_motion_t
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        map_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_ObjectMotionType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: object_semantic_t
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        map_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_ObjectSemanticType(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = map_interfaces::msg::PolygonObject;
    is_plain =
      (
      offsetof(DataType, object_semantic_t) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PolygonObject__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const map_interfaces::msg::PolygonObject *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PolygonObject__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<map_interfaces::msg::PolygonObject *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PolygonObject__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const map_interfaces::msg::PolygonObject *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PolygonObject__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PolygonObject(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PolygonObject__callbacks = {
  "map_interfaces::msg",
  "PolygonObject",
  _PolygonObject__cdr_serialize,
  _PolygonObject__cdr_deserialize,
  _PolygonObject__get_serialized_size,
  _PolygonObject__max_serialized_size
};

static rosidl_message_type_support_t _PolygonObject__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PolygonObject__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace map_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_map_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<map_interfaces::msg::PolygonObject>()
{
  return &map_interfaces::msg::typesupport_fastrtps_cpp::_PolygonObject__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, map_interfaces, msg, PolygonObject)() {
  return &map_interfaces::msg::typesupport_fastrtps_cpp::_PolygonObject__handle;
}

#ifdef __cplusplus
}
#endif
