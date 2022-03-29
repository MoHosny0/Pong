#include "Ball.h"

Ball::Ball() { 
    
}

Ball::Ball(const Vec2D &InitialPosition, const float BallRadius)
{
    position = InitialPosition;
    radius = BallRadius;
    velocity = Vec2D(0.0f, 0.0f);
}
const Vec2D &Ball::getPosition() const { return position; }
const Vec2D &Ball::getVelocity() const { return velocity; }
const float &Ball::getRadius() const { return radius; }
void Ball::setPosition(const Vec2D &NewPosition)
{
    position = NewPosition;
}
void Ball::setVelocity(const Vec2D &NewVelocity)
{
    velocity = NewVelocity;
}