// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "Vector2.h"

#include <cmath>

/// ===========
/// calcuration
/// ===========

float Vector2::Dot(const Vector2& _v) const
{
    return x * _v.x + y * _v.y;
}

float Vector2::Length() const
{
    return std::sqrtf(x * x + y * y);
}

float Vector2::LengthWithoutRoot() const
{
    return x * x + y * y;
}

Vector2 Vector2::Normalize() const
{
    float length = this->Length();
    return Vector2(
        x / length,
        y / length
    );
}

void Vector2::Lerp(const Vector2& _begin, const Vector2& _end, float _t)
{
    x = (1.0f - _t) * _begin.x + _t * _end.x;
    y = (1.0f - _t) * _begin.y + _t * _end.y;
    return;
}

Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

/// =====
/// float
/// =====

Vector2 Vector2::operator*(float _f) const
{
    Vector2 result{};
    result.x = x * _f;
    result.y = y * _f;
    return result;
}

Vector2 Vector2::operator/(float _f) const
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

Vector2 Vector2::operator+(const Vector2& _v) const
{
    Vector2 result{};
    result.x = x + _v.x;
    result.y = y + _v.y;
    return result;
}

Vector2 Vector2::operator-(const Vector2& _v) const
{
    Vector2 result{};
    result.x = x - _v.x;
    result.y = y - _v.y;
    return result;
}

Vector2 Vector2::operator*(const Vector2& _v) const
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
