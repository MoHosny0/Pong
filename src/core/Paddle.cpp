#include "Paddle.h"

Rectangle::Paddle(const Rectangle startingPosition)
{
    rect = startingPosition;
}
const Rectangle &Rectangle::GetPositionSize() const
{
    return rect;
}
Rectangle::SetPositionSize(const Rectangle newPositionSize)
{
    rect = newPositionSize;
}
Rectangle::setPosition(const Vec2D newPosition)
{
    rect.x = newPosition.x;
    rect.y = newPosition.y;
}