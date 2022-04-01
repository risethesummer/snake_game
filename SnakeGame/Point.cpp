#include "Point.h"

istream& operator>>(istream& stream, Point& point)
{
	stream >> point.x >> point.y;
	return stream;
}

bool operator==(const Point& a, const Point& b)
{
	return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point& a, const Point& b)
{
	return !(a == b);
}
