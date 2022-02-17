#include <iostream>
#include "OneDimensionArray.h"
#include "Matrix.h"

using namespace std;

int main()
{
	int* arr = nullptr;
	int n = 0;
	
	cout << "Moi nhap vao mang\n";
	InputArray_1D(arr, n);
	
	cout << "Thong tin mang vua nhap la\n";
	OutputArray_1D(arr, n);

	FreeArray(arr);

	return 1;
}