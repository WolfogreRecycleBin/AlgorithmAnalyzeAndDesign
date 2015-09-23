#include  <iostream>
using namespace std;

int c[100][100];
int b[100][100];
char str_x[] = "sABCBDAB";
char str_y[] = "sBDCABA"; 


void InitCB()
{
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
		{
			c[i][j] = -1;
			b[i][j] = 0;
		}	
}

int CalCB(int i, int j)
{
	if(c[i][j] != -1)
		return c[i][j];

	if(i == 0 || j == 0)
		c[i][j] = 0;
	else
	{
		if(str_x[i] == str_y[j])
		{
			c[i][j] = CalCB(i - 1, j - 1) + 1;
			b[i][j] = 1;
		}
		else
		{
			if(CalCB(i, j - 1) > CalCB(i - 1, j))
			{
				c[i][j] = CalCB(i, j - 1);
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = CalCB(i - 1, j);
				b[i][j] = 3;
			}
		}
		
	}
	return c[i][j];
}

void ShowC(int size)
{
	cout << endl;
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if(c[i][j] == -1)
				cout << "*" << " ";
			else
				cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

void ShowB(int size)
{
	cout << endl;
	for(int i = 1; i < size; ++i)
	{
		for(int j = 1; j < size; ++j)
		{
			if(b[i][j] == 0)
				cout << "*" << " ";
			else
				cout << b[i][j] << " ";
		}
		cout << endl;
	}
}

string LCS(int i, int j)
{
	if(i == 0 || j == 0)
		return string("");
	if(b[i][j] == 1)
		return LCS(i - 1, j - 1) + str_x[i];
	if(b[i][j] == 2)
		return LCS(i - 1, j);
	if(b[i][j] == 3)
		return LCS(i, j - 1);
}

int main()
{
	int str_x_len = 7 + 1;
	int str_y_len = 6 + 1;
	
	InitCB();
	//for(int i = 0; i < str_x_len; ++i)
		//for(int j = 0; j < str_y_len; ++j)
			CalCB(str_x_len,str_y_len);
	ShowC(str_x_len);
	ShowB(str_x_len);
	cout << LCS(str_x_len, str_y_len) << endl;;
	return 0;
}































