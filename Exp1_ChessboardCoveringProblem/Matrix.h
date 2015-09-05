#pragma once
class Matrix
{
public:
	Matrix(int row, int col);
	~Matrix();
	Matrix & operator = (const Matrix & value) = delete;
	bool GetValue(int row, int col, int & value);
	bool SetValue(int row, int col, const int & value);
	bool Show();
private:
	int _row;
	int _col;
	int ** _p;
};

