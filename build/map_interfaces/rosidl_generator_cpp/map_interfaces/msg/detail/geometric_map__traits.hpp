// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_interfaces:msg/GeometricMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__TRAITS_HPP_
#define MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_interfaces/msg/detail/geometric_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'boundary'
#include "map_interfaces/msg/detail/polygon_object__traits.hpp"
// Member 'obstacle_list'
#include "map_interfaces/msg/detail/polygon_object_array__traits.hpp"

namespace map_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GeometricMap & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: boundary
  {
    out << "boundary: ";
    to_flow_style_yaml(msg.boundary, out);
    out << ", ";
  }

  // member: obstacle_list
  {
    out << "obstacle_list: ";
    to_flow_style_yaml(msg.obstacle_list, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GeometricMap & msg,
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

  // member: boundary
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "boundary:\n";
    to_block_style_yaml(msg.boundary, out, indentation + 2);
  }

  // member: obstacle_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_list:\n";
    to_block_style_yaml(msg.obstacle_list, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GeometricMap & msg, bool use_flow_style = false)
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
  const map_interfaces::msg::GeometricMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_interfaces::msg::GeometricMap & msg)
{
  return map_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_interfaces::msg::GeometricMap>()
{
  return "map_interfaces::msg::GeometricMap";
}

template<>
inline const char * name<map_interfaces::msg::GeometricMap>()
{
  return "map_interfaces/msg/GeometricMap";
}

template<>
struct has_fixed_size<map_interfaces::msg::GeometricMap>
  : std::integral_constant<bool, has_fixed_size<map_interfaces::msg::PolygonObject>::value && has_fixed_size<map_interfaces::msg::PolygonObjectArray>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<map_interfaces::msg::GeometricMap>
  : std::integral_constant<bool, has_bounded_size<map_interfaces::msg::PolygonObject>::value && has_bounded_size<map_interfaces::msg::PolygonObjectArray>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<map_interfaces::msg::GeometricMap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__TRAITS_HPP_
