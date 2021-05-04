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
  Rigid rigidBody(120, 20, 1, 2);

  game.addEntity(&eRigid);
  game.addEntity(&eStatic);
  game.addEntity(&rigidBody);

  Game::setColor(0, RGB15(31, 0, 0));
  Game::setColor(1, RGB15(0, 31, 0));
  Game::setColor(2, RGB15(0, 0, 31));

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

    oamRotateScale(&oamMain, 0, angle, intToFixed(1, 8), intToFixed(1, 8));

    game.update();
  }

  return 0;
}
