// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__STRUCT_HPP_
#define MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'mu_list_list'
// Member 'std_list_list'
// Member 'conf_list_list'
#include "mmp_interfaces/msg/detail/human_trajectory_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mmp_interfaces__msg__MotionPredictionResult __attribute__((deprecated))
#else
# define DEPRECATED__mmp_interfaces__msg__MotionPredictionResult __declspec(deprecated)
#endif

namespace mmp_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotionPredictionResult_
{
  using Type = MotionPredictionResult_<ContainerAllocator>;

  explicit MotionPredictionResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit MotionPredictionResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _mu_list_list_type =
    std::vector<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>>;
  _mu_list_list_type mu_list_list;
  using _std_list_list_type =
    std::vector<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>>;
  _std_list_list_type std_list_list;
  using _conf_list_list_type =
    std::vector<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>>;
  _conf_list_list_type conf_list_list;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__mu_list_list(
    const std::vector<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>> & _arg)
  {
    this->mu_list_list = _arg;
    return *this;
  }
  Type & set__std_list_list(
    const std::vector<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>> & _arg)
  {
    this->std_list_list = _arg;
    return *this;
  }
  Type & set__conf_list_list(
    const std::vector<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>> & _arg)
  {
    this->conf_list_list = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmp_interfaces__msg__MotionPredictionResult
    std::shared_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmp_interfaces__msg__MotionPredictionResult
    std::shared_ptr<mmp_interfaces::msg::MotionPredictionResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotionPredictionResult_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->mu_list_list != other.mu_list_list) {
      return false;
    }
    if (this->std_list_list != other.std_list_list) {
      return false;
    }
    if (this->conf_list_list != other.conf_list_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotionPredictionResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotionPredictionResult_

// alias to use template instance with default allocator
using MotionPredictionResult =
  mmp_interfaces::msg::MotionPredictionResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mmp_interfaces

#endif  // MMP_INTERFACES__MSG__DETAIL__MOTION_PREDICTION_RESULT__STRUCT_HPP_
