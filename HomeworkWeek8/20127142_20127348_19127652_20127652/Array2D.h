#ifndef ARRAY_2D
#define ARRAY_2D
#define HEAD_SIZE 12
#include <memory.h>
#include "Fraction.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Array2D
{
	int row, col, itemSize;
	void* data[1];
};

int countRow(void** aData);
int countColumn(void** aData);
void free2D(void** aData);
void alloc2D(void*** a, int m, int n, int sz);
void arr2DInput(void** aData);
void arr2DOutput(void** aData);


#endif