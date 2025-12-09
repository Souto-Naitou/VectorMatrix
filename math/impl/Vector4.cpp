// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "../Vector4.h"

Vector4 Vector4::operator-() const
{
    return Vector4(-x, -y, -z, -w);
}

void Vector4::Lerp(const Vector4& begin, const Vector4& end, float t)
{
    x = begin.x + (end.x - begin.x) * t;
    y = begin.y + (end.y - begin.y) * t;
    z = begin.z + (end.z - begin.z) * t;
    w = begin.w + (end.w - begin.w) * t;
    return;
}

/// =======
/// Vector4
/// =======

Vector4& Vector4::operator+=(const Vector4& rv)
{
    x += rv.x;
    y += rv.y;
    z += rv.z;
    w += rv.w;
    return *this;
}

Vector4& Vector4::operator-=(const Vector4& rv)
{
    x -= rv.x;
    y -= rv.y;
    z -= rv.z;
    w -= rv.w;
    return *this;
}

Vector4& Vector4::operator*=(const Vector4& rv)
{
    x *= rv.x;
    y *= rv.y;
    z *= rv.z;
    w *= rv.w;
    return *this;
}

Vector4 Vector4::operator+(const Vector4& v)
{
    Vector4 result{};
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z + v.z;
    result.w = w + v.w;
    return result;
}


Vector4 Vector4::operator-(const Vector4& v)
{
    Vector4 result{};
    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z - v.z;
    result.w = w - v.w;
    return result;
}

Vector4 Vector4::operator*(const Vector4& v)
{
    Vector4 result{};
    result.x = x * v.x;
    result.y = y * v.y;
    result.z = z * v.z;
    result.w = w * v.w;
    return result;
}

/// =====
/// float
/// =====


Vector4 Vector4::operator*(float f)
{
    Vector4 result{};
    result.x = x * f;
    result.y = y * f;
    result.z = z * f;
    result.w = w * f;
    return result;
}

Vector4 Vector4::operator/(float f)
{
    Vector4 result{};
    result.x = x / f;
    result.y = y / f;
    result.z = z / f;
    result.w = w / f;
    return result;
}

Vector4& Vector4::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
    w += f;
    return *this;
}

Vector4& Vector4::operator/=(float f)
{
    x /= f;
    y /= f;
    z /= f;
    w /= f;
    return *this;
}

/// =======
/// Vector2
/// =======

Vector4& Vector4::operator+=(const Vector2& rv)
{
    x += rv.x;
    y += rv.y;
    return *this;
}

Vector4& Vector4::operator-=(const Vector2& rv)
{
    x -= rv.x;
    y -= rv.y;
    return *this;
}

Vector4& Vector4::operator*=(const Vector2& rv)
{
    x *= rv.x;
    y *= rv.y;
    return *this;
}

Vector4 Vector4::operator+(const Vector2& v)
{
    Vector4 result{};
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z;
    result.w = w;
    return result;
}

Vector4 Vector4::operator-(const Vector2& v)
{
    Vector4 result{};
    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z;
    result.w = w;
    return result;
}

Vector4 Vector4::operator*(const Vector2& v)
{
    Vector4 result{};
    result.x = x * v.x;
    result.y = y * v.y;
    result.z = z;
    result.w = w;
    return result;
}

/// =======
/// Vector3
/// =======

Vector4& Vector4::operator+=(const Vector3& rv)
{
    x += rv.x;
    y += rv.y;
    z += rv.z;
    return *this;
}

Vector4& Vector4::operator-=(const Vector3& rv)
{
    x -= rv.x;
    y -= rv.y;
    z -= rv.z;
    return *this;
}

Vector4& Vector4::operator*=(const Vector3& rv)
{
    x *= rv.x;
    y *= rv.y;
    z *= rv.z;
    return *this;
}

Vector4 Vector4::operator+(const Vector3& v)
{
    Vector4 result{};
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z + v.z;
    result.w = w;
    return result;
}

Vector4 Vector4::operator-(const Vector3& v)
{
    Vector4 result{};
    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z - v.z;
    result.w = w;
    return result;
}

Vector4 Vector4::operator*(const Vector3& v)
{
    Vector4 result{};
    result.x = x * v.x;
    result.y = y * v.y;
    result.z = z * v.z;
    result.w = w;
    return result;
}

/// =========
/// overscope
/// =========

Vector4 operator*(const float f, const Vector4& v)
{
    return Vector4(v.x * f, v.y * f, v.z * f, v.w * f);
}

Vector4 operator/(const float f, const Vector4& v)
{
    return Vector4(v.x / f, v.y / f, v.z / f, v.w / f);
}
