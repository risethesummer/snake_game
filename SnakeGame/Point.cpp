#include "Point.h"

istream& operator>>(istream& stream, Point& point)
{
	stream >> point.x >> point.y;
	return stream;
}

ostream& operator<<(ostream& stream, Point& point)
{
	stream << point.x << ' ' << point.y;
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

Point operator+(const Point& a, const Point& b)
{
	Point res = { a.x + b.x, a.y + b.y };
	return res;
}

Point operator-(const Point& a, const Point& b)
{
	Point res = { a.x - b.x, a.y - b.y };
	return res;
}

Point& operator+=(Point& a, const Point& b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

Point getUnitVector(const Point& a)
{
	Point res;
	if (a.x != 0)
		res.x = a.x > 0 ? 1 : -1;
	else
		res.y = a.y > 0 ? 1 : -1;
	return res;
}
