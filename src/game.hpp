#pragma once

#include <nds.h>
#include <vector>

#include "entity.hpp"

class Game
{
private:
  u16 *m_Gfx;
  std::vector<Entity *> m_Entities;

public:
  Game();
  /**
   * Should be runned at each frame.
   */
  void update();
  /**
   * Adds a new Entity.
   */
  void addEntity(Entity *entity);

  /**
   * @returns the main graphics.
   */
  inline u16 *getGfx() { return m_Gfx; };
  /**
   * @returns an array of Entities.
   */
  inline std::vector<Entity *> getEntities() { return m_Entities; };
};
