#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main()
{
	cout << "Input complex items\n"; 
	SoPhuc* B = soPhucArrIn(); 
	SoPhuc* x = (SoPhuc*)arrPopback((void**)&B);
	cout << "After pop: \n"; 
	soPhucArrOut(B); 
	cout << "Popped element : " << *x << endl;
	free(x); 
	arrFree(B);
}
