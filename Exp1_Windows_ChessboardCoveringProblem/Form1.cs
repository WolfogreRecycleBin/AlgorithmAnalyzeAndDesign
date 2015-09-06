using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Exp1_Windows_ChessboardCoveringProblem
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			int k = Convert.ToInt32(textBox2.Text);
			int size = 1 << k;
			int specialRow = Convert.ToInt32(textBox3.Text) - 1;
			int specialCol = Convert.ToInt32(textBox4.Text) - 1;
			ChessBoard cb = new ChessBoard(size, specialCol, specialRow);
			int [,] result = cb.FillBoard();
			textBox1.Clear();
			for(int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
					textBox1.Text += " " + result[i, j];
				textBox1.Text += " " + Environment.NewLine;
			}
			chessBoardControl.LoadData(result, size);
		}
	}
}
