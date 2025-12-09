#pragma once

#include "../Vector3.h"
#include "../Matrix4x4.h"

namespace Math
{
    float cotanf(float x);
    float clamp(
        float x,
        float min,
        float max
    );
    int clamp(
        int x,
        int min,
        int max
    );
    float Lerp(float x, float y, float t);
    Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);
    Vector3 Lerp(const Vector3& vx, const Vector3& vy, float t);
    Vector3 Slerp(const Vector3& vx, const Vector3& vy, float t);
}