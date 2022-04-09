#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

//Define the coordinate of a point on console screen
struct Point
{
	//x coordindate
	short x = 0;
	//y coordinate
	short y = 0;
};


//Load a point from a stream
istream& operator>>(istream& stream, Point& point);
ostream& operator<<(ostream& stream, Point& point);
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);
Point operator+(const Point& a, const Point& b);
Point operator-(const Point& a, const Point& b);
Point& operator+=(Point& a, const Point& b);
Point getUnitVector(const Point& a);

#endif