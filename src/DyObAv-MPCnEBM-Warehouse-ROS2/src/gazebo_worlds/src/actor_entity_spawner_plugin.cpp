#include <memory>
#include <string>
#include <thread>

#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo_msgs/srv/spawn_entity.hpp>
#include <rclcpp/rclcpp.hpp>

namespace gazebo
{

class ActorEntitySpawnerPlugin : public WorldPlugin
{
public:
  ActorEntitySpawnerPlugin() = default;

  ~ActorEntitySpawnerPlugin() override
  {
    if (executor_) {
      executor_->cancel();
    }
    if (spin_thread_.joinable()) {
      spin_thread_.join();
    }
  }

  void Load(physics::WorldPtr world, sdf::ElementPtr) override
  {
    world_ = world;

    if (!rclcpp::ok()) {
      int argc = 0;
      char ** argv = nullptr;
      rclcpp::init(argc, argv);
    }

    node_ = std::make_shared<rclcpp::Node>("actor_entity_spawner");
    service_ = node_->create_service<gazebo_msgs::srv::SpawnEntity>(
      "/spawn_actor_entity",
      [this](
        const std::shared_ptr<gazebo_msgs::srv::SpawnEntity::Request> request,
        std::shared_ptr<gazebo_msgs::srv::SpawnEntity::Response> response) {
        this->SpawnActor(request, response);
      });

    executor_ = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
    executor_->add_node(node_);
    spin_thread_ = std::thread([this]() { executor_->spin(); });

    gzmsg << "[ActorEntitySpawner] Ready on /spawn_actor_entity\n";
  }

private:
  void SpawnActor(
    const std::shared_ptr<gazebo_msgs::srv::SpawnEntity::Request> request,
    std::shared_ptr<gazebo_msgs::srv::SpawnEntity::Response> response)
  {
    if (!world_) {
      response->success = false;
      response->status_message = "Gazebo world is not available";
      return;
    }
    if (request->xml.empty()) {
      response->success = false;
      response->status_message = "Actor XML is empty";
      return;
    }

    world_->InsertModelString(request->xml);
    response->success = true;
    response->status_message = "Actor insert request sent";
    gzmsg << "[ActorEntitySpawner] Inserted actor request: " << request->name << "\n";
  }

  physics::WorldPtr world_;
  rclcpp::Node::SharedPtr node_;
  rclcpp::Service<gazebo_msgs::srv::SpawnEntity>::SharedPtr service_;
  std::shared_ptr<rclcpp::executors::SingleThreadedExecutor> executor_;
  std::thread spin_thread_;
};

GZ_REGISTER_WORLD_PLUGIN(ActorEntitySpawnerPlugin)

}  // namespace gazebo
