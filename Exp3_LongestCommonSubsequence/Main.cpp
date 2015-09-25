#include <iostream>
#include <string>
using namespace std;

int mat_c[100][100];
int mat_b[100][100];
char str_x[] = "sABCBDAB";
char str_y[] = "sBDCABA";



void CalMatCB(int row, int col)
{
	for (int co = 0; co < col; ++co)
	{
		for (int ro = 0; ro < row; ++ro)
		{
			if (co == 0 || ro == 0)
			{
				mat_c[ro][co] = 0;
				mat_b[ro][co] = 0;
				continue;
			}
			if (str_x[co] == str_y[ro])
			{
				mat_c[ro][co] = mat_c[ro - 1][co - 1] + 1;
				mat_b[ro][co] = 1;
				continue;
			}
			if (mat_c[ro - 1][co] >= mat_c[ro][co - 1])
			{
				mat_c[ro][co] = mat_c[ro - 1][co];
				mat_b[ro][co] = 2;
				continue;
			}
			mat_c[ro][co] = mat_c[ro][co - 1];
			mat_b[ro][co] = 3;
			continue;
		}
	}

}

void ShowC(int size)
{
	cout << endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (mat_c[i][j] == -1)
				cout << "*" << " ";
			else
				cout << mat_c[i][j] << " ";
		}
		cout << endl;
	}
}

void ShowB(int size)
{
	cout << endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << mat_b[i][j] << " ";
		}
		cout << endl;
	}
}

string LCS(int i, int j)
{
	if (i == 0 || j == 0)
		return string("");
	if (mat_b[i][j] == 1)
		return LCS(i - 1, j - 1) + str_x[i];
	if (mat_b[i][j] == 2)
		return LCS(i - 1, j);
	if (mat_b[i][j] == 3)
		return LCS(i, j - 1);
}

int main()
{
	int str_x_len = 7 + 1;
	int str_y_len = 6 + 1;

	CalMatCB(str_x_len + 1, str_y_len + 1);
	ShowC(str_x_len);
	ShowB(str_x_len);
	cout << LCS(str_x_len, str_y_len) << endl;
	system("pause");
	return 0;
}
