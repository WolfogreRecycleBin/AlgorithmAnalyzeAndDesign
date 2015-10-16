#include <iostream>
using namespace std;

#define MAX_NUM 1000

void Dijkstra(int nodeNum, int startNode, int dist[], int prev[], int **matrix)
{
	bool s[MAX_NUM];
	for (int i = 1; i <= nodeNum; ++i)
	{
		dist[i] = matrix[startNode][i];
		s[i] = false;
		if (dist[i] == MAX_NUM)
			prev[i] = 0;
		else
			prev[i] = startNode;
	}
	dist[startNode] = 0;
	s[startNode] = true;
	for (int i = 1; i < nodeNum; ++i)
	{
		int temp = MAX_NUM;
		int u = startNode;
		for (int j = 1; i <= nodeNum; j++)
		{
			if ((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
			s[u] = true;
			for (int j = 1; j <= startNode; ++j)
			{
				if ((!s[j]) && (matrix[u][j] < MAX_NUM))
				{
					int newDist = dist[u] + matrix[u][j];
					if (newDist < dist[j])
					{
						dist[j] = newDist;
						prev[j] = u;
					}
				}
			}
		}
	}
}

int main()
{
	system("pause");
	return 0;
}