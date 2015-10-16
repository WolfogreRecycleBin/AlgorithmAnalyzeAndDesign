class Matrix
{
public:
	Matrix(int inputRows, int inputCols)
	{
		rows = inputRows;
		cols = inputCols;
		matrixPointer = new int*[rows];
		for (int i = 0; i < cols; ++i)
			matrixPointer[i] = new int[cols];

	}
	~Matrix()
	{
		if (matrixPointer == nullptr)
			return;
		for (int i = 0; i < cols; ++i)
			delete [] matrixPointer[i];
		delete[] matrixPointer;
		matrixPointer = nullptr;
	}

	int **matrixPointer;
	int rows, cols;
};