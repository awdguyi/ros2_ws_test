// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_interfaces:msg/PolygonObjectArrayStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__TRAITS_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_interfaces/msg/detail/polygon_object_array_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'polygon_objects'
#include "map_interfaces/msg/detail/polygon_object_array__traits.hpp"

namespace map_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PolygonObjectArrayStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: polygon_objects
  {
    out << "polygon_objects: ";
    to_flow_style_yaml(msg.polygon_objects, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PolygonObjectArrayStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: polygon_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polygon_objects:\n";
    to_block_style_yaml(msg.polygon_objects, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PolygonObjectArrayStamped & msg, bool use_flow_style = false)
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
  const map_interfaces::msg::PolygonObjectArrayStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_interfaces::msg::PolygonObjectArrayStamped & msg)
{
  return map_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_interfaces::msg::PolygonObjectArrayStamped>()
{
  return "map_interfaces::msg::PolygonObjectArrayStamped";
}

template<>
inline const char * name<map_interfaces::msg::PolygonObjectArrayStamped>()
{
  return "map_interfaces/msg/PolygonObjectArrayStamped";
}

template<>
struct has_fixed_size<map_interfaces::msg::PolygonObjectArrayStamped>
  : std::integral_constant<bool, has_fixed_size<map_interfaces::msg::PolygonObjectArray>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<map_interfaces::msg::PolygonObjectArrayStamped>
  : std::integral_constant<bool, has_bounded_size<map_interfaces::msg::PolygonObjectArray>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<map_interfaces::msg::PolygonObjectArrayStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__TRAITS_HPP_
