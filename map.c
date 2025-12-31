#include <raylib.h>
#include "map.h"

int map_world[MAP_H][MAP_W] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

void DrawMap2D(void)
{
    for (int y = 0; y < MAP_H; y++)
    {
        for (int x = 0; x < MAP_W; x++)
        {
            Rectangle cell = (Rectangle){ x * TILE, y * TILE, TILE, TILE };

            if (map_world[y][x] == 1)
                DrawRectangleRec(cell, GRAY);
            else
                DrawRectangleLinesEx(cell, 1, DARKGRAY);
        }
    }
}
int MapIsInside(float x ,float y)
{
    return (x>=0 && y>=0 && x<MAP_W*TILE && y<MAP_H*TILE);
}
int MapIsWallAt(float x ,float y)
{
    if(!MapIsInside(x,y)) return 1;

    int mx=(int)(x/TILE);
    int my=(int)(y/TILE);

    return (map_world[my][mx]==1);
}
int MapCircleCollides(float x, float y, float r)
{
    if (MapIsWallAt(x + r, y)) return 1;
    if (MapIsWallAt(x - r, y)) return 1;
    if (MapIsWallAt(x, y + r)) return 1;
    if (MapIsWallAt(x, y - r)) return 1;
    return 0;
}