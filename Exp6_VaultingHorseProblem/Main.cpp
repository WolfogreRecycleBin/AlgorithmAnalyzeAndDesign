#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Point
{
	int row;
	int col;
};

Point dRC[] = {
	{ -2, -1, },
	{ -2, +1, },
	{ -1, -2, },
	{ -1, +2, },
	{ +1, -2, },
	{ +1, +2, },
	{ +2, -1, },
	{ +2, +1, }
};

bool mat[8][8];

int FindWay(queue<Point> &points, Point aimNode)
{
	if (mat[aimNode.row][aimNode.col])
	{
		return 0;
	}
	queue<Point> newPoints;
	while (!points.empty())
	{
		Point point = points.front();
		points.pop();
		for (int i = 0; i < 8; ++i)
		{
			int row2 = point.row + dRC[i].row;
			int col2 = point.col + dRC[i].col;
			if (row2 >= 0 && row2 <= 7 && col2 >= 0 && col2 <= 7 && !mat[row2][col2])
			{
				mat[row2][col2] = true;
				Point newPoint;
				newPoint.row = row2;
				newPoint.col = col2;
				newPoints.push(newPoint);
			}
		}
	}
	return 1 + FindWay(newPoints, aimNode);
}

void Init()
{
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			mat[i][j] = false;
}

int main()
{
	int caseCount = 0;
	string line;
	while (getline(cin,line) && line.length() == 5)
	{
		Init();
		Point startNode;
		Point aimNode;
		stringstream sstr;
		sstr << line;
		char ch;
		sstr >> ch;
		startNode.row = ch - 'a';
		sstr >> ch;
		startNode.col = ch - '1';
		sstr >> ch;
		aimNode.row = ch - 'a';
		sstr >> ch;
		aimNode.col = ch - '1';
		queue<Point> points;
		points.push(startNode);
		mat[startNode.row][startNode.col] = true;
		cout << (char)(startNode.row + 'a') << (char)(startNode.col + '1')
			<< "==>"
			<< (char)(aimNode.row + 'a') << (char)(aimNode.col + '1')
			<< ": " << FindWay(points, aimNode)
			<< " moves" << endl;
	}
	return 0;
}