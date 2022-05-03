#include "Paddle.h"
#include <iostream>

Paddle::Paddle() {}

const Rectangle &Paddle::getPosition() const { return rect; }

void Paddle::setPosition(const Vec2D NewPosition)
{
    rect.x = NewPosition.getX();
    rect.y = NewPosition.getY();
}
void Paddle::haut(const Terrain &t)
{

    if (t.posEstValide(rect.x, rect.y - 1))
        rect.y -= rect.speed ;

}
void Paddle::bas(const Terrain &t)
{

    if (t.posEstValide(rect.x, rect.y + rect.height))
        rect.y+= rect.speed ;
    else
        std::cout << "Invalid position" << std::endl;
}

void Paddle::setDimension(const int x, const int y)
{
    rect.width = x;
    rect.height = y;
}

void Paddle::setSpeed(const int  x){rect.speed = x;}