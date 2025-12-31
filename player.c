#include "player.h"
#include <raymath.h>
#include "map.h"
#include <math.h>

Player PlayerCreate(float x, float y, float radius, float speed)
{
    Player p;
    p.pos = (Vector2){ x, y };
    p.dir =(Vector2){1.0f,0.0f};
    p.radius = radius;
    p.speed = speed;
    p.rotSpeed=2.5f;
    return p;
}
void PlayerUpdate(Player *p)
{
    float dt = GetFrameTime();

    if (IsKeyDown(KEY_LEFT))
    {
        float angle = p->rotSpeed * dt;
        float oldX = p->dir.x;
        p->dir.x = p->dir.x * cosf(angle) - p->dir.y * sinf(angle);
        p->dir.y = oldX       * sinf(angle) + p->dir.y * cosf(angle);
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        float angle = -p->rotSpeed * dt;
        float oldX = p->dir.x;
        p->dir.x = p->dir.x * cosf(angle) - p->dir.y * sinf(angle);
        p->dir.y = oldX       * sinf(angle) + p->dir.y * cosf(angle);
    }

    Vector2 move = (Vector2){0};

    if (IsKeyDown(KEY_W)) { move.x += p->dir.x; move.y += p->dir.y; }
    if (IsKeyDown(KEY_S)) { move.x -= p->dir.x; move.y -= p->dir.y; }

    Vector2 right = (Vector2){ p->dir.y, -p->dir.x };
    if (IsKeyDown(KEY_D)) { move.x += right.x; move.y += right.y; }
    if (IsKeyDown(KEY_A)) { move.x -= right.x; move.y -= right.y; }

    if (move.x == 0 && move.y == 0) return;

    move = Vector2Normalize(move);

    Vector2 nextPos = p->pos;

    float nextX = nextPos.x + move.x * p->speed * dt;
    if (!MapCircleCollides(nextX, nextPos.y, p->radius))
        nextPos.x = nextX;

    float nextY = nextPos.y + move.y * p->speed * dt;
    if (!MapCircleCollides(nextPos.x, nextY, p->radius))
        nextPos.y = nextY;

    p->pos = nextPos;
}
void PlayerDraw(const Player *p)
{
    DrawCircleV(p->pos, p->radius, RED);

    DrawLine(
        (int)p->pos.x, (int)p->pos.y,
        (int)(p->pos.x + p->dir.x * 20),
        (int)(p->pos.y + p->dir.y * 20),
        BLUE
    );
}