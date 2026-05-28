// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zmr_interfaces:srv/GetRobotState.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__TRAITS_HPP_
#define ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zmr_interfaces/srv/detail/get_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace zmr_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRobotState_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRobotState_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRobotState_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zmr_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zmr_interfaces::srv::GetRobotState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  zmr_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zmr_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const zmr_interfaces::srv::GetRobotState_Request & msg)
{
  return zmr_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zmr_interfaces::srv::GetRobotState_Request>()
{
  return "zmr_interfaces::srv::GetRobotState_Request";
}

template<>
inline const char * name<zmr_interfaces::srv::GetRobotState_Request>()
{
  return "zmr_interfaces/srv/GetRobotState_Request";
}

template<>
struct has_fixed_size<zmr_interfaces::srv::GetRobotState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<zmr_interfaces::srv::GetRobotState_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<zmr_interfaces::srv::GetRobotState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace zmr_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRobotState_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_state
  {
    if (msg.robot_state.size() == 0) {
      out << "robot_state: []";
    } else {
      out << "robot_state: [";
      size_t pending_items = msg.robot_state.size();
      for (auto item : msg.robot_state) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: future_states
  {
    if (msg.future_states.size() == 0) {
      out << "future_states: []";
    } else {
      out << "future_states: [";
      size_t pending_items = msg.future_states.size();
      for (auto item : msg.future_states) {
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
  const GetRobotState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_state.size() == 0) {
      out << "robot_state: []\n";
    } else {
      out << "robot_state:\n";
      for (auto item : msg.robot_state) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: future_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.future_states.size() == 0) {
      out << "future_states: []\n";
    } else {
      out << "future_states:\n";
      for (auto item : msg.future_states) {
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

inline std::string to_yaml(const GetRobotState_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace zmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zmr_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zmr_interfaces::srv::GetRobotState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  zmr_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zmr_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const zmr_interfaces::srv::GetRobotState_Response & msg)
{
  return zmr_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<zmr_interfaces::srv::GetRobotState_Response>()
{
  return "zmr_interfaces::srv::GetRobotState_Response";
}

template<>
inline const char * name<zmr_interfaces::srv::GetRobotState_Response>()
{
  return "zmr_interfaces/srv/GetRobotState_Response";
}

template<>
struct has_fixed_size<zmr_interfaces::srv::GetRobotState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<zmr_interfaces::srv::GetRobotState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<zmr_interfaces::srv::GetRobotState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<zmr_interfaces::srv::GetRobotState>()
{
  return "zmr_interfaces::srv::GetRobotState";
}

template<>
inline const char * name<zmr_interfaces::srv::GetRobotState>()
{
  return "zmr_interfaces/srv/GetRobotState";
}

template<>
struct has_fixed_size<zmr_interfaces::srv::GetRobotState>
  : std::integral_constant<
    bool,
    has_fixed_size<zmr_interfaces::srv::GetRobotState_Request>::value &&
    has_fixed_size<zmr_interfaces::srv::GetRobotState_Response>::value
  >
{
};

template<>
struct has_bounded_size<zmr_interfaces::srv::GetRobotState>
  : std::integral_constant<
    bool,
    has_bounded_size<zmr_interfaces::srv::GetRobotState_Request>::value &&
    has_bounded_size<zmr_interfaces::srv::GetRobotState_Response>::value
  >
{
};

template<>
struct is_service<zmr_interfaces::srv::GetRobotState>
  : std::true_type
{
};

template<>
struct is_service_request<zmr_interfaces::srv::GetRobotState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<zmr_interfaces::srv::GetRobotState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__TRAITS_HPP_
