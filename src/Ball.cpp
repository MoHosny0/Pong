#include "Ball.h"

Ball::Ball(const Vec2D &InitialPosition, const float BallRadius)
{
    position = InitialPosition;
    radius = BallRadius;
    velocity(0, 0);
}
const Vec2D &Ball::GetPosition() const { return position; }
const Vec2D &Ball::GetVelocity() const { return velocity; }
const float &Ball::GetRadius() const { return radius; }
void Ball::SetPosition(const Vec2D &NewPosition)
{
    position = NewPosition;
}
void Ball::SetVelocity(const Vec2D &NewVelocity)
{
    velocity = NewVelocity;
}