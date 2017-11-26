#pragma once

#include <unordered_map>

class Component {};

class Entity {
public:

private:
    std::unordered_map<uint32_t, Component> m_components;
};
