// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once

#include <Vector2.h>

/// <summary>
/// 3次元ベクトル
/// </summary>
class Vector3 final {
public:
    float x;
    float y;
    float z;

    inline Vector3() : x(), y(), z() {};

    inline Vector3(const float& _x, const float& _y, const float& _z)
    {
        x = _x;
        y = _y;
        z = _z;
        return;
    }

    inline Vector3(const float& _x, const float& _y)
    {
        x = _x;
        y = _y;
        z = 0.0f;
        return;
    }

    inline Vector3(const float& _x)
    {
        x = _x;
        y = 0.0f;
        z = 0.0f;
        return;
    }

    inline Vector3(const Vector2& _vec2)
    {
        x = _vec2.x;
        y = _vec2.y;
        z = 0.0f;
        return;
    }

    /// マイナス符号
    Vector3 operator-() const;

    /// =======
    /// Vector3
    /// =======

    Vector3& operator+=(const Vector3& _rv);
    Vector3& operator-=(const Vector3& _rv);
    Vector3& operator*=(const Vector3& _rv);

    Vector3 operator+(const Vector3& _v);
    Vector3 operator-(const Vector3& _v);
    Vector3 operator*(const Vector3& _v);

    /// =====
    /// float
    /// =====

    Vector3 operator+(float) = delete;
    Vector3 operator-(float) = delete;
    Vector3 operator*(float _f);
    Vector3 operator/(float _f);
    Vector3& operator+=(float) = delete;
    Vector3& operator-=(float) = delete;
    Vector3& operator*=(float _f);
    Vector3& operator/=(float _f);

    /// =======
    /// Vector2
    /// =======

    Vector3& operator+=(const Vector2& _rv);
    Vector3& operator-=(const Vector2& _rv);
    Vector3& operator*=(const Vector2& _rv);

    Vector3 operator+(const Vector2& _v);
    Vector3 operator-(const Vector2& _v);
    Vector3 operator*(const Vector2& _v);
};
    Vector3 operator*(const float _f, const Vector3& _v);
    Vector3 operator/(const float _f, const Vector3& _v);