#pragma once

#include "rigid.hpp"

class Player : public Rigid
{
public:
  /**
   * A Player
   * @param x The x coordinate of the Entity
   * @param y The y coordinate of the Entity
   * @param weight The weight of the RigidBody
   * @param colorIndex The palette color index of the Entity
   */
  Player(int x, int y, int weight, int colorIndex);

  /**
   * @param strenght The height of the jump.
   */
  void jump(unsigned int strenght);
};
