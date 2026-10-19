#pragma once
#include <TFT_eSPI.h>
#include <stdint.h>

// HoneyBadgerWatch -- the Texugo mascot, as RGB565 sprites blitted onto the
// 8-bit frame. The sprite data is generated from the PNGs in
// ~/Documents/texugo-sprite by tools/png2sprite.py into texugo_sprites.h;
// only texugo.cpp includes that (big) header, so the arrays are defined once.
//
// This is step 1 of the Squachy -> Texugo swap: the art renders through the
// firmware's own pixel path. Wiring it into the boot splash and the idle
// mascot comes next.
namespace Texugo {

// Blit an RGB565 sprite, skipping transparent (KEY) pixels. Each source
// pixel becomes a scale x scale block; (x, y) is the destination top-left.
// Colours convert to the 8-bit frame via drawPixel/fillRect, the same path
// drawBody() draws through.
void draw(TFT_eSPI& t, const uint16_t* px, int w, int h, int x, int y, int scale);

// The named poses. (x, y) is the top-left; the sprites are 64x64.
void drawFofo(TFT_eSPI& t, int x, int y, int scale);     // front, waving -- the main idle pose
void drawRetrato(TFT_eSPI& t, int x, int y, int scale);  // big head -- the icon / boot
void drawCorpo(TFT_eSPI& t, int x, int y, int scale);    // standing, front

}
