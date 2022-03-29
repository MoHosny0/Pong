#ifndef PADDLE_H
#define PADDLE_H

#include "Vec2D.h"
#include "Terrain.h"

struct Rectangle
{
    float x;
    float y;
    float width;
    float height;
};

class Paddle
{

private:
    Rectangle rect;

public:
    Paddle();
    Paddle(const Rectangle startingPosition);
    const Rectangle &GetPositionSize() const;
    void setPositionSize(const Rectangle newPositionSize);
    void setPosition(const Vec2D newPosition);
    void haut(const Terrain &t);
    void bas(const Terrain &t);
};

#endif