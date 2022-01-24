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


/**
* Load a point from a stream
* @param stream The stream used to load
* @param point The point keeping loaded data
* @param the stream used to load the point
*/
istream& operator>>(istream& stream, Point& point);

#endif