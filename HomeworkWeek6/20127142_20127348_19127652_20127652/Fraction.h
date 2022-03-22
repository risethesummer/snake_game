#ifndef FRACTION_H
#define FRACRTION_H
#include <iostream>
using namespace std;

struct Fraction
{
	int num, den;
};

bool operator>(const Fraction& a, const Fraction& b);
bool operator<(const Fraction& a, const Fraction& b);
ostream& operator<<(ostream& stream, const Fraction& f);

#endif
