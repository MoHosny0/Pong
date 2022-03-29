#include "Paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(const Rectangle startingPosition)
{
    rect = startingPosition;
}
const Rectangle &Paddle::getPositionSize() const
{
    return rect;
}
void Paddle::setPositionSize(const Rectangle newPositionSize)
{
    rect = newPositionSize;
}
void Paddle::setPosition(const Vec2D newPosition)
{
    rect.x = newPosition.getX();
    rect.y = newPosition.getY();
}
void Paddle::haut(const Terrain &t)
{
    if (t.posEstValide(rect.x, rect.y + 1))
        rect.y++;
}
void Paddle::bas(const Terrain &t)
{
    if (t.posEstValide(rect.x, rect.y - 1))
        rect.y--;
}
