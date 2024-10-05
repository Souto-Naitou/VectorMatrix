#pragma once
/// <summary>
/// 4x4行列
/// </summary>
struct Matrix4x4 {
	float m[4][4];
	Matrix4x4 operator*=(const Matrix4x4& _lm);
};

Matrix4x4 operator*(const Matrix4x4& _lm, const Matrix4x4& _rm);

