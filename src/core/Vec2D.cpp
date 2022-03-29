#include "Vec2D.h"
#include <iostream>

Vec2D Vec2D::operator+(Vec2D const &v)
{
    return Vec2D(x + v.x, y + v.y);
}

Vec2D &Vec2D::operator+=(Vec2D const &v)
{
    x += v.x;
    y += v.y;

    return *this;
}

Vec2D Vec2D::operator*(float k)
{
    return Vec2D(x * k, y * k);
}

float Vec2D::getX() const { return x; }
float Vec2D::getY() const { return y; }