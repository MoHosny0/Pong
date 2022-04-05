#include "Ball.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Ball::Ball()
{
    srand (static_cast <unsigned> (time(0)));
    
    float r1;
    float r2;

    do
    {
        r1 = ((rand()) / ((RAND_MAX/2)) - 1 );
    } while (r1 == 0);
    
    do
    {
        r2 = ((rand()) / ((RAND_MAX/2)) - 1 );
    } while (r2 == 0);

    // float r1 = ((rand()) / ((RAND_MAX/2)) - 1 );
    // float r2 = ((rand()) / ((RAND_MAX/2)) - 1 );

    /*while(r1 == 0)
    {
        float r1 = ((rand()) / ((RAND_MAX/2)) - 1 );
    }

    while(r2 == 0.0f)
    {
        float r2 = ((rand()) / ((RAND_MAX/2)) - 1 );
    }*/
    
    position = Vec2D(40, 15);
    velocity = Vec2D(r1, r2);
}

Ball::Ball(const Vec2D &InitialPosition, const float BallRadius)
{
    position = InitialPosition;
    radius = BallRadius;
    velocity = Vec2D(1.0f, 1.0f);
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
void Ball::setRadius(const float NewRadius)
{
    radius = NewRadius;
}

void Ball::bougeAuto(/*const Terrain &t*/)
{
    setPosition( position += getVelocity());
    
}
