#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Rectangle.h"

enum class STATE
{
    UP,
    DOWN,
    HOVER
}

class Button
{
private:
    std::string text;
    Rectangle position_size;
    STATE state;

public:
    Button(const std::string &text, const Rectangle positionAndSize);
    const Rectangle &GetPositionAndSize() const;
    void setPositionAndSize(const Rectangle positionAndSize);
    void SetPosition(const Vec2D &NewPosition);
    void SetSize(const Vec2D &NewSize);
    
}

#endif