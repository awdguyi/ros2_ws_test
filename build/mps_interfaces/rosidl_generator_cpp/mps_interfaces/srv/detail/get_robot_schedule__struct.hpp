// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mps_interfaces:srv/GetRobotSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__STRUCT_HPP_
#define MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Request __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Request __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRobotSchedule_Request_
{
  using Type = GetRobotSchedule_Request_<ContainerAllocator>;

  explicit GetRobotSchedule_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0ll;
      this->current_time = 0.0;
    }
  }

  explicit GetRobotSchedule_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0ll;
      this->current_time = 0.0;
    }
  }

  // field types and members
  using _robot_id_type =
    int64_t;
  _robot_id_type robot_id;
  using _current_time_type =
    double;
  _current_time_type current_time;

  // setters for named parameter idiom
  Type & set__robot_id(
    const int64_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__current_time(
    const double & _arg)
  {
    this->current_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Request
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Request
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRobotSchedule_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->current_time != other.current_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRobotSchedule_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRobotSchedule_Request_

// alias to use template instance with default allocator
using GetRobotSchedule_Request =
  mps_interfaces::srv::GetRobotSchedule_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mps_interfaces


// Include directives for member types
// Member 'path_schedule'
#include "mps_interfaces/msg/detail/path_schedule_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Response __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Response __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRobotSchedule_Response_
{
  using Type = GetRobotSchedule_Response_<ContainerAllocator>;

  explicit GetRobotSchedule_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_schedule(_init)
  {
    (void)_init;
  }

  explicit GetRobotSchedule_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path_schedule(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _path_schedule_type =
    mps_interfaces::msg::PathScheduleStamped_<ContainerAllocator>;
  _path_schedule_type path_schedule;

  // setters for named parameter idiom
  Type & set__path_schedule(
    const mps_interfaces::msg::PathScheduleStamped_<ContainerAllocator> & _arg)
  {
    this->path_schedule = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Response
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__srv__GetRobotSchedule_Response
    std::shared_ptr<mps_interfaces::srv::GetRobotSchedule_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRobotSchedule_Response_ & other) const
  {
    if (this->path_schedule != other.path_schedule) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRobotSchedule_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRobotSchedule_Response_

// alias to use template instance with default allocator
using GetRobotSchedule_Response =
  mps_interfaces::srv::GetRobotSchedule_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mps_interfaces

namespace mps_interfaces
{

namespace srv
{

struct GetRobotSchedule
{
  using Request = mps_interfaces::srv::GetRobotSchedule_Request;
  using Response = mps_interfaces::srv::GetRobotSchedule_Response;
};

}  // namespace srv

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__STRUCT_HPP_
