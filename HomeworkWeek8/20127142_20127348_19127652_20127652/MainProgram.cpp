#include "Array2D.h"

int main()
{
	Fraction** f = NULL;
	allocArr((void***)&f, 2, 3, sizeof(Fraction));
	arr2DInput((void**)f);
	arr2DOutput((void**)f);
	freeArr((void**)f);
	return 1;
}