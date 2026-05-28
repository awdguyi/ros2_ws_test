// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/ObjectShapeType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_SHAPE_TYPE__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_SHAPE_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/object_shape_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectShapeType_o_shape_type
{
public:
  Init_ObjectShapeType_o_shape_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_interfaces::msg::ObjectShapeType o_shape_type(::map_interfaces::msg::ObjectShapeType::_o_shape_type_type arg)
  {
    msg_.o_shape_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::ObjectShapeType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::ObjectShapeType>()
{
  return map_interfaces::msg::builder::Init_ObjectShapeType_o_shape_type();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_SHAPE_TYPE__BUILDER_HPP_
