#ifndef PROCESS_DEAD_H
#define PROCESS_DEAD_H
#include <vector>
#include "Point.h"
using namespace std;

//Determine the snake touches the wall or its body
//Head is the first element
//------------
//-			 -
//-			 -
//------------
bool ProcessDead(const vector<Point> snake, const Point& topLeftAnchor, const Point& bottomRightAnchor);

#endif