// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "../Vector2.h"

#include <cmath>

/// ===========
/// calcuration
/// ===========

float Vector2::Dot(const Vector2& v) const
{
    return this->x * v.x + this->y * v.y;
}

float Vector2::Cross(const Vector2& v) const
{
    return this->x * v.y - this->y * v.x;
}

float Vector2::Length() const
{
    return std::sqrtf(this->x * this->x + this->y * this->y);
}

float Vector2::LengthWithoutRoot() const
{
    return this->x * this->x + this->y * this->y;
}

Vector2 Vector2::Perpendicular() const
{
    return Vector2(-y, this->x);
}

Vector2 Vector2::Normalize() const
{
    float length = this->Length();
    if (length == 0) return {};
    return Vector2(
        this->x / length,
        this->y / length
    );
}

float Vector2::Projection(const Vector2& a) const
{
    Vector2 axis = a.Normalize();
    return (*this).Dot(axis);
}

void Vector2::Lerp(const Vector2& begin, const Vector2& end, float t)
{
    this->x = (1.0f - t) * begin.x + t * end.x;
    this->y = (1.0f - t) * begin.y + t * end.y;
    return;
}

float Vector2::Distance(const Vector2& destination) const
{
    return Vector2(destination - *this).Length();
}

float Vector2::Theta(const Vector2& origin) const
{
    Vector2 distance = *this - origin;
    return std::atan2(distance.y, distance.x);
}

Vector2 Vector2::Rotated(float theta) const
{
    Vector2 result = {};
    result.x = this->x * std::cosf(theta) - this->y * std::sinf(theta);
    result.y = this->x * std::sinf(theta) + this->y * std::cosf(theta);
    return result;
}

Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

/// =====
/// float
/// =====

Vector2 Vector2::operator*(float f) const
{
    Vector2 result{};
    result.x = this->x * f;
    result.y = this->y * f;
    return result;
}

Vector2 Vector2::operator/(float f) const
{
    Vector2 result{};
    result.x = this->x / f;
    result.y = this->y / f;
    return result;
}

Vector2& Vector2::operator*=(float f)
{
    this->x *= f;
    this->y *= f;
    return *this;
}

Vector2& Vector2::operator/=(float f)
{
    this->x /= f;
    this->y /= f;
    return *this;
}

/// =======
/// Vector2
/// =======

Vector2 Vector2::operator+(const Vector2& v) const
{
    Vector2 result{};
    result.x = this->x + v.x;
    result.y = this->y + v.y;
    return result;
}

Vector2 Vector2::operator-(const Vector2& v) const
{
    Vector2 result{};
    result.x = this->x - v.x;
    result.y = this->y - v.y;
    return result;
}

Vector2 Vector2::operator*(const Vector2& v) const
{
    Vector2 result{};
    result.x = this->x * v.x;
    result.y = this->y * v.y;
    return result;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
    this->x += v.x;
    this->y += v.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
    this->x -= v.x;
    this->y -= v.y;
    return *this;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
    this->x *= v.x;
    this->y *= v.y;
    return *this;
}

bool Vector2::operator==(const Vector2& v) const
{
    return this->x == v.x && this->y == v.y;
}

/// =========
/// overscope
/// =========

Vector2 operator*(const float f, const Vector2& v)
{
    return Vector2(v.x * f, v.y * f);
}

Vector2 operator/(const float f, const Vector2& v)
{
    return Vector2(v.x / f, v.y / f);
}
