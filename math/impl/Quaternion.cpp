#include "Quaternion.h"

#include "../Vector3.h"

#include <cmath> // std::sqrt

Quaternion Quaternion::Identity()
{
    return Quaternion({ 0.0f, 0.0f, 0.0f, 1.0f });
}


Quaternion Quaternion::Conjugate(const Quaternion& _q)
{
    return Quaternion({ -_q.x, -_q.y, -_q.z, _q.w });
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

Quaternion Quaternion::RotateAxisAngleQuaternion(const Vector3& _axis, float _angle)
{
    float halfAngle = _angle * 0.5f;
    float cosHalfAngle = std::cos(halfAngle);
    float sinHalfAngle = std::sin(halfAngle);

    Quaternion result = {};
    result.x = sinHalfAngle * _axis.x;
    result.y = sinHalfAngle * _axis.y;
    result.z = sinHalfAngle * _axis.z;
    result.w = cosHalfAngle;

    return result;
}

Quaternion Quaternion::operator*(const Quaternion& _rq) const
{
    Quaternion result = {};
    result.x = w * _rq.x + x * _rq.w + y * _rq.z - z * _rq.y;
    result.y = w * _rq.y + y * _rq.w + z * _rq.x - x * _rq.z;
    result.z = w * _rq.z + z * _rq.w + x * _rq.y - y * _rq.x;
    result.w = w * _rq.w - x * _rq.x - y * _rq.y - z * _rq.z;

    return result;
}

Quaternion Quaternion::operator/(float _f) const
{
    Quaternion result = {};
    result.x = x / _f;
    result.y = y / _f;
    result.z = z / _f;
    result.w = w / _f;

    return result;
}

Vector3 FMath::RotateVector(const Vector3& _v, const Quaternion& _q)
{
    Vector3 result = {};

    Quaternion q = _q * Quaternion({ _v.x, _v.y, _v.z, 0.0f }) * Quaternion::Conjugate(_q);

    result.x = q.x;
    result.y = q.y;
    result.z = q.z;

    return result;
}
