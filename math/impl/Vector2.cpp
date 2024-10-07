// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "../Vector2.h"

Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

/// =====
/// float
/// =====

Vector2 Vector2::operator*(float _f)
{
    Vector2 result{};
    result.x = x * _f;
    result.y = y * _f;
    return result;
}

Vector2 Vector2::operator/(float _f)
{
    Vector2 result{};
    result.x = x / _f;
    result.y = y / _f;
    return result;
}

Vector2& Vector2::operator*=(float _f)
{
    x *= _f;
    y *= _f;
    return *this;
}

Vector2& Vector2::operator/=(float _f)
{
    x /= _f;
    y /= _f;
    return *this;
}

/// =======
/// Vector2
/// =======

Vector2 Vector2::operator+(const Vector2& _v)
{
    Vector2 result{};
    result.x = x + _v.x;
    result.y = y + _v.y;
    return result;
}

Vector2 Vector2::operator-(const Vector2& _v)
{
    Vector2 result{};
    result.x = x - _v.x;
    result.y = y - _v.y;
    return result;
}

Vector2 Vector2::operator*(const Vector2& _v)
{
    Vector2 result{};
    result.x = x * _v.x;
    result.y = y * _v.y;
    return result;
}

Vector2& Vector2::operator+=(const Vector2& _v)
{
    x += _v.x;
    y += _v.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& _v)
{
    x -= _v.x;
    y -= _v.y;
    return *this;
}

Vector2& Vector2::operator*=(const Vector2& _v)
{
    x *= _v.x;
    y *= _v.y;
    return *this;
}

/// =========
/// overscope
/// =========

Vector2 operator*(const float _f, const Vector2& _v)
{
    return Vector2(_v.x * _f, _v.y * _f);
}

Vector2 operator/(const float _f, const Vector2& _v)
{
    return Vector2(_v.x / _f, _v.y / _f);
}
