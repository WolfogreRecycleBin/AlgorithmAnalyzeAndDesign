#include <iostream>
using namespace std;

void MatrixChain(int *p, int n, int **m, int **s)
{
	for (int i = 1; i <= n; ++i)
		m[i][i] = 0;
	for (int r = 2; r <= n; ++r)
		for (int i = 1; i <= n - r + 1; ++i)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; ++k)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
}

void Traceback(int i, int j, int **s)
{
	if (i == j)
		return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "M A" << i << "," << s[i][j];
	cout << "and A" << (s[i][j] + 1) << "," << j << endl;
}


void Show(int **mat, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int p[7] = { 30, 35, 15, 5, 10, 20 , 25};
	int **m = new int*[7];
	int **s = new int*[7];
	for (int i = 0; i < 7; ++i)
	{
		m[i] = new int[7];
		s[i] = new int[7];
	}
	MatrixChain(p, 6, m, s);
	Traceback(1, 6, s);
	system("pause");
	return 0;
}