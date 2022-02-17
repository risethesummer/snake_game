#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "OneDimensionArray.h"
using namespace std;

int** CreateMatrix(int n);
void PrintMatrix(int** matrix, int n);
void FreeMatrix(int** matrix, int n);
void InputMatrix(int**& matrix, int& n);

#endif