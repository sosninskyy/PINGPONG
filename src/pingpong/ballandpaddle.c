#include "raylib.h"

struct Cir {
    int x;
    int y;
    int rad;
    int speedx;
    int speedy;
};

//rectangle - rect.x - withd in x; position in y; width in y
//circle 
void checkKeys(Vector3 *rect) {
    if (IsKeyDown(KEY_W) && rect->y > 0) {
        rect->y -= 5;
    }
    if (IsKeyDown(KEY_S) && (rect->y + rect->z) < GetScreenHeight()) {
        rect->y += 5;
    }
}

void restart(struct Cir *cir, Vector3 *rect) {
    cir->x = GetScreenWidth() / 2;
    cir->y = GetScreenHeight() / 2;
    rect->y = GetScreenHeight() / 2;
}


void paddle(Vector3 *rect) {
    DrawRectangle(GetScreenWidth() - rect->x, rect->y, rect->x, rect->z, WHITE);
}

void circle(struct Cir *cir, Vector3 *rect) {
    int deaths = 0;
    if ((cir->y + cir->rad) >= GetScreenHeight()) {
        cir->y = GetScreenHeight() - cir->rad;
        cir->speedy = cir->speedy * -1;
    }

    if ((cir->y - cir->rad) <= 0) {
        cir->y = 0 + cir->rad;
        cir->speedy = cir->speedy * -1;
    }

    if ((cir->x + cir->rad) >= (GetScreenWidth() - rect->x) && (cir->y >= rect->y && cir->y <= rect->y + rect->z)) { 
        cir->x = (GetScreenWidth() - rect->x) - cir->rad;
        cir->speedx = cir->speedx * -1; 
    }

    if ((cir->x - cir->rad) <= 0) {
        cir->x = 0 + cir->rad;
        cir->speedx = cir->speedx * -1; 
    }

    cir->x += cir->speedx;
    cir->y += cir->speedy;

    if ((cir->x + cir->rad) >= GetScreenWidth()) {
        restart(cir, rect);
        deaths += 1;
    }
    DrawCircle(cir->x, cir->y, cir->rad, WHITE);
    DrawText(TextFormat("Deaths: %d", deaths), 20, 20, 20, WHITE);
}
