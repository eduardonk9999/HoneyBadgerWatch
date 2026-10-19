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

// The animated mascot. (x, y) is the top-left; each 64x64 frame is drawn at
// `scale`. `now` drives the animation; `mode` picks what he is doing:
//   IDLE_MODE -- resting, with a blink every few seconds
//   WAVE_MODE -- waving hello (boot, and the WAVE mood)
//   MAL_MODE  -- angry: yellow slit eyes, fangs, raised fist (a detection)
enum Mode : uint8_t { IDLE_MODE = 0, WAVE_MODE = 1, MAL_MODE = 2 };
void drawMascot(TFT_eSPI& t, int x, int y, int scale, uint8_t mode, uint32_t now);
void drawRetrato(TFT_eSPI& t, int x, int y, int scale);  // big head -- the icon
void drawCorpo(TFT_eSPI& t, int x, int y, int scale);    // standing, front

}
