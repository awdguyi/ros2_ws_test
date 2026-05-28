#include <ctime>
#include <map>
#include <string>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <ignition/math/Rand.hh>

namespace gazebo {

class RandomActorOffsetPlugin : public WorldPlugin
{
public:
    void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf) override
    {
        ignition::math::Rand::Seed(static_cast<unsigned int>(std::time(nullptr)));

        double default_period = 55.0;
        if (_sdf->HasElement("default_period"))
            default_period = _sdf->Get<double>("default_period");

        // Read per-actor periods: <actor><name>actor1</name><period>65.0</period></actor>
        std::map<std::string, double> actor_periods;
        if (_sdf->HasElement("actor")) {
            auto elem = _sdf->GetElement("actor");
            while (elem) {
                std::string name = elem->Get<std::string>("name");
                double period = default_period;
                if (elem->HasElement("period"))
                    period = elem->Get<double>("period");
                actor_periods[name] = period;
                elem = elem->GetNextElement("actor");
            }
        }

        for (unsigned int i = 0; i < _world->ModelCount(); ++i) {
            auto model = _world->ModelByIndex(i);
            auto actor = boost::dynamic_pointer_cast<physics::Actor>(model);
            if (!actor) continue;

            std::string name = actor->GetName();
            double period = (actor_periods.count(name) > 0)
                            ? actor_periods.at(name) : default_period;

            double offset = ignition::math::Rand::DblUniform(0.0, period);
            actor->SetScriptTime(offset);
            gzmsg << "[RandomActorOffset] " << name
                  << " start_offset=" << offset << "s / period=" << period << "s\n";
        }
    }
};

GZ_REGISTER_WORLD_PLUGIN(RandomActorOffsetPlugin)

} // namespace gazebo
