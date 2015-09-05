#pragma once
#include "Point.h"
class Matrix
{
public:
	Matrix(int row, int col);
	~Matrix();
	Matrix & operator = (const Matrix & value) = delete;
	int GetValue(Point point)
	{
		return _p[point.y][point.x];
	}
	bool SetValue(Point point, const int & value)
	{
		_p[point.y][point.x] = value;
		return true;
	}
	int GetRow()
	{
		return _row;
	}
	int GetCol()
	{
		return _col;
	}
	bool Show();
	bool IsFull()
	{
		for (int i = 0; i < _row; ++i)
			for (int j = 0; j < _col; ++j)
			{
				if (_p[i][j] == 0)
					return false;
			}
		return true;
	}
	bool Show();
private:
	int _row;
	int _col;
	int ** _p;
};

