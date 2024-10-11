// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once

/// <summary>
/// 2th Dimension Vector
/// </summary>
class Vector2 final{
public:
    float x;
    float y;

    inline Vector2() : x(), y() {};

    inline Vector2(const float& _x, const float& _y)
    {
        x = _x;
        y = _y;
        return;
    }

    inline Vector2(const float& _x)
    {
        x = _x;
        y = 0.0f;
    }

    /// ===========
    /// calcuration
    /// ===========

    float   Dot(const Vector2& _v)  const;
    float   Length()                const;
    float   LengthWithoutRoot()     const;
    Vector2 Normalize()             const;
    void    Lerp(const Vector2& _begin, const Vector2& _end, float _t);
    Vector2 Distance(const Vector2& _destination) const;
    float   Theta(const Vector2& _origin = { 0.0f, 0.0f }) const;
    Vector2 Rotated(float _theta) const;

    /// ==========
    /// Minus sign
    /// ==========
    
    Vector2 operator-() const;

    /// =====
    /// float
    /// =====

    Vector2 operator+(float) = delete;
    Vector2 operator-(float) = delete;
    Vector2 operator*(float _f) const;
    Vector2 operator/(float _f) const;
    Vector2& operator+=(float _f) = delete;
    Vector2& operator-=(float _f) = delete;
    Vector2& operator*=(float _f);
    Vector2& operator/=(float _f);

    /// =======
    /// Vector2
    /// =======

    Vector2 operator+(const Vector2& _v) const;
    Vector2 operator-(const Vector2& _v) const;
    Vector2 operator*(const Vector2& _v) const;

    Vector2& operator+=(const Vector2& _v);
    Vector2& operator-=(const Vector2& _v);
    Vector2& operator*=(const Vector2& _v);
};

Vector2 operator*(const float _f, const Vector2& _v);
Vector2 operator/(const float _f, const Vector2& _v);