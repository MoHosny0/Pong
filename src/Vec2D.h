#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
private:
    float x, y;

public:
    Vec2D() : x(0.0f), y(0.0f) {}
    Vec2D(float x, float y) : x(x), y(y) {}
    Vec2D operator+(Vec2D const &v);
    Vec2D &operator+=(Vec2D const &v);
    Vec2D operator*(float k);
};
#endif