// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE__TRAITS_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mps_interfaces/msg/detail/schedule__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mps_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Schedule & msg,
  std::ostream & out)
{
  out << "{";
  // member: schedule_name
  {
    out << "schedule_name: ";
    rosidl_generator_traits::value_to_yaml(msg.schedule_name, out);
    out << ", ";
  }

  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: node_ids
  {
    if (msg.node_ids.size() == 0) {
      out << "node_ids: []";
    } else {
      out << "node_ids: [";
      size_t pending_items = msg.node_ids.size();
      for (auto item : msg.node_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: node_names
  {
    if (msg.node_names.size() == 0) {
      out << "node_names: []";
    } else {
      out << "node_names: [";
      size_t pending_items = msg.node_names.size();
      for (auto item : msg.node_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: etas
  {
    if (msg.etas.size() == 0) {
      out << "etas: []";
    } else {
      out << "etas: [";
      size_t pending_items = msg.etas.size();
      for (auto item : msg.etas) {
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
  const Schedule & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: schedule_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "schedule_name: ";
    rosidl_generator_traits::value_to_yaml(msg.schedule_name, out);
    out << "\n";
  }

  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: node_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.node_ids.size() == 0) {
      out << "node_ids: []\n";
    } else {
      out << "node_ids:\n";
      for (auto item : msg.node_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: node_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.node_names.size() == 0) {
      out << "node_names: []\n";
    } else {
      out << "node_names:\n";
      for (auto item : msg.node_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: etas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.etas.size() == 0) {
      out << "etas: []\n";
    } else {
      out << "etas:\n";
      for (auto item : msg.etas) {
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

inline std::string to_yaml(const Schedule & msg, bool use_flow_style = false)
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
  const mps_interfaces::msg::Schedule & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::msg::Schedule & msg)
{
  return mps_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::msg::Schedule>()
{
  return "mps_interfaces::msg::Schedule";
}

template<>
inline const char * name<mps_interfaces::msg::Schedule>()
{
  return "mps_interfaces/msg/Schedule";
}

template<>
struct has_fixed_size<mps_interfaces::msg::Schedule>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mps_interfaces::msg::Schedule>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mps_interfaces::msg::Schedule>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE__TRAITS_HPP_
