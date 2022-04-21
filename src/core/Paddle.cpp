#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
    rect.x = 2;
    rect.y = 13;
}

Paddle::Paddle(const Rectangle StartingPosition)
{
    rect = StartingPosition;
}
const Rectangle &Paddle::getPosition() const
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
    if (t.posEstValide(rect.x, rect.y - 1))
        rect.y--;
    else
        std::cout << "Invalid position" << std::endl;
}
void Paddle::bas(const Terrain &t)
{
    if (t.posEstValide(rect.x, rect.y + 2))
        rect.y++;
    else
        std::cout << "Invalid position" << std::endl;
}
