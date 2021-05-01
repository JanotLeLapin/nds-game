#include <nds.h>

#include "game.hpp"

int main(void)
{
  int angle = 0;

  Game game = Game();

  for (int i = 0; i < 32 * 32 / 2; i++)
  {
    game.getGfx()[i] = 1 | (1 << 8);
  }

  SPRITE_PALETTE[1] = RGB15(31, 0, 0);

  while (true)
  {
    scanKeys();

    int held = keysHeld();

    if (held & KEY_START)
      break;
    if (held & KEY_LEFT)
      angle += degreesToAngle(4);
    if (held & KEY_RIGHT)
      angle -= degreesToAngle(1);

    //-------------------------------------------------------------------------
    // Set the first rotation/scale matrix
    //
    // There are 32 rotation/scale matricies that can store sprite rotations
    // Any number of sprites can share a sprite rotation matrix or each sprite
    // (up to 32) can utilize a seperate rotation. Because this sprite is doubled
    // in size we have to adjust its position by subtracting half of its height and
    // width (20 - 16, 20 - 16, )
    //-------------------------------------------------------------------------
    oamRotateScale(&oamMain, 0, angle, intToFixed(1, 8), intToFixed(1, 8));

    oamSet(&oamMain,         //main graphics engine context
           0,                //oam index (0 to 127)
           20 - 16, 20 - 16, //x and y pixle location of the sprite
           0,                //priority, lower renders last (on top)
           0,                //this is the palette index if multiple palettes or the alpha value if bmp sprite
           SpriteSize_32x32,
           SpriteColorFormat_256Color,
           game.getGfx(), //pointer to the loaded graphics
           0,             //sprite rotation/scale matrix index
           true,          //double the size when rotating?
           false,         //hide the sprite?
           false, false,  //vflip, hflip
           false          //apply mosaic
    );

    //-------------------------------------------------------------------------
    // Because the sprite below has size double set to false it can never be larger than
    // 32x32 causing it to clip as it rotates.
    //-------------------------------------------------------------------------
    oamSet(&oamMain, //main graphics engine context
           1,        //oam index (0 to 127)
           204, 20,  //x and y pixle location of the sprite
           0,        //priority, lower renders last (on top)
           0,        //this is the palette index if multiple palettes or the alpha value if bmp sprite
           SpriteSize_32x32,
           SpriteColorFormat_256Color,
           game.getGfx(), //pointer to the loaded graphics
           0,             //sprite rotation/scale matrix index
           false,         //double the size when rotating?
           false,         //hide the sprite?
           false, false,  //vflip, hflip
           false          //apply mosaic
    );
    swiWaitForVBlank();
    game.update();
  }

  return 0;
}
