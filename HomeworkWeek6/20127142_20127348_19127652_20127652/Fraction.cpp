#include "Fraction.h"

bool operator>(const Fraction& a, const Fraction& b)
{
	return a.num * b.den - b.num * a.den > 0;
}

bool operator<(const Fraction& a, const Fraction& b)
{
	return a.num * b.den - b.num * a.den < 0;
}

ostream& operator<<(ostream& stream, const Fraction& f)
{
	stream << f.num;
	if (f.num != 0 && f.den != 1)
		stream << '/' << f.den;
	return stream;
}
