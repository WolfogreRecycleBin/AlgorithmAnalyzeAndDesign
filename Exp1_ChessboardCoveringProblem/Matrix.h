#pragma once
#include "Point.h"
class Matrix
{
public:
	//���캯��
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

	//��������
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

	//ɾ����������
	Matrix & operator = (const Matrix & value) = delete;

	//���ĳ���ֵ
	int GetValue(Point point)
	{
		return _p[point.y][point.x];
	}
	int GetValue(int x, int y)
	{
		return _p[y][x];
	}

	//����ĳ���ֵ
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

	//��þ��������
	int GetRow()
	{
		return _row;
	}

	//��þ��������
	int GetCol()
	{
		return _col;
	}

	//��ʾ����
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

	//���ؾ����Ƿ�ȫ��
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
	int _row;															//��������
	int _col;															//��������
	int ** _p;															//��ά����ָ��
};

