#include <iostream>
#include <vector>
using namespace std;

int mat[1000][1000];
int nodeCount;
vector<int> bestWay;
vector<int> way;
int bestWayLenth;
int wayLenth;

bool IsInWay(int node)
{
	for (auto it : way)
		if (it == node)
			return true;
	return false;
}


void FindWay(int startNode, int aimNode)//startNode and aimNode are numbers start form 0
{
	if (startNode == aimNode)
	{
		if (wayLenth == bestWayLenth && way.size() >= bestWay.size())
			return;
		bestWayLenth = wayLenth;
		bestWay = way;
		return;
	}
	for (int i = 0; i < nodeCount; ++i)
	{
		if (!IsInWay(i) && mat[startNode][i] != -1 && wayLenth + mat[startNode][i] <= bestWayLenth)
		{
			wayLenth += mat[startNode][i];
			way.push_back(i);
			FindWay(i, aimNode);
			way.pop_back();
			wayLenth -= mat[startNode][i];
		}
	}
}

void Init()
{
	bestWay.clear();
	way.clear();
	bestWayLenth = INT_MAX;
	wayLenth = 0;
}

void ShowBestWay()
{
	bool isFirst = true;
	for (auto it : bestWay)
	{
		if (isFirst)
		{
			cout << it + 1;
			isFirst = false;
			continue;
		}
		cout << "->" << it + 1;
	}
		
}

int main()
{
	int caseCount = 0;
	while (cin >> nodeCount)
	{
		for (int i = 0; i < nodeCount; ++i)
			for (int j = 0; j < nodeCount; ++j)
				cin >> mat[i][j];
		int startNode;
		int aimNode;
		cin >> startNode >> aimNode;
		Init();
		way.push_back(startNode - 1);
		FindWay(startNode - 1, aimNode - 1);
		cout << "Case " << ++caseCount << endl;
		cout << "The least distance from " << startNode << "->" << aimNode << " is " << bestWayLenth << endl;
		cout << "the path is ";
		ShowBestWay();
		cout << endl;
	}
	return 0;
}