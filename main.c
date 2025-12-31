#include <raylib.h>
#include "map.h"
#include "player.h"

int main(void)
{
    const int screenWidth  = MAP_W * TILE;
    const int screenHeight = MAP_H * TILE;

    InitWindow(screenWidth, screenHeight, "BP Project - Phase 1");
    SetTargetFPS(60);

    Player player = PlayerCreate(2.5f * TILE, 1.5f * TILE, 8.0f, 120.0f);

    while (!WindowShouldClose())
    {
        PlayerUpdate(&player);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawMap2D();
        PlayerDraw(&player);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}