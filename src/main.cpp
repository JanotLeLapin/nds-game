#include <nds.h>

#include "game.hpp"
#include "entity/entity.hpp"
#include "entity/rigid.hpp"
#include "entity/player.hpp"

int main(void)
{
  int angle = 0;
  touchPosition touch;

  PrintConsole *console = consoleDemoInit();
  consoleSetWindow(console, 15, 1, 12, 16);
  consoleSelect(console);

  Game game = Game();

  Rigid rigidBody(20, 20, 1, 0);
  Player player(SCREEN_WIDTH - 20, 20, 1, 1);

  game.addEntity(&rigidBody);
  game.addEntity(&player);

  Game::setColor(0, RGB15(31, 0, 0));
  Game::setColor(1, RGB15(0, 12, 21));

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
      player.setX(player.getX() - 4);
    if (held & KEY_RIGHT)
      player.setX(player.getX() + 4);
    if (held & KEY_B || held & KEY_A || held & KEY_UP)
      player.jump(4);

    oamRotateScale(&oamMain, 0, angle, intToFixed(1, 8), intToFixed(1, 8));

    game.update();
  }

  return 0;
}
