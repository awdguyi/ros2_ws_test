// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__TRAITS_HPP_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mps_interfaces/msg/detail/path_schedule__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'path_coords'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace mps_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const PathSchedule & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: path_coords
  {
    if (msg.path_coords.size() == 0) {
      out << "path_coords: []";
    } else {
      out << "path_coords: [";
      size_t pending_items = msg.path_coords.size();
      for (auto item : msg.path_coords) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: path_times
  {
    if (msg.path_times.size() == 0) {
      out << "path_times: []";
    } else {
      out << "path_times: [";
      size_t pending_items = msg.path_times.size();
      for (auto item : msg.path_times) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const PathSchedule & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: path_coords
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path_coords.size() == 0) {
      out << "path_coords: []\n";
    } else {
      out << "path_coords:\n";
      for (auto item : msg.path_coords) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: path_times
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path_times.size() == 0) {
      out << "path_times: []\n";
    } else {
      out << "path_times:\n";
      for (auto item : msg.path_times) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathSchedule & msg, bool use_flow_style = false)
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
  const mps_interfaces::msg::PathSchedule & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::msg::PathSchedule & msg)
{
  return mps_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::msg::PathSchedule>()
{
  return "mps_interfaces::msg::PathSchedule";
}

template<>
inline const char * name<mps_interfaces::msg::PathSchedule>()
{
  return "mps_interfaces/msg/PathSchedule";
}

template<>
struct has_fixed_size<mps_interfaces::msg::PathSchedule>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mps_interfaces::msg::PathSchedule>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mps_interfaces::msg::PathSchedule>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__TRAITS_HPP_
