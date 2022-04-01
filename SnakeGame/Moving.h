#ifndef MOVING_H
#define MOVING_H
#include <iostream>
#include "Snake.h"
#include "Point.h"
#include "Direction.h"
#include "ConsoleHandler.h"
using namespace std;

Point getAddition(const Direction& dir);
void move(Snake& snake, const Direction& dir);

#endif