#include <nds.h>
#include <cstdio>

#include "game.hpp"
#include "entity/entity.hpp"
#include "entity/rigid.hpp"

int main(void)
{
  int angle = 0;
  touchPosition touch;

  PrintConsole *console = consoleDemoInit();
  consoleSetWindow(console, 15, 1, 12, 16);
  consoleSelect(console);

  Game game = Game();

  Entity eRigid(20, 20, 0);
  Entity eStatic(SCREEN_WIDTH - 20, 20, 1);
  Rigid rigidBody(120, 20, 1, 1);

  game.addEntity(&eRigid);
  game.addEntity(&eStatic);
  game.addEntity(&rigidBody);

  SPRITE_PALETTE[1] = RGB15(31, 0, 0);

  while (true)
  {
    scanKeys();

    int held = keysHeld();

    if (held & KEY_START)
      break;
    if (held & KEY_TOUCH)
    {
      touchRead(&touch);
      rigidBody.setFrozen(true);
      rigidBody.setX(touch.px);
      rigidBody.setY(touch.py);
    }
    else
    {
      rigidBody.setFrozen(false);
    }
    if (held & KEY_LEFT)
      angle += degreesToAngle(4);
    if (held & KEY_RIGHT)
      angle -= degreesToAngle(1);

    oamRotateScale(&oamMain, 0, angle, intToFixed(1, 8), intToFixed(1, 8));

    game.update();
  }

  return 0;
}
