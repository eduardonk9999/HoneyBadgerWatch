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

void drawFofo(TFT_eSPI& t, int x, int y, int scale)    { draw(t, FOFO,    FOFO_W,    FOFO_H,    x, y, scale); }
void drawRetrato(TFT_eSPI& t, int x, int y, int scale) { draw(t, RETRATO, RETRATO_W, RETRATO_H, x, y, scale); }
void drawCorpo(TFT_eSPI& t, int x, int y, int scale)   { draw(t, CORPO,   CORPO_W,   CORPO_H,   x, y, scale); }

}
