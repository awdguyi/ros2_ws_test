// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__TRAITS_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mps_interfaces/msg/detail/schedule_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'schedules'
#include "mps_interfaces/msg/detail/schedule__traits.hpp"

namespace mps_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ScheduleArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: schedules
  {
    if (msg.schedules.size() == 0) {
      out << "schedules: []";
    } else {
      out << "schedules: [";
      size_t pending_items = msg.schedules.size();
      for (auto item : msg.schedules) {
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
  const ScheduleArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: schedules
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.schedules.size() == 0) {
      out << "schedules: []\n";
    } else {
      out << "schedules:\n";
      for (auto item : msg.schedules) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScheduleArray & msg, bool use_flow_style = false)
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
  const mps_interfaces::msg::ScheduleArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::msg::ScheduleArray & msg)
{
  return mps_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::msg::ScheduleArray>()
{
  return "mps_interfaces::msg::ScheduleArray";
}

template<>
inline const char * name<mps_interfaces::msg::ScheduleArray>()
{
  return "mps_interfaces/msg/ScheduleArray";
}

template<>
struct has_fixed_size<mps_interfaces::msg::ScheduleArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mps_interfaces::msg::ScheduleArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mps_interfaces::msg::ScheduleArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__TRAITS_HPP_
