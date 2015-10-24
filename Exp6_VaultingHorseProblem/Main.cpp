#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Point
{
	int row;
	int col;
};

bool mat[8][8][8][8];
vector<Point> way;
int bestWayLenth;
int wayLenth;

bool IsInWay(Point point)
{
	for (auto it : way)
		if (it.row == point.row && it.col == point.col)
			return true;
	return false;
}

void InitMat()
{
	for (int row1 = 0; row1 < 8; ++row1)
		for (int col1 = 0; col1 < 8; ++col1)
		{
			for (int row2 = 0; row2 < 8; ++row2)
				for (int col2 = 0; col2 < 8; ++col2)
					mat[row1][col1][row2][col2] = false;
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
			for (int i = 0; i < 8; ++i)
			{
				int row2 = row1 + dRC[i].row;
				int col2 = col1 + dRC[i].col;
				if (row2 >= 0 && row2 <= 8 && col2 >= 0 && col2 <= 8)
					mat[row1][col1][row2][col2] = true;
			}
		}		
}

void InitWay()
{
	way.clear();
	bestWayLenth = INT_MAX;
	wayLenth = 0;
}

void FindWay(Point startNode, Point aimNode)//startNode and aimNode are numbers start form 0
{
	if (startNode.row == aimNode.row && startNode.col == aimNode.col)
	{
		bestWayLenth = wayLenth;
		return;
	}
	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			Point point;
			point.row = row;
			point.col = col;
			{
				if (!IsInWay(point) && mat[startNode.row][startNode.col][row][col] && wayLenth + 1 <= bestWayLenth)
				{
					++wayLenth;
					way.push_back(point);
					FindWay(point, aimNode);
					way.pop_back();
					--wayLenth;
				}
			}
		}
}


int main()
{
	int caseCount = 0;
	string line;
	InitMat();
	while (getline(cin,line) && line.length() == 5)
	{
		Point startNode;
		Point aimNode;
		stringstream sstr;
		sstr << line;
		char ch;
		sstr >> ch;
		startNode.row = ch - 'a';
		//cout << ch << " " << startNode.row << endl;
		sstr >> ch;
		startNode.col = ch - '1';
		//cout << ch << " " << startNode.col << endl;
		sstr >> ch;
		aimNode.row = ch - 'a';
		//cout << ch << " " << aimNode.row << endl;
		sstr >> ch;
		aimNode.col = ch - '1';
		//cout << ch << " " << aimNode.col << endl;
		InitWay();
		way.push_back(startNode);
		FindWay(startNode, aimNode);
		cout << (char)(startNode.row + 'a') << (char)(startNode.col + '1')
			<< "==>"
			<< (char)(aimNode.row + 'a') << (char)(aimNode.col + '1')
			<< ": " << bestWayLenth
			<< " moves" << endl;
	}
	return 0;
}