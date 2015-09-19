#include <iostream>
#include <string>
using namespace std;

// int p & int n: the dimension of the matrix[i] is p[i - 1] * p[i], i = [1 : n];
// int m[][]: the least multiply times required of matrix[i : j] is m[i][j], 1 <= i <= j <= n;
// int s[][]: the best disconnection position of matrix[i : j] is p[i][j], 1 <= i <= j <= n;
void MatrixChain(int *p, int n, int **m, int **s)
{
	//the least multiply times required of matrix[i : i] is 0
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

string Traceback(int i, int j, int **s, string left_str, string right_str)
{
	//if (i == j)
	//	return "A" + string(itoa(i, str, 10));
	if (i == j)
	{
		char str[100];
		_itoa_s(i, str, 10);
		return "A" + string(str);
	}

	left_str += Traceback(i, s[i][j], s, "", "");
	right_str += Traceback(s[i][j] + 1, j, s, "", "");
	return "(" + left_str + right_str + ")";
}

int main()
{
	int p[20];
	int **m = new int*[20];
	int **s = new int*[20];
	for (int i = 0; i < 20; ++i)
	{
		m[i] = new int[20];
		s[i] = new int[20];
	}

	int n;
	int count = 0;
	while (cin >> n)
	{
		++count;
		for (int i = 0; i <= n; ++i)
		{
			cin >> p[i];
		}
		MatrixChain(p, n, m, s);
		string result = Traceback(1, n, s, "", "");
		result.erase(0, 1);
		result.erase(result.length() - 1, 1);
		cout << "Case " << count << endl;
		cout << m[1][n] << " " << result << endl;
	}

	for (int i = 0; i < 20; ++i)
	{
		delete[] m[i];
		delete[] s[i];
	}
	delete[] m;
	delete[] s;
	system("pause");
	return 0;
}