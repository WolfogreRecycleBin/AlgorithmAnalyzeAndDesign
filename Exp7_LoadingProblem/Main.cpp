#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> result;
vector<int> bestResult;
int w[10000];
int boxCount;
int valueSum;
int c1, c2;
int s1, s2;
int bestW;

void FindBestW(int index)
{
	if (index >= boxCount)
	{
		bestW = s1;
		return;
	}
	if (s1 + w[index] <= c1)
	{
		s1 += w[index];
		FindBestW(index + 1);
		s1 -= w[index];
	}
	if (s2 + w[index] <= c2 && valueSum - (s2 + w[index]) > bestW)
	{
		s2 += w[index];
		FindBestW(index + 1);
		s2 -= w[index];
	}
}

bool FindBestWay(int index)
{
	if (index >= boxCount)
	{
		bestResult = result;
		return true;
	}
	if (s1 + w[index] <= c1)
	{
		s1 += w[index];
		result.push_back(1);
		if (FindBestWay(index + 1))
			return true;
		result.pop_back();
		s1 -= w[index];
	}
	if (s2 + w[index] <= c2 && valueSum - (s2 + w[index]) >= bestW)
	{
		s2 += w[index];
		result.push_back(0);
		if (FindBestWay(index + 1))
			return true;
		result.pop_back();
		s2 -= w[index];
	}
	return false;
}

int main()
{
	int caseCount = 0;

	while (cin >> boxCount)
	{
		valueSum = 0;
		for (int i = 0; i < boxCount; ++i)
		{
			cin >> w[i];
			valueSum += w[i];
		}
		cin >> c1 >> c2;
		
		s1 = s2 = bestW = 0;
		FindBestW(0);
		cout << "Case " << ++caseCount << endl;
		if (bestW == 0)
			cout << "No" << endl;
		else
		{
			s1 = s2 = 0;
			result.clear();
			bestResult.clear();
			FindBestWay(0);
			cout << bestW << " ";
			for (auto it : bestResult)
				cout << it;
			cout << endl;
		}
	}
	return 0;
}