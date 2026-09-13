#include "raylib.h"
#include "ballandpaddle.h"

int main() {
    InitWindow(800, 600, "PingPong");
    SetTargetFPS(60);
    Vector3 rect = {10, 400, 50}; 
    struct Cir cir = {400, 300, 10, 6, 6};
    int deaths = 0;
    while(!WindowShouldClose()) {
        BeginDrawing();
            checkKeys(&rect);
            paddle(&rect);
            circle(&cir, &rect, &deaths);
            DrawText(TextFormat("Deaths: %d", deaths), 20, 20, 20, WHITE);
            ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}