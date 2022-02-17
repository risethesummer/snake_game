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
	int ** arr = nullptr;
	int n = 0;
	cout << "Bai 2: Mang 2 chieu/n";
	InputMatrix(arr, n);
	cout << "Thong tin mang vua nhap la/n";
	PrintMatrix(arr, n);
	FreeMatrix(arr, n);
	
}

int main()
{
	Exercise1();
	Exercise2();

	return 1;
}
