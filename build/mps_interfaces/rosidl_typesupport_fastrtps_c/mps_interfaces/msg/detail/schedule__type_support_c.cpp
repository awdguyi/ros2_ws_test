// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice
#include "mps_interfaces/msg/detail/schedule__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mps_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mps_interfaces/msg/detail/schedule__struct.h"
#include "mps_interfaces/msg/detail/schedule__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // etas, node_ids
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // etas, node_ids
#include "rosidl_runtime_c/string.h"  // node_names, schedule_name
#include "rosidl_runtime_c/string_functions.h"  // node_names, schedule_name

// forward declare type support functions


using _Schedule__ros_msg_type = mps_interfaces__msg__Schedule;

static bool _Schedule__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Schedule__ros_msg_type * ros_message = static_cast<const _Schedule__ros_msg_type *>(untyped_ros_message);
  // Field name: schedule_name
  {
    const rosidl_runtime_c__String * str = &ros_message->schedule_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: robot_id
  {
    cdr << ros_message->robot_id;
  }

  // Field name: node_ids
  {
    size_t size = ros_message->node_ids.size;
    auto array_ptr = ros_message->node_ids.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: node_names
  {
    size_t size = ros_message->node_names.size;
    auto array_ptr = ros_message->node_names.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: etas
  {
    size_t size = ros_message->etas.size;
    auto array_ptr = ros_message->etas.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _Schedule__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Schedule__ros_msg_type * ros_message = static_cast<_Schedule__ros_msg_type *>(untyped_ros_message);
  // Field name: schedule_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->schedule_name.data) {
      rosidl_runtime_c__String__init(&ros_message->schedule_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->schedule_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'schedule_name'\n");
      return false;
    }
  }

  // Field name: robot_id
  {
    cdr >> ros_message->robot_id;
  }

  // Field name: node_ids
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->node_ids.data) {
      rosidl_runtime_c__int16__Sequence__fini(&ros_message->node_ids);
    }
    if (!rosidl_runtime_c__int16__Sequence__init(&ros_message->node_ids, size)) {
      fprintf(stderr, "failed to create array for field 'node_ids'");
      return false;
    }
    auto array_ptr = ros_message->node_ids.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: node_names
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->node_names.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->node_names);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->node_names, size)) {
      fprintf(stderr, "failed to create array for field 'node_names'");
      return false;
    }
    auto array_ptr = ros_message->node_names.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'node_names'\n");
        return false;
      }
    }
  }

  // Field name: etas
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->etas.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->etas);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->etas, size)) {
      fprintf(stderr, "failed to create array for field 'etas'");
      return false;
    }
    auto array_ptr = ros_message->etas.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mps_interfaces
size_t get_serialized_size_mps_interfaces__msg__Schedule(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Schedule__ros_msg_type * ros_message = static_cast<const _Schedule__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name schedule_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->schedule_name.size + 1);
  // field.name robot_id
  {
    size_t item_size = sizeof(ros_message->robot_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name node_ids
  {
    size_t array_size = ros_message->node_ids.size;
    auto array_ptr = ros_message->node_ids.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name node_names
  {
    size_t array_size = ros_message->node_names.size;
    auto array_ptr = ros_message->node_names.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name etas
  {
    size_t array_size = ros_message->etas.size;
    auto array_ptr = ros_message->etas.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Schedule__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mps_interfaces__msg__Schedule(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mps_interfaces
size_t max_serialized_size_mps_interfaces__msg__Schedule(
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

  // member: schedule_name
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
  // member: robot_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: node_ids
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: node_names
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: etas
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mps_interfaces__msg__Schedule;
    is_plain =
      (
      offsetof(DataType, etas) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Schedule__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mps_interfaces__msg__Schedule(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Schedule = {
  "mps_interfaces::msg",
  "Schedule",
  _Schedule__cdr_serialize,
  _Schedule__cdr_deserialize,
  _Schedule__get_serialized_size,
  _Schedule__max_serialized_size
};

static rosidl_message_type_support_t _Schedule__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Schedule,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mps_interfaces, msg, Schedule)() {
  return &_Schedule__type_support;
}

#if defined(__cplusplus)
}
#endif
