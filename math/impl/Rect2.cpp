#include "Rect2.h"

void Rect2::MakeSquare(int _size, bool _centerMode)
{
    sizetemp_ = _size;
    if (_centerMode)
    {
        x1 = y1 = -_size / 2;
        x2 = y2 = _size / 2;
    }
    else
    {
        x2 = _size;
        y2 = _size;
    }
    return;
}

void Rect2::MakeRectangle(int _width, int _height, bool _centerMode)
{
    if (_centerMode)
    {
        x1 = -_width / 2;
        y1 = -_height / 2;
        x2 = _width / 2;
        y2 = _height / 2;
    }
    else
    {
        x2 = _width;
        y2 = _height;
    }
    return;
}

Rect2 Rect2::operator+(const Vector2& _pos)
{
    Rect2 result;
    result.x1 = x1 + static_cast<int>(_pos.x);
    result.y1 = y1 + static_cast<int>(_pos.y);
    result.x2 = x2 + static_cast<int>(_pos.x);
    result.y2 = y2 + static_cast<int>(_pos.y);
    return result;
}
