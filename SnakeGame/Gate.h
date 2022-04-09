#ifndef GATE_H
#define GATE_H
#include "Point.h"
#include "Snake.h"

void drawGate(const Point& centerPoint);
bool checkGate(const Snake& snake, const vector<Point>& obstacles, const Point& gate);
Point* createGate(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight);
Point* createGateAndDraw(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight);
#endif // GATE_H
