// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mmp_interfaces:msg/HumanTrajectory.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__TRAITS_HPP_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mmp_interfaces/msg/detail/human_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'traj_points'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace mmp_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HumanTrajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: traj_points
  {
    if (msg.traj_points.size() == 0) {
      out << "traj_points: []";
    } else {
      out << "traj_points: [";
      size_t pending_items = msg.traj_points.size();
      for (auto item : msg.traj_points) {
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
  const HumanTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: traj_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.traj_points.size() == 0) {
      out << "traj_points: []\n";
    } else {
      out << "traj_points:\n";
      for (auto item : msg.traj_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HumanTrajectory & msg, bool use_flow_style = false)
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

}  // namespace mmp_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmp_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmp_interfaces::msg::HumanTrajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmp_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmp_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mmp_interfaces::msg::HumanTrajectory & msg)
{
  return mmp_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mmp_interfaces::msg::HumanTrajectory>()
{
  return "mmp_interfaces::msg::HumanTrajectory";
}

template<>
inline const char * name<mmp_interfaces::msg::HumanTrajectory>()
{
  return "mmp_interfaces/msg/HumanTrajectory";
}

template<>
struct has_fixed_size<mmp_interfaces::msg::HumanTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmp_interfaces::msg::HumanTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmp_interfaces::msg::HumanTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__TRAITS_HPP_
