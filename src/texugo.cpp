#include "texugo.h"
#include "texugo_sprites.h"

namespace Texugo {

void draw(TFT_eSPI& t, const uint16_t* px, int w, int h, int x, int y, int scale) {
    if (scale < 1) scale = 1;
    for (int sy = 0; sy < h; sy++) {
        for (int sx = 0; sx < w; sx++) {
            const uint16_t c = px[sy * w + sx];
            if (c == KEY) continue;
            if (scale == 1) t.drawPixel(x + sx, y + sy, c);
            else            t.fillRect(x + sx * scale, y + sy * scale, scale, scale, c);
        }
    }
}

void drawMascot(TFT_eSPI& t, int x, int y, int scale, bool mal, uint32_t now) {
    const uint16_t* f;
    if (mal) f = ((now / 250u) % 2u) ? MAL2 : MAL1;       // an angry twitch
    else     f = ((now % 3000u) < 150u) ? BLINK : IDLE;   // blink ~150ms every 3s
    draw(t, f, IDLE_W, IDLE_H, x, y, scale);              // all frames are 64x64
}
void drawRetrato(TFT_eSPI& t, int x, int y, int scale) { draw(t, RETRATO, RETRATO_W, RETRATO_H, x, y, scale); }
void drawCorpo(TFT_eSPI& t, int x, int y, int scale)   { draw(t, CORPO,   CORPO_W,   CORPO_H,   x, y, scale); }

}
