using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Exp1_Windows_ChessboardCoveringProblem
{
	public partial class ChessBoardControl : UserControl
	{
		int[,] _board;
		int _size;

		public ChessBoardControl()
		{
			_board = null;
			_size = 0;
			InitializeComponent();
		}

		public void LoadData(int[,] board, int size)
		{
			_size = size;
			_board = new int[_size, _size];
			for (int i = 0; i < _size; ++i)
				for (int j = 0; j < _size; ++j)
					_board[i, j] = board[i, j];
			PaintEventArgs pra = new PaintEventArgs(this.CreateGraphics(), this.ClientRectangle);
			this.OnPrint(pra);
		}

		void Draw(Graphics g)
		{
			if(_board != null)
			{
				int atomWidth = this.Size.Width / _size;
				int atomHeight = this.Size.Height / _size;
				for (int i = 0; i < _size; ++i)
					for (int j = 0; j < _size; ++j)
					{
						Rectangle rect = new Rectangle(j * atomWidth, i * atomHeight, atomWidth, atomHeight);
						Color color;
						if(_board[i, j] == 0)
						{
							color = Color.FromArgb(0, 0, 0);
						}
						else
						{
							Random r = new Random(_board[i, j]);
							color = Color.FromArgb(r.Next(255), r.Next(255), r.Next(255));
						}
						
						Brush brush = new SolidBrush(color);
						g.FillRectangle(brush, rect);
					}
			}
		}



		private void ChessBoardControl_Paint(object sender, PaintEventArgs e)
		{
			Graphics g = e.Graphics;
			this.Draw(g);
		}
	}
}
