#include "Array2D.h"

int main()
{
	Fraction** f = NULL;
	alloc2D((void***)&f, 2, 3, sizeof(Fraction));
	arr2DInput((void**)f);
	arr2DOutput((void**)f);
	free2D((void**)f);
	return 1;
}