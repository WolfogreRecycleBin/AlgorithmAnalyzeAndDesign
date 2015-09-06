#pragma once
#include "Point.h"
class Matrix
{
public:
	//构造函数
	Matrix(int row, int col)
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

	//析构函数
	~Matrix()
	{
		if (_p != NULL)
		{
			for (int i = 0; i < _row; ++i)
			{
				if (_p[i] != NULL)
				{
					delete[] _p[i];
					_p[i] = NULL;
				}
			}
			delete[] _p;
			_p = NULL;
		}
	}

	//删除拷贝函数
	Matrix & operator = (const Matrix & value) = delete;

	//获得某点的值
	int GetValue(Point point)
	{
		return _p[point.y][point.x];
	}
	int GetValue(int x, int y)
	{
		return _p[y][x];
	}

	//设置某点的值
	bool SetValue(Point point, const int & value)
	{
		_p[point.y][point.x] = value;
		return true;
	}
	bool SetValue(int x, int y, const int & value)
	{
		_p[y][x] = value;
		return true;
	}

	//获得矩阵的行数
	int GetRow()
	{
		return _row;
	}

	//获得矩阵的列数
	int GetCol()
	{
		return _col;
	}

	//显示矩阵
	bool Show()
	{
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
	}

	//返回矩阵是否全满
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

private:
	int _row;															//矩阵行数
	int _col;															//矩阵列数
	int ** _p;															//二维数组指针
};

