// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/PolygonObjectStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/polygon_object_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_PolygonObjectStamped_polygon_object
{
public:
  explicit Init_PolygonObjectStamped_polygon_object(::map_interfaces::msg::PolygonObjectStamped & msg)
  : msg_(msg)
  {}
  ::map_interfaces::msg::PolygonObjectStamped polygon_object(::map_interfaces::msg::PolygonObjectStamped::_polygon_object_type arg)
  {
    msg_.polygon_object = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObjectStamped msg_;
};

class Init_PolygonObjectStamped_header
{
public:
  Init_PolygonObjectStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonObjectStamped_polygon_object header(::map_interfaces::msg::PolygonObjectStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PolygonObjectStamped_polygon_object(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObjectStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::PolygonObjectStamped>()
{
  return map_interfaces::msg::builder::Init_PolygonObjectStamped_header();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__BUILDER_HPP_
