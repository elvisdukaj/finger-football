#pragma once

#include "math.hpp"
#include <vector>
#include <type_traits>
#include <cstdint>

using Vector3f = float[3];

struct Component {};cd ../

struct PositionComponent : public Component {
    Vector3f position;
};

struct RotationComponent : public Component {
    Vector3f position;
};

struct RigidBodyCompont : public Component {
    float mass;
    Vector3f force;
    Vector3f torque;
};

class Entity {
public:
    Entity();

    template<typename ComponentType, typename... Args>
    void addComponent(Args&&... args)
    {
        m_components.emplace_back(std::forward<Args>(args)...);
    }

private:
    const uint32_t m_id;
    std::vector<Component> m_components;
    static uint32_t m_globalID;
};
