#include "game.hpp"

#include <nds.h>

Game::Game()
{
  videoSetMode(MODE_0_2D);
  vramSetBankA(VRAM_A_MAIN_SPRITE);
  oamInit(&oamMain, SpriteMapping_1D_32, false);

  m_Gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}

void Game::update()
{
  oamUpdate(&oamMain);
}
