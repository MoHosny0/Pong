#include "Paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(const Rectangle StartingPosition)
{
    rect = StartingPosition;
}
const Rectangle &Paddle::getPositionSize() const
{
    return rect;
}
void Paddle::setPositionSize(const Rectangle NewPositionSize)
{
    rect = NewPositionSize;
}
void Paddle::setPosition(const Vec2D NewPosition)
{
    rect.x = NewPosition.getX();
    rect.y = NewPosition.getY();
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
