// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__TRAITS_HPP_
#define MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mmp_interfaces/msg/detail/motion_prediction_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'mu_list_list'
// Member 'std_list_list'
// Member 'conf_list_list'
#include "mmp_interfaces/msg/detail/human_trajectory_array__traits.hpp"

namespace mmp_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotionPredictionResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: mu_list_list
  {
    if (msg.mu_list_list.size() == 0) {
      out << "mu_list_list: []";
    } else {
      out << "mu_list_list: [";
      size_t pending_items = msg.mu_list_list.size();
      for (auto item : msg.mu_list_list) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: std_list_list
  {
    if (msg.std_list_list.size() == 0) {
      out << "std_list_list: []";
    } else {
      out << "std_list_list: [";
      size_t pending_items = msg.std_list_list.size();
      for (auto item : msg.std_list_list) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: conf_list_list
  {
    if (msg.conf_list_list.size() == 0) {
      out << "conf_list_list: []";
    } else {
      out << "conf_list_list: [";
      size_t pending_items = msg.conf_list_list.size();
      for (auto item : msg.conf_list_list) {
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
  const MotionPredictionResult & msg,
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

  // member: mu_list_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.mu_list_list.size() == 0) {
      out << "mu_list_list: []\n";
    } else {
      out << "mu_list_list:\n";
      for (auto item : msg.mu_list_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: std_list_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.std_list_list.size() == 0) {
      out << "std_list_list: []\n";
    } else {
      out << "std_list_list:\n";
      for (auto item : msg.std_list_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: conf_list_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.conf_list_list.size() == 0) {
      out << "conf_list_list: []\n";
    } else {
      out << "conf_list_list:\n";
      for (auto item : msg.conf_list_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotionPredictionResult & msg, bool use_flow_style = false)
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
  const mmp_interfaces::msg::MotionPredictionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmp_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmp_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const mmp_interfaces::msg::MotionPredictionResult & msg)
{
  return mmp_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mmp_interfaces::msg::MotionPredictionResult>()
{
  return "mmp_interfaces::msg::MotionPredictionResult";
}

template<>
inline const char * name<mmp_interfaces::msg::MotionPredictionResult>()
{
  return "mmp_interfaces/msg/MotionPredictionResult";
}

template<>
struct has_fixed_size<mmp_interfaces::msg::MotionPredictionResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmp_interfaces::msg::MotionPredictionResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmp_interfaces::msg::MotionPredictionResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__TRAITS_HPP_
