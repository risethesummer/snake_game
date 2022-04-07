#ifndef GATE_H
#define GATE_H
#include "Point.h"
#include "Snake.h"

//---
//- -
Point createAndDrawGate(const Snake& snake, int topLeft, int bottomRight);
bool checkSnakePassGate(const Snake& snake);

#endif // GATE_H
