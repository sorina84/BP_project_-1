#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

typedef struct Player {
    Vector2 pos;
    Vector2 dir;
    float radius;
    float speed;
    float rotSpeed;
} Player;

Player PlayerCreate(float x, float y, float radius, float speed);
void PlayerUpdate(Player *p);
void PlayerDraw(const Player *p);

#endif