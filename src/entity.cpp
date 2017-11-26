#include "entity.hpp"

uint32_t Entity::m_globalID = 0;

Entity::Entity()
    : m_id{++m_globalID}
{
}
