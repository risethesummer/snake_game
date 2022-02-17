#include "Matrix.h"
int** CreateMatrix(int n)
{
	if (n <= 0)
		return nullptr;
	int** result = new int* [n];
	for (int i = 0; i < n; i++)
		result[i] = new int[n];
	return result;
}

void InputMatrix(int**& matrix, int& n)
{
	n = 0;
	while (n <= 0)
	{
		cout << "Moi nhap vao so hang trong ma tran: ";
		cin >> n;
		if (n <= 0)
			cout << "So hang khong the <= 0. Moi nhap lai!\n";
	}

	matrix = CreateMatrix(n);

	for (int i = 0; i < n; i++)
	{
		cout << "Moi nhap vao thong tin hang " << i << "\n";
		for (int j = 0; j < n; j++)
		{
			cout << "Nhap phan tu thu " << j << " cua hang thu " << i << " : ";
			cin >> matrix[i][j];
		}
	}
}


void PrintMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void FreeMatrix(int** matrix, int n)
{
	for(int i = 0; i < n; i++)
		 delete []matrix[i];
	delete []matrix;
}
