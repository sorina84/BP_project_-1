#include <raylib.h>
#include "map.h"

int main(void)
{
    const int screenWidth  = MAP_W * TILE;
    const int screenHeight = MAP_H * TILE;

    InitWindow(screenWidth, screenHeight, "BP Project - Phase 1");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawMap2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}