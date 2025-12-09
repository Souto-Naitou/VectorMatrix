// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "../Vector3.h"
#include "../Matrix4x4.h"

#include <assert.h>
#include <math.h>

Vector3 FMath::Add(const Vector3& v1, const Vector3& v2)
{
    return Vector3(
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    );
}

Vector3 FMath::Subtract(const Vector3& v1, const Vector3& v2)
{
    return Vector3(
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    );
}

Vector3 FMath::Multiply(float scalar, const Vector3& v)
{
    return Vector3(
        scalar * v.x,
        scalar * v.y,
        scalar * v.z
    );
}

float FMath::Dot(const Vector3& v1, const Vector3& v2)
{
    return float(
        v1.x * v2.x +
        v1.y * v2.y +
        v1.z * v2.z
        );
}

float FMath::Length(const Vector3& v)
{
    return sqrtf(
        v.x * v.x +
        v.y * v.y +
        v.z * v.z
        );
}

Vector3 FMath::Normalize(const Vector3& v)
{
    float length = Length(v);
    return Vector3(
        v.x / length,
        v.y / length,
        v.z / length
        );
}

Vector3 FMath::Transform(const Vector3& vector, const Matrix4x4& matrix)
{
    Vector3 result{};
    result.x =
        vector.x * matrix.m[0][0] +
        vector.y * matrix.m[1][0] +
        vector.z * matrix.m[2][0] +
        1.0f * matrix.m[3][0];
    result.y =
        vector.x * matrix.m[0][1] +
        vector.y * matrix.m[1][1] +
        vector.z * matrix.m[2][1] +
        1.0f * matrix.m[3][1];
    result.z =
        vector.x * matrix.m[0][2] +
        vector.y * matrix.m[1][2] +
        vector.z * matrix.m[2][2] +
        1.0f * matrix.m[3][2];
    float w =
        vector.x * matrix.m[0][3] +
        vector.y * matrix.m[1][3] +
        vector.z * matrix.m[2][3] +
        1.0f * matrix.m[3][3];
    assert(w != 0.0f);
    result.x /= w;
    result.y /= w;
    result.z /= w;
    return result;
}
