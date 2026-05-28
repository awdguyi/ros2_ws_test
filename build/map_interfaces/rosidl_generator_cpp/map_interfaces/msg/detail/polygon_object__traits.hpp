// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__TRAITS_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_interfaces/msg/detail/polygon_object__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'polygon'
#include "geometry_msgs/msg/detail/polygon__traits.hpp"
// Member 'centroid'
#include "geometry_msgs/msg/detail/point32__traits.hpp"
// Member 'object_shape_t'
#include "map_interfaces/msg/detail/object_shape_type__traits.hpp"
// Member 'object_motion_t'
#include "map_interfaces/msg/detail/object_motion_type__traits.hpp"
// Member 'object_semantic_t'
#include "map_interfaces/msg/detail/object_semantic_type__traits.hpp"

namespace map_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PolygonObject & msg,
  std::ostream & out)
{
  out << "{";
  // member: object_id
  {
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << ", ";
  }

  // member: object_name
  {
    out << "object_name: ";
    rosidl_generator_traits::value_to_yaml(msg.object_name, out);
    out << ", ";
  }

  // member: polygon
  {
    out << "polygon: ";
    to_flow_style_yaml(msg.polygon, out);
    out << ", ";
  }

  // member: centroid
  {
    out << "centroid: ";
    to_flow_style_yaml(msg.centroid, out);
    out << ", ";
  }

  // member: object_shape_t
  {
    out << "object_shape_t: ";
    to_flow_style_yaml(msg.object_shape_t, out);
    out << ", ";
  }

  // member: object_motion_t
  {
    out << "object_motion_t: ";
    to_flow_style_yaml(msg.object_motion_t, out);
    out << ", ";
  }

  // member: object_semantic_t
  {
    out << "object_semantic_t: ";
    to_flow_style_yaml(msg.object_semantic_t, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PolygonObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: object_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << "\n";
  }

  // member: object_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_name: ";
    rosidl_generator_traits::value_to_yaml(msg.object_name, out);
    out << "\n";
  }

  // member: polygon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polygon:\n";
    to_block_style_yaml(msg.polygon, out, indentation + 2);
  }

  // member: centroid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "centroid:\n";
    to_block_style_yaml(msg.centroid, out, indentation + 2);
  }

  // member: object_shape_t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_shape_t:\n";
    to_block_style_yaml(msg.object_shape_t, out, indentation + 2);
  }

  // member: object_motion_t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_motion_t:\n";
    to_block_style_yaml(msg.object_motion_t, out, indentation + 2);
  }

  // member: object_semantic_t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_semantic_t:\n";
    to_block_style_yaml(msg.object_semantic_t, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PolygonObject & msg, bool use_flow_style = false)
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
  const map_interfaces::msg::PolygonObject & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_interfaces::msg::PolygonObject & msg)
{
  return map_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_interfaces::msg::PolygonObject>()
{
  return "map_interfaces::msg::PolygonObject";
}

template<>
inline const char * name<map_interfaces::msg::PolygonObject>()
{
  return "map_interfaces/msg/PolygonObject";
}

template<>
struct has_fixed_size<map_interfaces::msg::PolygonObject>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<map_interfaces::msg::PolygonObject>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<map_interfaces::msg::PolygonObject>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__TRAITS_HPP_
