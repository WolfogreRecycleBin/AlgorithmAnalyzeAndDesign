#include <iostream>
#include "Matrix.h"
#include "Domino.h"

bool AddDomino(int value, Matrix &mat, int x, int y, int row, int col)
{
	mat.Show();

	for (int type = 1; type <= 4; ++type)
	{
		Domino domino(type, value);
		//this is a shit!!!!!!!!!!!!
	}
	

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (x + i >= col)
				return true;
			if (y + j >= row)
				return true;
			int temp1;
			mat.GetValue(x + i, y + j, temp1);
			int temp2;
			domino.GetValue(x + i, y + j, temp2);
			if (temp1 != 0 && temp2 != 0)
				return true;
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			int temp1;
			domino.GetValue(i, j, temp1);
			int temp2;
			mat.GetValue(i, j, temp2);
			mat.SetValue(x + i, y + j, temp1 + temp2);
		}

	bool isFull = true;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int temp;
			mat.GetValue(i, j, temp);
			if (temp == 0)
			{
				isFull = false;
				break;
			}
		}
	}
	if (isFull)
	{
		std::cout << "find!" << std::endl;
		return false;
	}

	int next_type = type;
	if (type < 4)
	{
		++next_type;
		if (!AddDomino(next_type, value + 1, mat, x, y, row, col))
			return false;
	}
	
	next_type = 0;

	int next_x = x;
	int next_y = y;
	if (x + 1 < col)
	{
		++next_x;
	}
	else
	{
		if (y + 1 < row)
		{
			next_x = 0;
			++next_y;
		}
		else
		{
			std::cout << "error!" << std::endl;
			return false;
		}
	}
	
	if (!AddDomino(next_type, value + 1, mat, next_x, next_y, row, col))
		return false;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			int temp1;
			domino.GetValue(i, j, temp1);
			int temp2;
			mat.GetValue(i, j, temp2);
			mat.SetValue(x + i, y + j, temp2 - temp1);
		}

	return true;

}


int main()
{
	int row = 2;
	int col = 2;

	Matrix mat(row, col);
	mat.SetValue(0, 1, -1);
	AddDomino(1, 1, mat, 0, 0, 2, 2);

	system("pause");
	return 0;
}

