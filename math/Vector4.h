// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once

#include "Vector3.h"
#include "Vector2.h"


/// <summary>
/// 4th Dimension Vector
/// </summary>
class Vector4 final {
public:
    float x;
    float y;
    float z;
    float w;

    Vector4() : x(), y(), z(), w() {};

    constexpr Vector4(const float& x, const float& y, const float& z, const float& w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        return;
    }

    constexpr Vector4(const float& x, const float& y, const float& z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = 0.0f;
        return;
    }

    constexpr Vector4(const float& x, const float& y)
    {
        this->x = x;
        this->y = y;
        this->z = 0.0f;
        this->w = 0.0f;
        return;
    }

    constexpr explicit Vector4(const float& x) 
    {
        this->x = x;
        this->y = 0.0f;
        this->z = 0.0f;
        this->w = 0.0f;
        return;
    }

    Vector4(const Vector3& vec3)
    {
        this->x = vec3.x;
        this->y = vec3.y;
        this->z = vec3.z;
        this->w = 0.0f;
        return;
    }

    Vector4(const Vector2& vec2)
    {
        this->x = vec2.x;
        this->y = vec2.y;
        this->z = 0.0f;
        this->w = 0.0f;
        return;
    }

    Vector4(const Vector3& vec3, const float& w)
    {
        this->x = vec3.x;
        this->y = vec3.y;
        this->z = vec3.z;
        this->w = w;
        return;
    }

    Vector3 xyz() const { return Vector3(x, y, z); }

    Vector2 xy() const { return Vector2(x, y); }


    void    Lerp(const Vector4& begin, const Vector4& end, float t);


    /// マイナス符号
    Vector4 operator-() const;

    /// =======
    /// Vector4
    /// =======

    Vector4& operator+=(const Vector4& rv);
    Vector4& operator-=(const Vector4& rv);
    Vector4& operator*=(const Vector4& rv);

    Vector4 operator+(const Vector4& v);
    Vector4 operator-(const Vector4& v);
    Vector4 operator*(const Vector4& v);

    /// =====
    /// float
    /// =====

    Vector4 operator+(float) = delete;
    Vector4 operator-(float) = delete;
    Vector4 operator*(float f);
    Vector4 operator/(float f);
    Vector4& operator+=(float) = delete;
    Vector4& operator-=(float) = delete;
    Vector4& operator*=(float f);
    Vector4& operator/=(float f);

    /// =======
    /// Vector2
    /// =======

    Vector4& operator+=(const Vector2& rv);
    Vector4& operator-=(const Vector2& rv);
    Vector4& operator*=(const Vector2& rv);

    Vector4 operator+(const Vector2& v);
    Vector4 operator-(const Vector2& v);
    Vector4 operator*(const Vector2& v);

    /// =======
    /// Vector3
    /// =======

    Vector4& operator+=(const Vector3& rv);
    Vector4& operator-=(const Vector3& rv);
    Vector4& operator*=(const Vector3& rv);

    Vector4 operator+(const Vector3& v);
    Vector4 operator-(const Vector3& v);
    Vector4 operator*(const Vector3& v);

};