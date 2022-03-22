#ifndef ARRAY_PRINTER_H
#define ARRAY_PRINTER_H
#include <iostream>
using namespace std;

template <class T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}


#endif