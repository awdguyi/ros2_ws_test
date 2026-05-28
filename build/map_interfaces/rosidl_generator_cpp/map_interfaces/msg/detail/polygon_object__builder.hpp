// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/polygon_object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_PolygonObject_object_semantic_t
{
public:
  explicit Init_PolygonObject_object_semantic_t(::map_interfaces::msg::PolygonObject & msg)
  : msg_(msg)
  {}
  ::map_interfaces::msg::PolygonObject object_semantic_t(::map_interfaces::msg::PolygonObject::_object_semantic_t_type arg)
  {
    msg_.object_semantic_t = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

class Init_PolygonObject_object_motion_t
{
public:
  explicit Init_PolygonObject_object_motion_t(::map_interfaces::msg::PolygonObject & msg)
  : msg_(msg)
  {}
  Init_PolygonObject_object_semantic_t object_motion_t(::map_interfaces::msg::PolygonObject::_object_motion_t_type arg)
  {
    msg_.object_motion_t = std::move(arg);
    return Init_PolygonObject_object_semantic_t(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

class Init_PolygonObject_object_shape_t
{
public:
  explicit Init_PolygonObject_object_shape_t(::map_interfaces::msg::PolygonObject & msg)
  : msg_(msg)
  {}
  Init_PolygonObject_object_motion_t object_shape_t(::map_interfaces::msg::PolygonObject::_object_shape_t_type arg)
  {
    msg_.object_shape_t = std::move(arg);
    return Init_PolygonObject_object_motion_t(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

class Init_PolygonObject_centroid
{
public:
  explicit Init_PolygonObject_centroid(::map_interfaces::msg::PolygonObject & msg)
  : msg_(msg)
  {}
  Init_PolygonObject_object_shape_t centroid(::map_interfaces::msg::PolygonObject::_centroid_type arg)
  {
    msg_.centroid = std::move(arg);
    return Init_PolygonObject_object_shape_t(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

class Init_PolygonObject_polygon
{
public:
  explicit Init_PolygonObject_polygon(::map_interfaces::msg::PolygonObject & msg)
  : msg_(msg)
  {}
  Init_PolygonObject_centroid polygon(::map_interfaces::msg::PolygonObject::_polygon_type arg)
  {
    msg_.polygon = std::move(arg);
    return Init_PolygonObject_centroid(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

class Init_PolygonObject_object_name
{
public:
  explicit Init_PolygonObject_object_name(::map_interfaces::msg::PolygonObject & msg)
  : msg_(msg)
  {}
  Init_PolygonObject_polygon object_name(::map_interfaces::msg::PolygonObject::_object_name_type arg)
  {
    msg_.object_name = std::move(arg);
    return Init_PolygonObject_polygon(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

class Init_PolygonObject_object_id
{
public:
  Init_PolygonObject_object_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PolygonObject_object_name object_id(::map_interfaces::msg::PolygonObject::_object_id_type arg)
  {
    msg_.object_id = std::move(arg);
    return Init_PolygonObject_object_name(msg_);
  }

private:
  ::map_interfaces::msg::PolygonObject msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::PolygonObject>()
{
  return map_interfaces::msg::builder::Init_PolygonObject_object_id();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__BUILDER_HPP_
