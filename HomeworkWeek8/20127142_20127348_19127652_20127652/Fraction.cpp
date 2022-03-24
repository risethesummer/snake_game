#include "Fraction.h"

ostream& operator<<(ostream& stream, const Fraction& f)
{
	stream << f.num;
	if (f.den != 1)
		stream << '/' << f.den;
	return stream;
}

istream& operator>>(istream& stream, Fraction& f)
{
	cout << "Nhap vao tu so: ";
	stream >> f.num;
	do
	{
		cout << "Nhap vao mau so: ";
		stream >> f.den;
		if (f.den == 0)
			cout << "Mau so khong the bang khong! Moi nhap lai\n";
	} while (f.den == 0);
	//Move the negative sign to the numerator
	if (f.den < 0)
	{
		f.num = -f.num;
		f.den = -f.den;
	}

	return stream;
}
