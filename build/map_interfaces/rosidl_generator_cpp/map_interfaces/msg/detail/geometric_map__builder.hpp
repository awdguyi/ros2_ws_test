// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/GeometricMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/geometric_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_GeometricMap_obstacle_list
{
public:
  explicit Init_GeometricMap_obstacle_list(::map_interfaces::msg::GeometricMap & msg)
  : msg_(msg)
  {}
  ::map_interfaces::msg::GeometricMap obstacle_list(::map_interfaces::msg::GeometricMap::_obstacle_list_type arg)
  {
    msg_.obstacle_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::GeometricMap msg_;
};

class Init_GeometricMap_boundary
{
public:
  explicit Init_GeometricMap_boundary(::map_interfaces::msg::GeometricMap & msg)
  : msg_(msg)
  {}
  Init_GeometricMap_obstacle_list boundary(::map_interfaces::msg::GeometricMap::_boundary_type arg)
  {
    msg_.boundary = std::move(arg);
    return Init_GeometricMap_obstacle_list(msg_);
  }

private:
  ::map_interfaces::msg::GeometricMap msg_;
};

class Init_GeometricMap_header
{
public:
  Init_GeometricMap_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GeometricMap_boundary header(::map_interfaces::msg::GeometricMap::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GeometricMap_boundary(msg_);
  }

private:
  ::map_interfaces::msg::GeometricMap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::GeometricMap>()
{
  return map_interfaces::msg::builder::Init_GeometricMap_header();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__BUILDER_HPP_
