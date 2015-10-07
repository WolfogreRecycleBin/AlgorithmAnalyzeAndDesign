#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mat_c[100][100];
int mat_b[100][100];
char str_x[100];
char str_y[100];



void CalMatCB(int rows, int cols)
{
	for (int col = 0; col < cols; ++col)
	{
		for (int row = 0; row < rows; ++row)
		{
			if (col == 0 || row == 0)
			{
				mat_c[row][col] = 0;
				mat_b[row][col] = 0;
				continue;
			}
			if (str_x[row - 1] == str_y[col - 1])
			{
				mat_c[row][col] = mat_c[row - 1][col - 1] + 1;
				mat_b[row][col] = 1;
				continue;
			}
			if (mat_c[row - 1][col] > mat_c[row][col - 1])
			{
				mat_c[row][col] = mat_c[row - 1][col];
				mat_b[row][col] = 2;
				continue;
			}
			if (mat_c[row - 1][col] < mat_c[row][col - 1])
			{
				mat_c[row][col] = mat_c[row][col - 1];
				mat_b[row][col] = 3;
				continue;
			}
			mat_c[row][col] = mat_c[row][col - 1];
			mat_b[row][col] = 4;
			continue;
		}
	}

}

void ShowC(int rows, int cols)
{
	cout << endl;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
			cout << mat_c[row][col] << " ";
		cout << endl;
	}
}

void ShowB(int rows, int cols)
{
	cout << endl;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
			cout << mat_b[row][col] << " ";
		cout << endl;
	}
}

void LCS(int row, int col, vector<char> & chars)
{
	//cout << "LCS(" << row << ", " << col << ", " << "chars(";
	//for (auto ch : chars)
	//	cout << ch;
	//cout << "));" << endl;
	if (mat_b[row][col] == 0)
	{
		for (int i = chars.size() - 1; i >= 0; --i)
			cout << chars[i] << " ";
		cout << endl;
		return;
	}
	if (mat_b[row][col] == 1)
	{
		chars.push_back(str_x[row - 1]);
		LCS(row - 1, col - 1, chars);
		chars.pop_back();
		return;
	}
	if (mat_b[row][col] == 2)
	{
		LCS(row - 1, col, chars);
		return;
	}
	if (mat_b[row][col] == 3)
	{
		LCS(row, col - 1, chars);
		return;
	}
	if (mat_b[row][col] == 4)
	{
		LCS(row, col - 1, chars);
		LCS(row - 1, col, chars);
		return;
	}
	throw exception("error");
}

int main()
{
	int cases;
	cin >> cases;

	int count = 1;
	while (cases--)
	{

		int str_x_len;
		int str_y_len;
		cin >> str_x_len;
		cin >> str_y_len;
		for (int i = 0; i < str_x_len; ++i)
			cin >> str_x[i];
		for (int i = 0; i < str_y_len; ++i)
			cin >> str_y[i];
		CalMatCB(str_x_len + 1, str_y_len + 1);
		vector<char> chars;
		cout << "Case " << count++ << endl;
		cout << "最长公共子序列的长度:" << mat_c[str_x_len][str_y_len] << endl;
		LCS(str_x_len, str_y_len, chars);
		ShowC(str_x_len + 1, str_y_len + 1);
		ShowB(str_x_len + 1, str_y_len + 1);
	}
	system("pause");
	return 0;
}
