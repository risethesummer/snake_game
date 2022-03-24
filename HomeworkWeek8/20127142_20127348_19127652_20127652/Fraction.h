#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

struct Fraction
{
	int num, den;
};

ostream& operator<<(ostream& stream, const Fraction& f);
istream& operator>>(istream& stream, Fraction& f);

#endif // FRACTION_H
