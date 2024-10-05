// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#pragma once
/// <summary>
/// 4x4行列
/// </summary>
class Matrix4x4 {
public:
	float m[4][4];
	Matrix4x4 operator*=(const Matrix4x4& _lm);
};

Matrix4x4 operator*(const Matrix4x4& _lm, const Matrix4x4& _rm);

