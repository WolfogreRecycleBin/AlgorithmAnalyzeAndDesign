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
		int _specailX;
		int _specailY;
		Color _specailColor;

		public ChessBoardControl()
		{
			_board = null;
			_size = 0;
			_specailColor = Color.FromArgb(0, 0, 0);
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
			this.timer1.Start();
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
							_specailX = j;
							_specailY = i;
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

		void Twinkle(Graphics g)
		{
			if(_board != null)
			{
				int atomWidth = this.Size.Width / _size;
				int atomHeight = this.Size.Height / _size;
				Brush brush = new SolidBrush(_specailColor);
				Rectangle rect = new Rectangle(_specailX * atomWidth, _specailY * atomHeight, atomWidth, atomHeight);
				g.FillRectangle(brush, rect);
				if(_specailColor.R == 0)
					_specailColor = Color.FromArgb(255, 255, 255);
				else
					_specailColor = Color.FromArgb(0, 0, 0);
			}
		}

		private void ChessBoardControl_Paint(object sender, PaintEventArgs e)
		{
			Graphics g = e.Graphics;
			this.Draw(g);
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			Twinkle(this.CreateGraphics());
		}
	}
}
