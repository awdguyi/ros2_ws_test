// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mps_interfaces:srv/GetRobotSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__TRAITS_HPP_
#define MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mps_interfaces/srv/detail/get_robot_schedule__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mps_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRobotSchedule_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: current_time
  {
    out << "current_time: ";
    rosidl_generator_traits::value_to_yaml(msg.current_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRobotSchedule_Request & msg,
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

  // member: current_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_time: ";
    rosidl_generator_traits::value_to_yaml(msg.current_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRobotSchedule_Request & msg, bool use_flow_style = false)
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

}  // namespace mps_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mps_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mps_interfaces::srv::GetRobotSchedule_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::srv::GetRobotSchedule_Request & msg)
{
  return mps_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::srv::GetRobotSchedule_Request>()
{
  return "mps_interfaces::srv::GetRobotSchedule_Request";
}

template<>
inline const char * name<mps_interfaces::srv::GetRobotSchedule_Request>()
{
  return "mps_interfaces/srv/GetRobotSchedule_Request";
}

template<>
struct has_fixed_size<mps_interfaces::srv::GetRobotSchedule_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mps_interfaces::srv::GetRobotSchedule_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mps_interfaces::srv::GetRobotSchedule_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'path_schedule'
#include "mps_interfaces/msg/detail/path_schedule_stamped__traits.hpp"

namespace mps_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRobotSchedule_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: path_schedule
  {
    out << "path_schedule: ";
    to_flow_style_yaml(msg.path_schedule, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRobotSchedule_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path_schedule
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "path_schedule:\n";
    to_block_style_yaml(msg.path_schedule, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRobotSchedule_Response & msg, bool use_flow_style = false)
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

}  // namespace mps_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mps_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mps_interfaces::srv::GetRobotSchedule_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::srv::GetRobotSchedule_Response & msg)
{
  return mps_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::srv::GetRobotSchedule_Response>()
{
  return "mps_interfaces::srv::GetRobotSchedule_Response";
}

template<>
inline const char * name<mps_interfaces::srv::GetRobotSchedule_Response>()
{
  return "mps_interfaces/srv/GetRobotSchedule_Response";
}

template<>
struct has_fixed_size<mps_interfaces::srv::GetRobotSchedule_Response>
  : std::integral_constant<bool, has_fixed_size<mps_interfaces::msg::PathScheduleStamped>::value> {};

template<>
struct has_bounded_size<mps_interfaces::srv::GetRobotSchedule_Response>
  : std::integral_constant<bool, has_bounded_size<mps_interfaces::msg::PathScheduleStamped>::value> {};

template<>
struct is_message<mps_interfaces::srv::GetRobotSchedule_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mps_interfaces::srv::GetRobotSchedule>()
{
  return "mps_interfaces::srv::GetRobotSchedule";
}

template<>
inline const char * name<mps_interfaces::srv::GetRobotSchedule>()
{
  return "mps_interfaces/srv/GetRobotSchedule";
}

template<>
struct has_fixed_size<mps_interfaces::srv::GetRobotSchedule>
  : std::integral_constant<
    bool,
    has_fixed_size<mps_interfaces::srv::GetRobotSchedule_Request>::value &&
    has_fixed_size<mps_interfaces::srv::GetRobotSchedule_Response>::value
  >
{
};

template<>
struct has_bounded_size<mps_interfaces::srv::GetRobotSchedule>
  : std::integral_constant<
    bool,
    has_bounded_size<mps_interfaces::srv::GetRobotSchedule_Request>::value &&
    has_bounded_size<mps_interfaces::srv::GetRobotSchedule_Response>::value
  >
{
};

template<>
struct is_service<mps_interfaces::srv::GetRobotSchedule>
  : std::true_type
{
};

template<>
struct is_service_request<mps_interfaces::srv::GetRobotSchedule_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mps_interfaces::srv::GetRobotSchedule_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__TRAITS_HPP_
