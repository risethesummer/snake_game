#ifndef MOVING_H
#define MOVING_H
#include <iostream>
#include "Snake.h"
#include "Point.h"
#include "Direction.h"
#include "ConsoleHandler.h"
using namespace std;

Point getAddition(Direction dir);
void moveSnake(Snake& snake, Direction dir);

#endif