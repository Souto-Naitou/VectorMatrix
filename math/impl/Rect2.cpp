// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "Rect2.h"

std::vector<Vector2> Rect2::GetVertices()
{
    std::vector<Vector2> result = {};
    result.push_back(LeftTop());
    result.push_back(RightTop());
    result.push_back(RightBottom());
    result.push_back(LeftBottom());

    return result;
}

void Rect2::MakeSquare(int size, bool centerMode)
{
    sizetemp_ = size;
    if (centerMode)
    {
        x1 = y1 = -size / 2;
        x2 = y2 = size / 2;
    }
    else
    {
        x2 = size;
        y2 = size;
    }
    return;
}

void Rect2::MakeRectangle(int width, int height, bool centerMode)
{
    if (centerMode)
    {
        x1 = -width / 2;
        y1 = -height / 2;
        x2 = width / 2;
        y2 = height / 2;
    }
    else
    {
        x2 = width;
        y2 = height;
    }
    return;
}

Rect2 Rect2::operator+(const Vector2& pos)
{
    Rect2 result;
    result.x1 = x1 + static_cast<int>(pos.x);
    result.y1 = y1 + static_cast<int>(pos.y);
    result.x2 = x2 + static_cast<int>(pos.x);
    result.y2 = y2 + static_cast<int>(pos.y);
    result.sizetemp_ = sizetemp_;
    return result;
}
