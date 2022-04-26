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
    // std::cout << "Paddle Vertical at " << rect.y << std::endl;
    if (t.posEstValide(rect.x, rect.y - 1))
        rect.y--;
    else
        std::cout << "Invalid position" << std::endl;
}
void Paddle::bas(const Terrain &t)
{
    // std::cout << "Paddle Vertical at " << rect.y << std::endl;
    if (t.posEstValide(rect.x, rect.y + 1))
        rect.y++;
    else
        std::cout << "Invalid position" << std::endl;
}

void Paddle::setDimension(const int x, const int y)
{
    rect.width = x;
    rect.height = y;
    // std::cout << "Setting Dimensions to " << x << "x" << y << std::endl;
    // std::cout << "Dimensions set to " << rect.width << "x" << rect.height << std::endl;
}
