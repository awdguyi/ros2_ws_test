// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mmp_interfaces:msg/HumanTrajectoryArray.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__TRAITS_HPP_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mmp_interfaces/msg/detail/human_trajectory_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'human_trajectories'
#include "mmp_interfaces/msg/detail/human_trajectory__traits.hpp"

namespace mmp_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HumanTrajectoryArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: human_trajectories
  {
    if (msg.human_trajectories.size() == 0) {
      out << "human_trajectories: []";
    } else {
      out << "human_trajectories: [";
      size_t pending_items = msg.human_trajectories.size();
      for (auto item : msg.human_trajectories) {
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
  const HumanTrajectoryArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: human_trajectories
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.human_trajectories.size() == 0) {
      out << "human_trajectories: []\n";
    } else {
      out << "human_trajectories:\n";
      for (auto item : msg.human_trajectories) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HumanTrajectoryArray & msg, bool use_flow_style = false)
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
  const mmp_interfaces::msg::HumanTrajectoryArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmp_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmp_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mmp_interfaces::msg::HumanTrajectoryArray & msg)
{
  return mmp_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mmp_interfaces::msg::HumanTrajectoryArray>()
{
  return "mmp_interfaces::msg::HumanTrajectoryArray";
}

template<>
inline const char * name<mmp_interfaces::msg::HumanTrajectoryArray>()
{
  return "mmp_interfaces/msg/HumanTrajectoryArray";
}

template<>
struct has_fixed_size<mmp_interfaces::msg::HumanTrajectoryArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmp_interfaces::msg::HumanTrajectoryArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmp_interfaces::msg::HumanTrajectoryArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__TRAITS_HPP_
