// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "Vector3.h"

Vector3& Vector3::operator+=(const Vector3& _rv)
{
    x += _rv.x;
    y += _rv.y;
    z += _rv.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& _rv)
{
    x -= _rv.x;
    y -= _rv.y;
    z -= _rv.z;
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& _rv)
{
    x *= _rv.x;
    y *= _rv.y;
    z *= _rv.z;
    return *this;
}

Vector3& Vector3::operator+=(const Vector2& _rv)
{
    x += _rv.x;
    y += _rv.y;
    return *this;
}

Vector3& Vector3::operator-=(const Vector2& _rv)
{
    x -= _rv.x;
    y -= _rv.y;
    return *this;
}

Vector3& Vector3::operator*=(const Vector2& _rv)
{
    x *= _rv.x;
    y *= _rv.y;
    return *this;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator-(const Vector3& _v)
{
    Vector3 result{};
    result.x = x - _v.x;
    result.y = y - _v.y;
    result.z = z - _v.z;
    return result;
}

Vector3 Vector3::operator*(const Vector3& _v)
{
    Vector3 result{};
    result.x = x * _v.x;
    result.y = y * _v.y;
    result.z = z * _v.z;
    return result;
}


Vector3 Vector3::operator+(const Vector3& _v)
{
    Vector3 result{};
    result.x = x + _v.x;
    result.y = y + _v.y;
    result.z = z + _v.z;
    return result;
}

Vector3 Vector3::operator*(float _f)
{
    Vector3 result{};
    result.x = x * _f;
    result.y = y * _f;
    result.z = z * _f;
    return result;
}

Vector3 Vector3::operator/(float _f)
{
    Vector3 result{};
    result.x = x / _f;
    result.y = y / _f;
    result.z = z / _f;
    return result;
}

Vector3& Vector3::operator*=(float _f)
{
    x *= _f;
    y *= _f;
    z *= _f;
    return *this;
}

Vector3& Vector3::operator/=(float _f)
{
    x /= _f;
    y /= _f;
    z /= _f;
    return *this;
}

Vector3 Vector3::operator+(const Vector2& _v)
{
    Vector3 result{};
    result.x = x + _v.x;
    result.y = y + _v.y;
    result.z = z;
    return result;
}

Vector3 Vector3::operator-(const Vector2& _v)
{
    Vector3 result{};
    result.x = x - _v.x;
    result.y = y - _v.y;
    result.z = z;
    return result;
}

Vector3 Vector3::operator*(const Vector2& _v)
{
    Vector3 result{};
    result.x = x * _v.x;
    result.y = y * _v.y;
    result.z = z;
    return result;
}

Vector3 operator*(const float _f, const Vector3& _v)
{
    return Vector3(_v.x * _f, _v.y * _f, _v.z * _f);
}

Vector3 operator/(const float _f, const Vector3& _v)
{
    return Vector3(_v.x / _f, _v.y / _f, _v.z / _f);
}
