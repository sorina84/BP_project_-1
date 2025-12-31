#ifndef MAP_MODULE_H
#define MAP_MODULE_H

#define MAP_W 10
#define MAP_H 10
#define TILE 48

void DrawMap2D(void);
int MapIsWallAt(float x ,float y);
int MapIsInside(float x,float y);
int MapCircleCollides(float x,float y,float r);

#endif