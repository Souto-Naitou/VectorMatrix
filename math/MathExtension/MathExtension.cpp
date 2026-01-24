#include "mathExtension.h"
#include "../Vector3.h"

#include <cmath>

float Math::cotanf(float x)
{
    return 1.0f / std::tanf(x);
}

Vector3 Math::TransformNormal(const Vector3& v, const Matrix4x4& m)
{
    Vector3 result
    {
        v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0],
        v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1],
        v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2]
    };

    return result;
}

Vector3 Math::Lerp(const Vector3& vx, const Vector3& vy, float t)
{
    return (1.0f - t) * vx + t * vy;
}

Vector3 Math::Slerp(const Vector3& vx, const Vector3& vy, float t)
{
    Vector3 normvx = FMath::Normalize(vx);
    Vector3 normvy = FMath::Normalize(vy);
    // dot
    float dot = FMath::Dot(normvx, normvy);
    // gosa
    dot = dot > 1.0f ? 1.0f : dot;
    // arccos
    float theta = std::acos(dot);
    // theta to sin(theta)
    float sinTheta = std::sin(theta);
    // sin(theta(1-t))
    float sinThetaFrom = std::sin((1.0f - t) * theta);
    // sin theta t
    float sinThetaTo = std::sin(t * theta);
    Vector3 normalizedInterpVector = sinThetaFrom / sinTheta * normvx + sinThetaTo / sinTheta * normvy;
    // prevent zero division
    if (sinTheta < 1.0e-5)
    {
        normalizedInterpVector = normvx;
    }
    else
    {
        // 球面線形補間したベクトル
        normalizedInterpVector = (sinThetaFrom * normvx + sinThetaTo * normvy) * (1.0f / sinTheta);
    }
    float lengthx = FMath::Length(vx);
    float lengthy = FMath::Length(vy);
    float length = std::lerp(lengthx, lengthy, t);

    return length * normalizedInterpVector;
}
