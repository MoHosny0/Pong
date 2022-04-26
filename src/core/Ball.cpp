#include "Ball.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Ball::Ball()
{
    srand(static_cast<unsigned>(time(0)));

    float r1; // change name
    float r2; // change name

    int FLOAT_MIN = -1;
    int FLOAT_MAX = 1;

    do
    {
        r1 = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
        // r1 = ((rand()) / ((RAND_MAX / 3)) - 1);
    } while (r1 == 0);

    do
    {   
        r2 = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX/(FLOAT_MAX - FLOAT_MIN)));
        // r2 = ((rand()) / ((RAND_MAX / 3)) - 1);
    } while (r2 == 0);

    velocity = Vec2D(r1, r2);
    cout << "velocity: " << velocity.getX() << "," << velocity.getY() << endl; // pourquoi ca s'affiche 2 fois dans le terminal??
}

const Vec2D &Ball::getPosition() const { return position; }
const Vec2D &Ball::getVelocity() const { return velocity; }
const float &Ball::getRadius() const { return radius; }

void Ball::setPosition(const Vec2D &NewPosition) { position = NewPosition; }
void Ball::setVelocity(const Vec2D &NewVelocity) { velocity = NewVelocity; }
void Ball::setRadius(const float NewRadius) { radius = NewRadius; }

void Ball::bougeAuto() { setPosition(position += getVelocity()); }
