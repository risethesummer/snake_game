#include "Array2D.h"


int countRow(void** aData)
{
	Array2D* arr = (Array2D*)((char*)aData - HEAD_SIZE);
	if (arr != NULL) 
		return arr->row;
	return 0;

}

int countColumn(void** aData)
{
	Array2D* arr = (Array2D*)((char*)aData - HEAD_SIZE);
	if (arr != NULL) 
		return arr->col;
	return 0;
}

void freeArr(void** aData)
{
	if (aData != NULL) {
		void* p = (char*)aData - HEAD_SIZE;
		free(p);
	}
}

void allocArr(void*** a, int m, int n, int sz)
{
	if (m <= 0 || n <= 0 || sz <= 0) 
		return;
	int szRow = n * sz; // bytes per row
	int sz1 = m * sizeof(void*); // bytes of pointers' array1D
	int sz2 = m * szRow; // bytes of all data
	void* buf = calloc(HEAD_SIZE + sz1 + sz2, 1);
	if (buf == NULL) 
		return;
	Array2D* arr = (Array2D*)buf;
	arr->row = m; 
	arr->col = n; 
	arr->itemSize = sz;
	buf = (char*)buf + HEAD_SIZE + sz1;
	for (int i = 0; i < m; i++) 
	{
		arr->data[i] = buf;
		buf = (char*)buf + szRow;
	}
	*a = arr->data;
}

void arr2DInput(void** aData)
{
	//int row, col, size;
	//do
	//{
	//	cout << "Nhap vao so luong dong: ";
	//	cin >> row;
	//	if (row <= 0)
	//		cout << "So luong dong phai la so duong. Moi nhap lai!\n";
	//} while (row <= 0);

	//do
	//{
	//	cout << "Nhap vao so luong cot: ";
	//	cin >> col;
	//	if (col <= 0)
	//		cout << "So luong cot phai la so duong. Moi nhap lai!\n";
	//} while (col <= 0);
	//
	//allocArr(aData, row, col, sizeof(Fraction));
	for (int i = 0; i < countRow(aData); i++)
	{
		for (int j = 0; j < countColumn(aData); j++)
		{
			cout << "Nhap vao phan so dong " << i << ", cot " << j << '\n';
			cin >> ((Fraction**)aData)[i][j];
		}
	}
}

void arr2DOutput(void** aData)
{
	if (aData == NULL)
		return;

	for (int i = 0; i < countRow(aData); i++)
	{
		for (int j = 0; j < countColumn(aData); j++)
		{
			cout << ((Fraction**)aData)[i][j] << " ";
		}
		cout << endl;
	}
}
