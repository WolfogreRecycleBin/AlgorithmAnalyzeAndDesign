#pragma once
#include "Matrix.h"
#include <exception>
#include "Point.h"
class Domino
{
public:
	Domino(int value, int type) :_mat(2, 2)
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				_mat.SetValue(i, j, value);
		switch (type)
		{
		case 1:
			_mat.SetValue(1, 1, 0);
			break;
		case 2:
			_mat.SetValue(1, 0, 0);
			break;
		case 3:
			_mat.SetValue(0, 1, 0);
			break;
		case 4:
			_mat.SetValue(0, 0, 0);
			break;
		default:
			throw std::exception("there is not this type");
		}
	}

	~Domino()
	{
		_mat.~Matrix();
	}

	Domino & operator = (const Domino & value) = delete;

	bool GetValue(Point point)
	{
		return _mat.GetValue(point);
	}

private:
	Matrix _mat;
};