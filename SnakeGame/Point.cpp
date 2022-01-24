#include "Point.h"

istream& operator>>(istream& stream, Point& point)
{
	stream >> point.x >> point.y;
	return stream;
}
