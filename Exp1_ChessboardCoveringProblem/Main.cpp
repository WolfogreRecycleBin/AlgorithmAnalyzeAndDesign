#include <iostream>
#include "Matrix.h"
#include "Domino.h"
#include "Point.h"

bool Fit(Domino & domino, Matrix & mat, Point point);
bool Add(Domino & domino, Matrix & mat, Point point);
bool Sub(Domino & domino, Matrix & mat, Point point);
Point GetNextPoint(Point old_point, Matrix &mat);

bool AddDomino(int value, Matrix &mat, Point point)
{
	mat.Show();

	for (int type = 1; type <= 4; ++type)
	{
		Domino domino(type, value);
		if (!Fit(domino, mat, point))
			continue;
		else
		{
			Add(domino, mat, point);
			if (mat.IsFull())
			{
				mat.Show();
				return false;
			}
			if (AddDomino(value + 1, mat, GetNextPoint(point, mat)))
				return false;
			Sub(domino, mat, point);
		}
	}
	
	return true;

}


int main()
{
	int row = 2;
	int col = 2;

	Matrix mat(row, col);
	mat.SetValue(0, 1, -1);
	Point start_point(0,0);
	AddDomino(1, mat, start_point);

	system("pause");
	return 0;
}


bool Fit(Domino & domino, Matrix & mat, Point point)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (domino.GetValue())
		}
}
bool Add(Domino & domino, Matrix & mat, Point point);
bool Sub(Domino & domino, Matrix & mat, Point point);
Point GetNextPoint(Point old_point, Matrix &mat);

