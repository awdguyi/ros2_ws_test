// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mps_interfaces:srv/GetInflatedMap.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__TRAITS_HPP_
#define MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mps_interfaces/srv/detail/get_inflated_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mps_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetInflatedMap_Request & msg,
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
  const GetInflatedMap_Request & msg,
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

inline std::string to_yaml(const GetInflatedMap_Request & msg, bool use_flow_style = false)
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
  const mps_interfaces::srv::GetInflatedMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::srv::GetInflatedMap_Request & msg)
{
  return mps_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::srv::GetInflatedMap_Request>()
{
  return "mps_interfaces::srv::GetInflatedMap_Request";
}

template<>
inline const char * name<mps_interfaces::srv::GetInflatedMap_Request>()
{
  return "mps_interfaces/srv/GetInflatedMap_Request";
}

template<>
struct has_fixed_size<mps_interfaces::srv::GetInflatedMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mps_interfaces::srv::GetInflatedMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mps_interfaces::srv::GetInflatedMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'inflated_map'
#include "map_interfaces/msg/detail/geometric_map__traits.hpp"

namespace mps_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetInflatedMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: inflated_map
  {
    out << "inflated_map: ";
    to_flow_style_yaml(msg.inflated_map, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetInflatedMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: inflated_map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inflated_map:\n";
    to_block_style_yaml(msg.inflated_map, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetInflatedMap_Response & msg, bool use_flow_style = false)
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
  const mps_interfaces::srv::GetInflatedMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mps_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mps_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mps_interfaces::srv::GetInflatedMap_Response & msg)
{
  return mps_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mps_interfaces::srv::GetInflatedMap_Response>()
{
  return "mps_interfaces::srv::GetInflatedMap_Response";
}

template<>
inline const char * name<mps_interfaces::srv::GetInflatedMap_Response>()
{
  return "mps_interfaces/srv/GetInflatedMap_Response";
}

template<>
struct has_fixed_size<mps_interfaces::srv::GetInflatedMap_Response>
  : std::integral_constant<bool, has_fixed_size<map_interfaces::msg::GeometricMap>::value> {};

template<>
struct has_bounded_size<mps_interfaces::srv::GetInflatedMap_Response>
  : std::integral_constant<bool, has_bounded_size<map_interfaces::msg::GeometricMap>::value> {};

template<>
struct is_message<mps_interfaces::srv::GetInflatedMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mps_interfaces::srv::GetInflatedMap>()
{
  return "mps_interfaces::srv::GetInflatedMap";
}

template<>
inline const char * name<mps_interfaces::srv::GetInflatedMap>()
{
  return "mps_interfaces/srv/GetInflatedMap";
}

template<>
struct has_fixed_size<mps_interfaces::srv::GetInflatedMap>
  : std::integral_constant<
    bool,
    has_fixed_size<mps_interfaces::srv::GetInflatedMap_Request>::value &&
    has_fixed_size<mps_interfaces::srv::GetInflatedMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<mps_interfaces::srv::GetInflatedMap>
  : std::integral_constant<
    bool,
    has_bounded_size<mps_interfaces::srv::GetInflatedMap_Request>::value &&
    has_bounded_size<mps_interfaces::srv::GetInflatedMap_Response>::value
  >
{
};

template<>
struct is_service<mps_interfaces::srv::GetInflatedMap>
  : std::true_type
{
};

template<>
struct is_service_request<mps_interfaces::srv::GetInflatedMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mps_interfaces::srv::GetInflatedMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__TRAITS_HPP_
