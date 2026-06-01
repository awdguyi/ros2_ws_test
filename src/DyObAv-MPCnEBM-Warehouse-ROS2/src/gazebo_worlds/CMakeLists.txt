cmake_minimum_required(VERSION 3.8)
project(gazebo_worlds)

find_package(ament_cmake REQUIRED)
find_package(gazebo REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(rclcpp REQUIRED)

add_library(actor_entity_spawner_plugin SHARED
  src/actor_entity_spawner_plugin.cpp
)
target_include_directories(actor_entity_spawner_plugin PRIVATE
  ${GAZEBO_INCLUDE_DIRS}
)
target_link_libraries(actor_entity_spawner_plugin
  ${GAZEBO_LIBRARIES}
)
ament_target_dependencies(actor_entity_spawner_plugin
  gazebo_msgs
  rclcpp
)

install(DIRECTORY launch worlds models DESTINATION share/${PROJECT_NAME})
install(PROGRAMS
  scripts/random_actor_respawner.py
  DESTINATION lib/${PROJECT_NAME}
)
install(TARGETS actor_entity_spawner_plugin
  LIBRARY DESTINATION lib
)

ament_package()
