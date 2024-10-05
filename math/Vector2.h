// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once

/// <summary>
/// 2次元ベクトル
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

    /// マイナス符号
    Vector2 operator-() const;

    /// =====
    /// float
    /// =====

    Vector2 operator+(float) = delete;
    Vector2 operator-(float) = delete;
    Vector2 operator*(float _f);
    Vector2 operator/(float _f);
    Vector2& operator+=(float _f) = delete;
    Vector2& operator-=(float _f) = delete;
    Vector2& operator*=(float _f);
    Vector2& operator/=(float _f);

    /// =======
    /// Vector2
    /// =======

    Vector2 operator+(const Vector2& _v);
    Vector2 operator-(const Vector2& _v);
    Vector2 operator*(const Vector2& _v);

    Vector2& operator+=(const Vector2& _v);
    Vector2& operator-=(const Vector2& _v);
    Vector2& operator*=(const Vector2& _v);
};

Vector2 operator*(const float _f, const Vector2& _v);
Vector2 operator/(const float _f, const Vector2& _v);