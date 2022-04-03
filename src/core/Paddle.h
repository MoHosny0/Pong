#ifndef PADDLE_H
#define PADDLE_H

#include "Vec2D.h"
#include "Terrain.h"

struct Rectangle
{
    float x;
    float y;
};

class Paddle
{

private:
    Rectangle rect;

public:
    Paddle();
    Paddle(const Rectangle StartingPosition);
    const Rectangle &getPosition() const;
    void setPositionSize(const Rectangle NewPositionSize);
    void setPosition(const Vec2D NewPosition);
    void haut(const Terrain &T);
    void bas(const Terrain &T);
};

#endif