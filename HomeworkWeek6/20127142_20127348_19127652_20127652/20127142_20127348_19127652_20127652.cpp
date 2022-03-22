#include <iostream>
#include "Fraction.h"
#include "Sort.h"
#include "ArrayPrinter.h"
#include <string>
using namespace std;


int main()
{
	int a[] = { 2, 5, 3, 6 };
	//Fraction a[] = {{1, 2}, {2, 3}, {3, 7}};
	//float a[] = { 1.6F, 8.6F, 9.9F, 2.3F };
	//string a[] = { "hello", "chao", "bonjour" };
	int n = sizeof(a) / sizeof(a[0]);
	sort(a, n, ascendingCompare);
	printArray(a, n);
	sort(a, n, descendingCompare);
	printArray(a, n);
	return 0;
}