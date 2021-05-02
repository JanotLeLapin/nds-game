#include "game.hpp"

#include <nds.h>

Game::Game()
{
  videoSetMode(MODE_0_2D);
  vramSetBankA(VRAM_A_MAIN_SPRITE);
  oamInit(&oamMain, SpriteMapping_1D_32, false);

  m_Gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

  for (int i = 0; i < 32 * 32 / 2; i++)
  {
    m_Gfx[i] = 1 | (1 << 8);
  }
}

void Game::update()
{
  for (unsigned int i = 0; i < m_Entities.size(); i++)
  {
    // Update Entity
    m_Entities[i]->update();

    // Render Entity
    oamSet(&oamMain,                                               //main graphics engine context
           i,                                                      //oam index (0 to 127)
           m_Entities[i]->getX() - 16, m_Entities[i]->getY() - 16, //x and y pixle location of the sprite
           0,                                                      //priority, lower renders last (on top)
           m_Entities[i]->getColorIndex(),                         //this is the palette index if multiple palettes or the alpha value if bmp sprite
           SpriteSize_32x32,
           SpriteColorFormat_256Color,
           m_Gfx,        //pointer to the loaded graphics
           -1,           //sprite rotation/scale matrix index
           false,        //double the size when rotating?
           false,        //hide the sprite?
           false, false, //vflip, hflip
           false         //apply mosaic
    );
  }
  swiWaitForVBlank();
  oamUpdate(&oamMain);
}

void Game::addEntity(Entity *entity)
{
  m_Entities.push_back(entity);
}
