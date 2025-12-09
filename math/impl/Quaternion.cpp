#include "Quaternion.h"
#include "Quaternion.h"

#include "../Vector3.h"

#include <cmath> // std::sqrt
#include <cassert>
#include <algorithm>

Quaternion Quaternion::Identity()
{
    return Quaternion({ 0.0f, 0.0f, 0.0f, 1.0f });
}


Quaternion Quaternion::Conjugate(const Quaternion& q)
{
    return Quaternion({ -q.x, -q.y, -q.z, q.w });
}

float Quaternion::Norm() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::Normalized() const
{
    return *this / Norm();
}


Quaternion Quaternion::Inversed() const
{
    return Conjugate(*this) / (x * x + y * y + z * z + w * w);
}

Quaternion Quaternion::RotateAxisAngleQuaternion(const Vector3& axis, float angle)
{
    float halfAngle = angle * 0.5f;
    float cosHalfAngle = std::cos(halfAngle);
    float sinHalfAngle = std::sin(halfAngle);

    Quaternion result = {};
    result.x = sinHalfAngle * axis.x;
    result.y = sinHalfAngle * axis.y;
    result.z = sinHalfAngle * axis.z;
    result.w = cosHalfAngle;

    return result;
}

Quaternion Quaternion::operator+(const Quaternion& rq) const
{
    return Quaternion({ x + rq.x, y + rq.y, z + rq.z, w + rq.w });
}

Quaternion Quaternion::operator-(const Quaternion& rq) const
{
    return Quaternion({ x - rq.x, y - rq.y, z - rq.z, w - rq.w });
}

Quaternion Quaternion::operator*(const Quaternion& rq) const
{
    Quaternion result = {};
    result.x = w * rq.x + x * rq.w + y * rq.z - z * rq.y;
    result.y = w * rq.y + y * rq.w + z * rq.x - x * rq.z;
    result.z = w * rq.z + z * rq.w + x * rq.y - y * rq.x;
    result.w = w * rq.w - x * rq.x - y * rq.y - z * rq.z;

    return result;
}

Quaternion Quaternion::operator/(float f) const
{
    Quaternion result = {};
    result.x = x / f;
    result.y = y / f;
    result.z = z / f;
    result.w = w / f;

    return result;
}

Quaternion Quaternion::operator-() const
{
    return Quaternion({ -x, -y, -z, -w });
}

Quaternion Quaternion::operator*(float f) const
{
    return Quaternion({ x * f, y * f, z * f, w * f });
}

Vector3 FMath::RotateVector(const Vector3& v, const Quaternion& q)
{
    Vector3 result = {};

    Quaternion quat = q * Quaternion({ v.x, v.y, v.z, 0.0f }) * Quaternion::Conjugate(q);

    result.x = quat.x;
    result.y = quat.y;
    result.z = quat.z;

    return result;
}

Quaternion Quaternion::Slerp(const Quaternion& begin, const Quaternion& end, float t)
{
    float dot = begin.x * end.x + begin.y * end.y + begin.z * end.z + begin.w * end.w;

    Quaternion beginTemp = begin;

    if (dot < 0.0f)
    {
        beginTemp = -begin;
        dot = -dot;
    }

    dot = std::clamp(dot, -1.0f, 1.0f);

    /// なす角を求める
    float theta = std::acos(dot);

    /// thetaとsinを使って補間係数scale0, scale1を求める
    float sinTheta = std::sin(theta);

    if (sinTheta < 1e-6f) // 0に近い場合は線形補間
    {
        return beginTemp * (1.0f - t) + end * t;
    }

    float scale0 = std::sin((1.0f - t) * theta) / sinTheta;
    float scale1 = std::sin(t * theta) / sinTheta;

    if (std::isnan(scale0) || std::isnan(scale1))
    {
        assert(0);
    }

    return beginTemp * scale0 + end * scale1;
}
