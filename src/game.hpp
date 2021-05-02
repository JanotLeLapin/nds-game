#include <nds.h>

#include "entity.hpp"

class Game
{
private:
  u16 *m_Gfx;
  std::vector<Entity *> m_Entities;

public:
  Game();
  void update();
  void addEntity(Entity *entity);

  inline u16 *getGfx() { return m_Gfx; };
  inline std::vector<Entity *> getEntities() { return m_Entities; };
};
