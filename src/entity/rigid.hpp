#pragma once

#include "entity.hpp"

class Rigid : public Entity
{
protected:
  int m_Weight, m_Acc;

public:
  /**
   * A rigid body
   * @param x The x coordinate of the Entity
   * @param y The y coordinate of the Entity
   * @param weight The weight of the RigidBody
   * @param colorIndex The palette color index of the Entity
   */
  Rigid(int x, int y, int weight, int colorIndex);

  void update() override;

  inline int getWeight() { return m_Weight; };
  /**
   * @returns The acceleration of the RigidBody.
   */
  inline int getAcc() { return m_Acc; };
};
