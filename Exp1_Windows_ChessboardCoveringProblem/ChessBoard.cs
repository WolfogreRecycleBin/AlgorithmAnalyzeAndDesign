using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exp1_Windows_ChessboardCoveringProblem
{
	class ChessBoard
	{
		int _size;
		int[,] _board;
		int _specialX;
		int _specialY;
		public ChessBoard(int size, int specialX, int specialY)
		{
			_size = size;
			_specialX = specialX;
			_specialY = specialY;
			_board = new int[_size, _size];
		}
		public int[,] FillBoard()
		{
			int dominoNumber = 1;
			FillBoardHelp(0, 0, _size, _specialX, _specialY, ref dominoNumber);
			return (int[,]) _board.Clone();
		}
		public void FillBoardHelp(int originRow, int originCol, int originSize, int originSpecialX, int originSpecialY, ref int originNumber)
		{
			if (originSize == 1)
				return;
			int size = originSize / 2;
			int number = originNumber++;

			if (originSpecialX < originCol + size && originSpecialY < originRow + size)
			{
				FillBoardHelp(originRow, originCol, size, originSpecialX, originSpecialY, ref originNumber);
			}
			else
			{
				_board[originRow + size - 1, originCol + size - 1] = number;
				FillBoardHelp(originRow, originCol, size, originCol + size - 1, originRow + size - 1, ref originNumber);
			}

			if (originSpecialX >= originCol + size && originSpecialY < originRow + size)
			{
				FillBoardHelp(originRow, originCol + size, size, originSpecialX, originSpecialY, ref originNumber);
			}
			else
			{
				_board[originRow + size - 1, originCol + size] = number;
				FillBoardHelp(originRow, originCol + size, size, originCol + size, originRow + size - 1, ref originNumber);
			}

			if (originSpecialX < originCol + size && originSpecialY >= originRow + size)
			{
				FillBoardHelp(originRow + size, originCol, size, originSpecialX, originSpecialY, ref originNumber);
			}
			else
			{
				_board[originRow + size, originCol + size - 1] = number;
				FillBoardHelp(originRow + size, originCol, size, originCol + size - 1, originRow + size, ref originNumber);
			}

			if (originSpecialX >= originCol + size && originSpecialY >= originRow + size)
			{
				FillBoardHelp(originRow + size, originCol + size, size, originSpecialX, originSpecialY, ref originNumber);
			}
			else
			{
				_board[originRow + size, originCol + size] = number;
				FillBoardHelp(originRow + size, originCol + size, size, originCol + size, originRow + size, ref originNumber);
			}
		}
	}
}
