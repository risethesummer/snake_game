#ifndef GATE_H
#define GATE_H
#include "Point.h"
#include "Snake.h"

//---
//- -
bool checkGate(const Snake& snake, const vector<Point>& obtacles, const Point& gate);
Point* createAndDrawGate(const Snake& snake, const vector<Point>& obtacles, const Point& topLeft, const Point& bottomRight);
//.......
//.....
#endif // GATE_H
