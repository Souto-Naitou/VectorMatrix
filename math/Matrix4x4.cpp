#include "Matrix4x4.h"
#include <matrix4calc.h>

Matrix4x4 Matrix4x4::operator*=(const Matrix4x4& _lm)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m[i][j] *= _lm.m[i][j];
		}
	}
	return *this;
}

Matrix4x4 operator*(const Matrix4x4& _lm, const Matrix4x4& _rm)
{
	Matrix4x4 result{};

	result = Multiply(_lm, _rm);

	return result;
}
