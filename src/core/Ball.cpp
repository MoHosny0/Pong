#include "Ball.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int FLOAT_MIN = -1;
const int FLOAT_MAX = 1;

using namespace std;

float getRandomFloat()
{
    float value = 0.0;
    while (value == 0.0)
    {
        value = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
    }
    return value;
}

Ball::Ball()
{
    float randOne = getRandomFloat();
    float randTwo = getRandomFloat();

    velocity = Vec2D(randOne, randTwo);
}

const Vec2D &Ball::getPosition() const { return position; }
const Vec2D &Ball::getVelocity() const { return velocity; }
const float &Ball::getRadius() const { return radius; }

void Ball::setPosition(const Vec2D &NewPosition) { position = NewPosition; }
void Ball::setVelocity(const Vec2D &NewVelocity) { velocity = NewVelocity; }
void Ball::setRadius(const float NewRadius) { radius = NewRadius; }

void Ball::bougeAuto()
{

    setPosition(position += getVelocity());
}
