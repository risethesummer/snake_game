#ifndef SO_PHUC_H
#define SO_PHUC_H
#include <iostream>
#include "Array.h"
using namespace std;

struct SoPhuc
{
	int thuc = 0, ao = 0;
};

istream& operator>>(istream& stream, SoPhuc& sp);
ostream& operator<<(ostream& stream, const SoPhuc& sp);
SoPhuc* soPhucArrIn();
void soPhucArrOut(SoPhuc* data);

#endif
