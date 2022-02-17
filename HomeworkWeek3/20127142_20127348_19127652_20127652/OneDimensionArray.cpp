#include "OneDimensionArray.h"

void InputArray_1D(int*& a, int& n)
{
	n = 0;
	while (n <= 0)
	{
		cout << "Moi nhap vao kich thuoc mang: ";
		cin >> n;
		if (n <= 0)
			cout << "Kich thuoc khong the <= 0. Moi nhap lai!\n";
	}
	
	a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}

void FreeArray(int*& a)
{
	delete[] a;
}

void OutputArray_1D(int* a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
