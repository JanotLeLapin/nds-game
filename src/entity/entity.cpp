#include "entity.hpp"

#include <nds.h>
#include <cstdio>

Entity::Entity(int x, int y, int colorIndex)
{
  m_X = x;
  m_Y = y;
  m_ColorIndex = colorIndex;
  m_Frozen = false;
}

void Entity::update() {}
