// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/PolygonObjectArrayStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/polygon_object_array_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_PolygonObjectArrayStamped_polygon_objects
{
public:
  explicit Init_PolygonObjectArrayStamped_polygon_objects(::map_interfaces::msg::PolygonObjectArrayStamped & msg)
  : msg_(msg)
  {}
  ::map_interfaces::msg::PolygonObjectArrayStamped polygon_objects(::map_interfaces::msg::PolygonObjectArrayStamped::_polygon_objects_type arg)
  {
    msg_.polygon_objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObjectArrayStamped msg_;
};

class Init_PolygonObjectArrayStamped_header
{
public:
  Init_PolygonObjectArrayStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonObjectArrayStamped_polygon_objects header(::map_interfaces::msg::PolygonObjectArrayStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PolygonObjectArrayStamped_polygon_objects(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObjectArrayStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::PolygonObjectArrayStamped>()
{
  return map_interfaces::msg::builder::Init_PolygonObjectArrayStamped_header();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__BUILDER_HPP_
