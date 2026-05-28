// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__TRAITS_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_interfaces/msg/detail/polygon_object_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'polygon_objects'
#include "map_interfaces/msg/detail/polygon_object__traits.hpp"

namespace map_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PolygonObjectArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: polygon_objects
  {
    if (msg.polygon_objects.size() == 0) {
      out << "polygon_objects: []";
    } else {
      out << "polygon_objects: [";
      size_t pending_items = msg.polygon_objects.size();
      for (auto item : msg.polygon_objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PolygonObjectArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: polygon_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.polygon_objects.size() == 0) {
      out << "polygon_objects: []\n";
    } else {
      out << "polygon_objects:\n";
      for (auto item : msg.polygon_objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PolygonObjectArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace map_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use map_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const map_interfaces::msg::PolygonObjectArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_interfaces::msg::PolygonObjectArray & msg)
{
  return map_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_interfaces::msg::PolygonObjectArray>()
{
  return "map_interfaces::msg::PolygonObjectArray";
}

template<>
inline const char * name<map_interfaces::msg::PolygonObjectArray>()
{
  return "map_interfaces/msg/PolygonObjectArray";
}

template<>
struct has_fixed_size<map_interfaces::msg::PolygonObjectArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<map_interfaces::msg::PolygonObjectArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<map_interfaces::msg::PolygonObjectArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__TRAITS_HPP_
