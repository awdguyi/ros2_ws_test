// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from map_interfaces:msg/ObjectMotionType.idl
// generated code does not contain a copyright notice
#include "map_interfaces/msg/detail/object_motion_type__rosidl_typesupport_fastrtps_cpp.hpp"
#include "map_interfaces/msg/detail/object_motion_type__struct.hpp"

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

namespace map_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
cdr_serialize(
  const map_interfaces::msg::ObjectMotionType & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: o_motion_type
  cdr << ros_message.o_motion_type;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  map_interfaces::msg::ObjectMotionType & ros_message)
{
  // Member: o_motion_type
  cdr >> ros_message.o_motion_type;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
get_serialized_size(
  const map_interfaces::msg::ObjectMotionType & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: o_motion_type
  {
    size_t item_size = sizeof(ros_message.o_motion_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_map_interfaces
max_serialized_size_ObjectMotionType(
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


  // Member: o_motion_type
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = map_interfaces::msg::ObjectMotionType;
    is_plain =
      (
      offsetof(DataType, o_motion_type) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ObjectMotionType__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const map_interfaces::msg::ObjectMotionType *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ObjectMotionType__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<map_interfaces::msg::ObjectMotionType *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ObjectMotionType__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const map_interfaces::msg::ObjectMotionType *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ObjectMotionType__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ObjectMotionType(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ObjectMotionType__callbacks = {
  "map_interfaces::msg",
  "ObjectMotionType",
  _ObjectMotionType__cdr_serialize,
  _ObjectMotionType__cdr_deserialize,
  _ObjectMotionType__get_serialized_size,
  _ObjectMotionType__max_serialized_size
};

static rosidl_message_type_support_t _ObjectMotionType__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ObjectMotionType__callbacks,
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
get_message_type_support_handle<map_interfaces::msg::ObjectMotionType>()
{
  return &map_interfaces::msg::typesupport_fastrtps_cpp::_ObjectMotionType__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, map_interfaces, msg, ObjectMotionType)() {
  return &map_interfaces::msg::typesupport_fastrtps_cpp::_ObjectMotionType__handle;
}

#ifdef __cplusplus
}
#endif
