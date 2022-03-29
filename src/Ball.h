#include "Vec2D.h"
#ifndef BALL_H
#define BALL_H

class Ball
{
private:
    Vec2D position;
    Vec2D velocity;
    float radius;

public:
    Ball(const Vec2D &pos, const float radius);
    const Vec2D &GetPosition() const;
    const Vec2D &GetVelocity() const;
    const float &GetRadius() const;
    void SetPosition(const Vec2D &NewPosition);
    void SetVelocity(const Vec2D &NewVelocity);
};
#endif