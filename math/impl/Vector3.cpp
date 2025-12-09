#include "Vector3.h"
// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "../Vector3.h"
#include "../Matrix4x4.h"

#include <cassert>
#include <cmath>

/// ===========
/// calcuration
/// ===========

float Vector3::Dot(const Vector3& v) const
{
    return float(
        x * v.x +
        y * v.y +
        z * v.z
    );
}

Vector3 Vector3::Cross(const Vector3& v) const
{
    return Vector3(
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x
    );
}

float Vector3::Length() const
{
    return std::sqrtf(x * x + y * y + z * z);
}

float Vector3::LengthWithoutRoot() const
{
    return x * x + y * y + z * z;
}

Vector3 Vector3::Normalized() const
{
    float length = this->Length();
    if (length == 0.0f) return {};
    return Vector3(
        x / length,
        y / length,
        z / length
    );
}

void Vector3::Lerp(const Vector3& begin, const Vector3& end, float t)
{
    x = (1.0f - t) * begin.x + t * end.x;
    y = (1.0f - t) * begin.y + t * end.y;
    z = (1.0f - t) * begin.z + t * end.z;
    return;
}

void Vector3::Theta(float azimuth, float elevation, const Vector3& origin) const
{
    Vector3 distance = *this - origin;
    azimuth = std::atan2(distance.y, distance.x);
    elevation = std::atan2(distance.z, sqrtf(distance.x * distance.x + distance.y * distance.y));
    return;
}

float Vector3::Projection(const Vector3& a) const
{
    Vector3 axis = a.Normalized();
    return (*this).Dot(axis);
}

float Vector3::Distance(const Vector3& destination) const
{
    Vector3 distance = destination - *this;
    return distance.Length();
}

/// ==========
/// minus sign
/// ==========

Vector3 Vector3::operator-() const
{
    return Vector3(-x, -y, -z);
}

/// =======
/// Vector3
/// =======

Vector3& Vector3::operator+=(const Vector3& rv)
{
    x += rv.x;
    y += rv.y;
    z += rv.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rv)
{
    x -= rv.x;
    y -= rv.y;
    z -= rv.z;
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& rv)
{
    x *= rv.x;
    y *= rv.y;
    z *= rv.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    Vector3 result{};
    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z - v.z;
    return result;
}

Vector3 Vector3::operator*(const Vector3& v) const
{
    Vector3 result{};
    result.x = x * v.x;
    result.y = y * v.y;
    result.z = z * v.z;
    return result;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
    Vector3 result{};
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z + v.z;
    return result;
}

/// =====
/// float
/// =====

Vector3 Vector3::operator*(float f) const
{
    Vector3 result{};
    result.x = x * f;
    result.y = y * f;
    result.z = z * f;
    return result;
}

Vector3 Vector3::operator/(float f) const
{
    Vector3 result{};
    result.x = x / f;
    result.y = y / f;
    result.z = z / f;
    return result;
}

Vector3& Vector3::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Vector3& Vector3::operator/=(float f)
{
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

/// =======
/// Vector2
/// =======

Vector3& Vector3::operator+=(const Vector2& rv)
{
    x += rv.x;
    y += rv.y;
    return *this;
}

Vector3& Vector3::operator-=(const Vector2& rv)
{
    x -= rv.x;
    y -= rv.y;
    return *this;
}

Vector3& Vector3::operator*=(const Vector2& rv)
{
    x *= rv.x;
    y *= rv.y;
    return *this;
}

Vector3 Vector3::operator+(const Vector2& v) const
{
    Vector3 result{};
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z;
    return result;
}

Vector3 Vector3::operator-(const Vector2& v) const
{
    Vector3 result{};
    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z;
    return result;
}

Vector3 Vector3::operator*(const Vector2& v) const
{
    Vector3 result{};
    result.x = x * v.x;
    result.y = y * v.y;
    result.z = z;
    return result;
}

Vector3 operator*(const float f, const Vector3& v)
{
    return Vector3(v.x * f, v.y * f, v.z * f);
}

Vector3 operator/(const float f, const Vector3& v)
{
    return Vector3(v.x / f, v.y / f, v.z / f);
}