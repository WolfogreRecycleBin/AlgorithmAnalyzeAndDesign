#include <iostream>
using namespace std;

int Board[1000][1000];
int tile = 1;

void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)
		return;
	int t = tile++;
	int s = size / 2;
	if (dr < tr + s && dc < tc + s)
		ChessBoard(tr, tc, dr, dc, s);
	else
	{
		Board[tr + s - 1][tc + s - 1] = t;
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr < tr + s && dc >= tc + s)
		ChessBoard(tr, tc + s, dr, dc, s);
	else
	{
		Board[tr + s - 1][tc + s] = t;
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}
	if (dr >= tr + s && dc < tc + s)
		ChessBoard(tr + s, tc, dr, dc, s);
	else
	{
		Board[tr + s][tc + s - 1] = t;
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s)
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else
	{
		Board[tr + s][tc + s] = t;
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}

int main()
{
	int k = 2;
	int size = 1 << k;
	int row = 2 - 1;
	int col = 3 - 1;
	
	
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			Board[i][j] = -1;

		
	ChessBoard(0, 0, row, col, size);


	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cout << Board[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}