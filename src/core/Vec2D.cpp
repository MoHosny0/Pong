#include "Vec2D.h"
#include <iostream>

// Vec2D Vec2D::operator+(Vec2D const &V)
// {
//     return Vec2D(x + V.x, y + V.y);
// }

Vec2D &Vec2D::operator+=(Vec2D const &V)
{
    x += V.x;
    y += V.y;

    return *this;
}

// Vec2D Vec2D::operator*(float k)
// {
//     return Vec2D(x * k, y * k);
// }

float Vec2D::getX() const { return x; }
float Vec2D::getY() const { return y; }

// void Vec2D::setX(const float x_)
// {
//     x = x_;
// }
// void Vec2D::setY(const float y_)
// {
//     y = y_;
// }