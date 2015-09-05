#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int row, int col)
{
	_row = row;
	_col = col;
	_p = new int *[_row];
	for (int i = 0; i < _row; ++i)
	{
		_p[i] = new int[_col];
	}

	for (int i = 0; i < _row; ++i)
		for (int j = 0; j < _col; ++j)
			_p[i][j] = 0;
}


Matrix::~Matrix()
{
	for (int i = 0; i < _row; ++i)
	{
		//delete[] _p[i];
	}
	//delete[] _p;
}

bool Matrix::Show()
{
	for (int i = 0; i < _row; ++i)
	{
		for (int j = 0; j < _col; ++j)
		{
			std::cout << _p[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return true;
}