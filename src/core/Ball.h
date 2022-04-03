#include "Vec2D.h"
#include "Terrain.h"
#ifndef BALL_H
#define BALL_H

class Ball
{
private:
    Vec2D position;
    Vec2D velocity;
    float radius;

public:
    Ball();
    Ball(const Vec2D &InitialPosition, const float BallRadius);
    const Vec2D &getPosition() const;
    const Vec2D &getVelocity() const;
    const float &getRadius() const;
    void setPosition(const Vec2D &NewPosition);
    void setVelocity(const Vec2D &NewVelocity);
    void setRadius(const float NewRadius);

    void bougeAuto(const Terrain &t);
};
#endif