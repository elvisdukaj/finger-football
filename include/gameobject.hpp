#pragma once

#include <unordered_map>

class GameComponent {
public:

private:
};

class GameObject {
public:

private:
    std::unordered_map<int, GameComponent*> m_components;
};
