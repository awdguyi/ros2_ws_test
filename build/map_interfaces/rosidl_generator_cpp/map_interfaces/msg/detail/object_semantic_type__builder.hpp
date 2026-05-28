// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from map_interfaces:msg/ObjectSemanticType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__BUILDER_HPP_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "map_interfaces/msg/detail/object_semantic_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace map_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectSemanticType_o_semantic_type
{
public:
  Init_ObjectSemanticType_o_semantic_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::map_interfaces::msg::ObjectSemanticType o_semantic_type(::map_interfaces::msg::ObjectSemanticType::_o_semantic_type_type arg)
  {
    msg_.o_semantic_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::map_interfaces::msg::ObjectSemanticType msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::map_interfaces::msg::ObjectSemanticType>()
{
  return map_interfaces::msg::builder::Init_ObjectSemanticType_o_semantic_type();
}

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__BUILDER_HPP_
