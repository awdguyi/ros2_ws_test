// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__BUILDER_HPP_
#define MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmp_interfaces/msg/detail/motion_prediction_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmp_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotionPredictionResult_conf_list_list
{
public:
  explicit Init_MotionPredictionResult_conf_list_list(::mmp_interfaces::msg::MotionPredictionResult & msg)
  : msg_(msg)
  {}
  ::mmp_interfaces::msg::MotionPredictionResult conf_list_list(::mmp_interfaces::msg::MotionPredictionResult::_conf_list_list_type arg)
  {
    msg_.conf_list_list = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmp_interfaces::msg::MotionPredictionResult msg_;
};

class Init_MotionPredictionResult_std_list_list
{
public:
  explicit Init_MotionPredictionResult_std_list_list(::mmp_interfaces::msg::MotionPredictionResult & msg)
  : msg_(msg)
  {}
  Init_MotionPredictionResult_conf_list_list std_list_list(::mmp_interfaces::msg::MotionPredictionResult::_std_list_list_type arg)
  {
    msg_.std_list_list = std::move(arg);
    return Init_MotionPredictionResult_conf_list_list(msg_);
  }

private:
  ::mmp_interfaces::msg::MotionPredictionResult msg_;
};

class Init_MotionPredictionResult_mu_list_list
{
public:
  explicit Init_MotionPredictionResult_mu_list_list(::mmp_interfaces::msg::MotionPredictionResult & msg)
  : msg_(msg)
  {}
  Init_MotionPredictionResult_std_list_list mu_list_list(::mmp_interfaces::msg::MotionPredictionResult::_mu_list_list_type arg)
  {
    msg_.mu_list_list = std::move(arg);
    return Init_MotionPredictionResult_std_list_list(msg_);
  }

private:
  ::mmp_interfaces::msg::MotionPredictionResult msg_;
};

class Init_MotionPredictionResult_header
{
public:
  Init_MotionPredictionResult_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotionPredictionResult_mu_list_list header(::mmp_interfaces::msg::MotionPredictionResult::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotionPredictionResult_mu_list_list(msg_);
  }

private:
  ::mmp_interfaces::msg::MotionPredictionResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmp_interfaces::msg::MotionPredictionResult>()
{
  return mmp_interfaces::msg::builder::Init_MotionPredictionResult_header();
}

}  // namespace mmp_interfaces

#endif  // MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__BUILDER_HPP_
