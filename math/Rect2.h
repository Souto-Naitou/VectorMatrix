#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include <vector>

class Rect2
{
public:
    int x1;
    int y1;
    int x2;
    int y2;

    Rect2() : x1(), y1(), x2(), y2(), sizetemp_() {};
    ~Rect2() = default;

    inline Rect2(const Vector2& lt, const Vector2& rb)
    {
        x1 = static_cast<int>(lt.x);
        y1 = static_cast<int>(lt.y);
        x2 = static_cast<int>(rb.x);
        y2 = static_cast<int>(rb.y);
        sizetemp_ = 0;
        return;
    }

    Rect2(const Vector3&) = delete;

    Vector2 LeftTop() const     { return Vector2(x1, y1); }
    Vector2 RightTop() const    { return Vector2(x2, y1); }
    Vector2 RightBottom() const { return Vector2(x2, y2); }
    Vector2 LeftBottom() const  { return Vector2(x1, y2); }

    std::vector<Vector2> GetVertices();

    void MakeSquare(int size, bool centerMode = true);
    void MakeRectangle(int width, int height, bool centerMode = true);
    int GetSize() const { return sizetemp_; }

    Rect2 operator+(const Vector2& pos);

private:
    int sizetemp_;
};