#ifndef MOVING_H
#define MOVING_H
#include <iostream>
#include <vector>
#include "Point.h"
#include "Direction.h"
#include "ConsoleHandler.h"
using namespace std;

Point getAddition(const Direction& dir);
void move(vector<Point>& snake, const Direction& dir);

#endif