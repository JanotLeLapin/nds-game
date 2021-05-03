#include "rigid.hpp"

#include <nds.h>
#include <cstdio>

Rigid::Rigid(int x, int y, int weight, int colorIndex) : Entity(x, y, colorIndex)
{
  m_Weight = weight;
}

void Rigid::update()
{
  if (m_Frozen)
    return;
  if (m_Y + m_Acc < SCREEN_HEIGHT - 16)
  {
    m_Y += m_Acc * m_Weight;
    m_Acc++;
  }
  else
  {
    m_Y = SCREEN_HEIGHT - 16;
    m_Acc = 0;
  }
}
