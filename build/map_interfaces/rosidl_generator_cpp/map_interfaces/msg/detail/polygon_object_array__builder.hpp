// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/polygon_object_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_PolygonObjectArray_polygon_objects
{
public:
  Init_PolygonObjectArray_polygon_objects()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_interfaces::msg::PolygonObjectArray polygon_objects(::map_interfaces::msg::PolygonObjectArray::_polygon_objects_type arg)
  {
    msg_.polygon_objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObjectArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::PolygonObjectArray>()
{
  return map_interfaces::msg::builder::Init_PolygonObjectArray_polygon_objects();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__BUILDER_HPP_
