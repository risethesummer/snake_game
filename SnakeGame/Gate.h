#ifndef GATE_H
#define GATE_H
#include "Point.h"
#include "Snake.h"

//---
//- -
bool checkGate(const Snake& snake, const Point& gate);
Point createAndDrawGate(const Snake& snake, int topLeft, int bottomRight);

bool checkSnakePassGate(const Snake& snake);

#endif // GATE_H
