#include <iostream>
#include "OneDimensionArray.h"
#include "Matrix.h"
using namespace std;

//Bai 1
void Exercise1()
{
	int* arr = nullptr;
	int n = 0;
	cout << "Bai 1: Mang 1 chieu\n";
	InputArray_1D(arr, n);
	cout << "Thong tin mang vua nhap la\n";
	OutputArray_1D(arr, n);
	FreeArray(arr);
}

//Bai 2
void Exercise2()
{
	int ** mat = nullptr;
	int n = 0;
	cout << "Bai 2: Ma tran\n";
	InputMatrix(mat, n);
	cout << "Thong tin ma tran vua nhap la\n";
	PrintMatrix(mat, n);
	FreeMatrix(mat, n);
}

int main()
{
	Exercise1();
	Exercise2();
	return 1;
}
