// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__TRAITS_HPP_
#define ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zmr_interfaces/msg/detail/current_future_states__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zmr_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CurrentFutureStates & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_states
  {
    if (msg.robot_states.size() == 0) {
      out << "robot_states: []";
    } else {
      out << "robot_states: [";
      size_t pending_items = msg.robot_states.size();
      for (auto item : msg.robot_states) {
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
  const CurrentFutureStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_states.size() == 0) {
      out << "robot_states: []\n";
    } else {
      out << "robot_states:\n";
      for (auto item : msg.robot_states) {
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

inline std::string to_yaml(const CurrentFutureStates & msg, bool use_flow_style = false)
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

}  // namespace zmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zmr_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zmr_interfaces::msg::CurrentFutureStates & msg,
  std::ostream & out, size_t indentation = 0)
{
  zmr_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zmr_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zmr_interfaces::msg::CurrentFutureStates & msg)
{
  return zmr_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zmr_interfaces::msg::CurrentFutureStates>()
{
  return "zmr_interfaces::msg::CurrentFutureStates";
}

template<>
inline const char * name<zmr_interfaces::msg::CurrentFutureStates>()
{
  return "zmr_interfaces/msg/CurrentFutureStates";
}

template<>
struct has_fixed_size<zmr_interfaces::msg::CurrentFutureStates>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zmr_interfaces::msg::CurrentFutureStates>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zmr_interfaces::msg::CurrentFutureStates>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__TRAITS_HPP_
