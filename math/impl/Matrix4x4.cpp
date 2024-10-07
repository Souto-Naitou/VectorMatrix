// Copyright © 2024 Souto-Naitou. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root for license information.

#include "../Matrix4x4.h"
#include "../Matrix4calc.h"

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
