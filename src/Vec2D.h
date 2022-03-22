#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
private:
    float x, y;

public:
    Vec2D() : x(0.0f), y(0.0f) {}           // default constructor
    Vec2D(float x, float y) : x(x), y(y) {} // constructor with params
    Vec2D operator+(Vec2D const &v);
    Vec2D &operator+=(Vec2D const &v);
    Vec2D operator*(float k);
    void setV(float x, float y);
    Vec2D getV() const;
};
#endif