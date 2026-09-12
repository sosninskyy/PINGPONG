#include "raylib.h"

struct Cir {
    int x;
    int y;
    int rad;
    int speedx;
    int speedy;
};

void checkKeys(Vector3 *rect);
void paddle(Vector3 *rect);
void circle(struct Cir *cir, Vector3 *rect);
void startScreen();