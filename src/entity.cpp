#include "entity.hpp"

#include <nds.h>
#include <cstdio>

Entity::Entity(int x, int y, bool rigid, int colorIndex)
{
  m_X = x;
  m_Y = y;
  m_Acc = 1;
  m_ColorIndex = colorIndex;
  m_Rigid = rigid;
}

void Entity::update()
{
  if (m_Rigid && m_Y + m_Acc < SCREEN_HEIGHT - 16)
  {
    m_Y += m_Acc;
    m_Acc++;
  }
  else if (m_Y + m_Acc > SCREEN_WIDTH - 16)
  {
    m_Acc = SCREEN_WIDTH - m_Y;
    printf("\nacc: %d, y: %d", m_Acc, m_Y);
  }
  else
  {
    m_Acc = 1;
  }
}
