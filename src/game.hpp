#include <nds.h>

class Game
{
private:
  u16 *m_Gfx;

public:
  Game();
  void update();

  inline u16 *getGfx() { return m_Gfx; };
};
