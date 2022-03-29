#include "Paddle.h"

Paddle::Paddle(const Rectangle startingPosition)
{
    rect = startingPosition;
}
const Rectangle &Paddle::GetPositionSize() const
{
    return rect;
}
Paddle::SetPositionSize(const Rectangle newPositionSize)
{
    rect = newPositionSize;
}
Paddle::setPosition(const Vec2D newPosition)
{
    rect.x = newPosition.x;
    rect.y = newPosition.y;
}
Paddle::haut(const Terrain & t) {
    if (t.estPositionPersoValide(x, y)) y++;
}