// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mps_interfaces:msg/PathScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__TRAITS_HPP_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mps_interfaces/msg/detail/path_schedule_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'path_schedule'
#include "mps_interfaces/msg/detail/path_schedule__traits.hpp"

namespace mps_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PathScheduleStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: path_schedule
  {
    out << "path_schedule: ";
    to_flow_style_yaml(msg.path_schedule, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PathScheduleStamped & msg,
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

  // member: path_schedule
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_schedule:\n";
    to_block_style_yaml(msg.path_schedule, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathScheduleStamped & msg, bool use_flow_style = false)
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

}  // namespace mps_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mps_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mps_interfaces::msg::PathScheduleStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::msg::PathScheduleStamped & msg)
{
  return mps_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::msg::PathScheduleStamped>()
{
  return "mps_interfaces::msg::PathScheduleStamped";
}

template<>
inline const char * name<mps_interfaces::msg::PathScheduleStamped>()
{
  return "mps_interfaces/msg/PathScheduleStamped";
}

template<>
struct has_fixed_size<mps_interfaces::msg::PathScheduleStamped>
  : std::integral_constant<bool, has_fixed_size<mps_interfaces::msg::PathSchedule>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<mps_interfaces::msg::PathScheduleStamped>
  : std::integral_constant<bool, has_bounded_size<mps_interfaces::msg::PathSchedule>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<mps_interfaces::msg::PathScheduleStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__TRAITS_HPP_
