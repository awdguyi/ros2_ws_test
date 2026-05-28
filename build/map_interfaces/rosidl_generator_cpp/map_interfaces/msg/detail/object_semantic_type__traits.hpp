// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from map_interfaces:msg/ObjectSemanticType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__TRAITS_HPP_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "map_interfaces/msg/detail/object_semantic_type__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace map_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectSemanticType & msg,
  std::ostream & out)
{
  out << "{";
  // member: o_semantic_type
  {
    out << "o_semantic_type: ";
    rosidl_generator_traits::value_to_yaml(msg.o_semantic_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectSemanticType & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: o_semantic_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "o_semantic_type: ";
    rosidl_generator_traits::value_to_yaml(msg.o_semantic_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectSemanticType & msg, bool use_flow_style = false)
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
  const map_interfaces::msg::ObjectSemanticType & msg,
  std::ostream & out, size_t indentation = 0)
{
  map_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use map_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const map_interfaces::msg::ObjectSemanticType & msg)
{
  return map_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<map_interfaces::msg::ObjectSemanticType>()
{
  return "map_interfaces::msg::ObjectSemanticType";
}

template<>
inline const char * name<map_interfaces::msg::ObjectSemanticType>()
{
  return "map_interfaces/msg/ObjectSemanticType";
}

template<>
struct has_fixed_size<map_interfaces::msg::ObjectSemanticType>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<map_interfaces::msg::ObjectSemanticType>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<map_interfaces::msg::ObjectSemanticType>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__TRAITS_HPP_
