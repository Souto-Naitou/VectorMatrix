// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once

#include "Vector2.h"

class Matrix4x4;

/// <summary>
/// 3th Dimension Vector
/// </summary>
class Vector3 final {
public:
    float x;
    float y;
    float z;

    Vector3() : x(), y(), z() {};

    Vector3(const float& x, const float& y, const float& z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        return;
    }

    Vector3(const float& x, const float& y)
    {
        this->x = x;
        this->y = y;
        this->z = 0.0f;
        return;
    }

    Vector3(const float& x)
    {
        this->x = x;
        this->y = 0.0f;
        this->z = 0.0f;
        return;
    }

    Vector3(const Vector2& vec2, float f)
    {
        this->x = vec2.x;
        this->y = vec2.y;
        this->z = f;
        return;
    }

    Vector3(const Vector2& vec2)
    {
        this->x = vec2.x;
        this->y = vec2.y;
        this->z = 0.0f;
        return;
    }

    Vector2 xy() const { return Vector2(x, y); }
    Vector2 xz() const { return Vector2(x, z); }
    Vector2 yz() const { return Vector2(y, z); }

    /// ===========
    /// calcuration
    /// ===========

    float   Dot(const Vector3& v)                   const;
    Vector3 Cross(const Vector3& v)                 const;
    float   Length()                                const;
    float   LengthWithoutRoot()                     const;
    Vector3 Normalized()                            const;
    float   Distance(const Vector3& destination)    const;
    float   Projection(const Vector3& a)            const;
    void    Lerp(const Vector3& begin, const Vector3& end, float t);
    void    Theta(float azimuth, float elevation, const Vector3& origin = { 0.0f, 0.0f }) const;

    /// ==========
    /// minus sign
    /// ==========

    Vector3 operator-() const;

    /// =======
    /// Vector3
    /// =======

    Vector3& operator+=(const Vector3& rv);
    Vector3& operator-=(const Vector3& rv);
    Vector3& operator*=(const Vector3& rv);

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;

    /// =====
    /// float
    /// =====

    Vector3 operator+(float) = delete;
    Vector3 operator-(float) = delete;
    Vector3 operator*(float f) const;
    Vector3 operator/(float f) const;
    Vector3& operator+=(float) = delete;
    Vector3& operator-=(float) = delete;
    Vector3& operator*=(float f);
    Vector3& operator/=(float f);

    /// =======
    /// Vector2
    /// =======

    Vector3& operator+=(const Vector2& rv);
    Vector3& operator-=(const Vector2& rv);
    Vector3& operator*=(const Vector2& rv);

    Vector3 operator+(const Vector2& v) const;
    Vector3 operator-(const Vector2& v) const;
    Vector3 operator*(const Vector2& v) const;
};

Vector3 operator*(const float f, const Vector3& v);
Vector3 operator/(const float f, const Vector3& v);

namespace FMath
{
    Vector3 Add(const Vector3& v1, const Vector3& v2);
    Vector3 Subtract(const Vector3& v1, const Vector3& v2);
    Vector3 Multiply(float scalar, const Vector3& v);
    float   Dot(const Vector3& v1, const Vector3& v2);
    float   Length(const Vector3& v);
    Vector3 Normalize(const Vector3& v);
    Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
}