// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "map_interfaces/msg/detail/polygon_object_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace map_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PolygonObjectArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) map_interfaces::msg::PolygonObjectArray(_init);
}

void PolygonObjectArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<map_interfaces::msg::PolygonObjectArray *>(message_memory);
  typed_message->~PolygonObjectArray();
}

size_t size_function__PolygonObjectArray__polygon_objects(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<map_interfaces::msg::PolygonObject> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PolygonObjectArray__polygon_objects(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<map_interfaces::msg::PolygonObject> *>(untyped_member);
  return &member[index];
}

void * get_function__PolygonObjectArray__polygon_objects(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<map_interfaces::msg::PolygonObject> *>(untyped_member);
  return &member[index];
}

void fetch_function__PolygonObjectArray__polygon_objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const map_interfaces::msg::PolygonObject *>(
    get_const_function__PolygonObjectArray__polygon_objects(untyped_member, index));
  auto & value = *reinterpret_cast<map_interfaces::msg::PolygonObject *>(untyped_value);
  value = item;
}

void assign_function__PolygonObjectArray__polygon_objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<map_interfaces::msg::PolygonObject *>(
    get_function__PolygonObjectArray__polygon_objects(untyped_member, index));
  const auto & value = *reinterpret_cast<const map_interfaces::msg::PolygonObject *>(untyped_value);
  item = value;
}

void resize_function__PolygonObjectArray__polygon_objects(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<map_interfaces::msg::PolygonObject> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PolygonObjectArray_message_member_array[1] = {
  {
    "polygon_objects",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<map_interfaces::msg::PolygonObject>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(map_interfaces::msg::PolygonObjectArray, polygon_objects),  // bytes offset in struct
    nullptr,  // default value
    size_function__PolygonObjectArray__polygon_objects,  // size() function pointer
    get_const_function__PolygonObjectArray__polygon_objects,  // get_const(index) function pointer
    get_function__PolygonObjectArray__polygon_objects,  // get(index) function pointer
    fetch_function__PolygonObjectArray__polygon_objects,  // fetch(index, &value) function pointer
    assign_function__PolygonObjectArray__polygon_objects,  // assign(index, value) function pointer
    resize_function__PolygonObjectArray__polygon_objects  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PolygonObjectArray_message_members = {
  "map_interfaces::msg",  // message namespace
  "PolygonObjectArray",  // message name
  1,  // number of fields
  sizeof(map_interfaces::msg::PolygonObjectArray),
  PolygonObjectArray_message_member_array,  // message members
  PolygonObjectArray_init_function,  // function to initialize message memory (memory has to be allocated)
  PolygonObjectArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PolygonObjectArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PolygonObjectArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace map_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<map_interfaces::msg::PolygonObjectArray>()
{
  return &::map_interfaces::msg::rosidl_typesupport_introspection_cpp::PolygonObjectArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, map_interfaces, msg, PolygonObjectArray)() {
  return &::map_interfaces::msg::rosidl_typesupport_introspection_cpp::PolygonObjectArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
