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

    Vector2() : x(), y() {};

    Vector2(const unsigned int x, const unsigned int& y)
    {
        this->x = static_cast<float>(x);
        this->y = static_cast<float>(y);
        return;
    }

    Vector2(const int& x, const int& y)
    {
        this->x = static_cast<float>(x);
        this->y = static_cast<float>(y);
        return;
    }

    Vector2(const float& x, const float& y)
    {
        this->x = x;
        this->y = y;
        return;
    }

    Vector2(const float& x)
    {
        this->x = x;
        this->y = 0.0f;
        return;
    }

    /// ===========
    /// calcuration
    /// ===========

    /// <summary>
    /// 内積
    /// </summary>
    /// <param name="v">ベクトル</param>
    /// <returns>内積</returns>
    float       Dot(const Vector2& v)                           const;

    /// <summary>
    /// 外積
    /// </summary>
    /// <param name="v">ベクトル</param>
    /// <returns>外積</returns>
    float       Cross(const Vector2& v)                         const;

    /// <summary>
    /// 原点からの距離を求める
    /// </summary>
    /// <returns>距離</returns>
    float       Length()                                        const;

    /// <summary>
    /// Length関数の平方根なし
    /// </summary>
    /// <returns></returns>
    float       LengthWithoutRoot()                             const;

    /// <summary>
    /// 垂直ベクトルを返す
    /// </summary>
    /// <returns></returns>
    Vector2     Perpendicular()                                 const;

    /// <summary>
    /// 正規化済みの値を返す
    /// </summary>
    /// <returns></returns>
    Vector2     Normalize()                                     const;

    /// <summary>
    /// thisから引数のベクトルまでの距離
    /// </summary>
    /// <param name="destination">行き先</param>
    /// <returns>距離</returns>
    float       Distance(const Vector2& destination)            const;
    float       Theta(const Vector2& origin = { 0.0f, 0.0f })   const;
    Vector2     Rotated(float theta)                            const;

    /// <summary>
    /// 軸aに投影した値を返す
    /// </summary>
    /// <param name="a">軸</param>
    /// <returns></returns>
    float       Projection(const Vector2& a)                    const;

    /// <summary>
    /// 線形補間
    /// </summary>
    /// <param name="begin">初期値</param>
    /// <param name="end">終了値</param>
    /// <param name="t">0.0~1.0</param>
    void        Lerp(const Vector2& begin, const Vector2& end, float t);

    /// ==========
    /// Minus sign
    /// ==========

    Vector2     operator-() const;

    /// =====
    /// float
    /// =====

    Vector2     operator+(float) = delete;
    Vector2     operator-(float) = delete;
    Vector2     operator*(float f) const;
    Vector2     operator/(float f) const;
    Vector2&    operator+=(float f) = delete;
    Vector2&    operator-=(float f) = delete;
    Vector2&    operator*=(float f);
    Vector2&    operator/=(float f);

    /// =======
    /// Vector2
    /// =======

    Vector2     operator+(const Vector2& v) const;
    Vector2     operator-(const Vector2& v) const;
    Vector2     operator*(const Vector2& v) const;

    Vector2&    operator+=(const Vector2& v);
    Vector2&    operator-=(const Vector2& v);
    Vector2&    operator*=(const Vector2& v);

    bool        operator==(const Vector2& v) const;
};

Vector2 operator*(const float f, const Vector2& v);
Vector2 operator/(const float f, const Vector2& v);