#ifndef _FOOD_H_
#define _FOOD_H_
#include<iostream>
#include "Point.h"
#include <vector>
#include<time.h>
using namespace std;

bool checkFood(const vector<Point>& snake, const Point& food);
Point createFood(const vector<Point>& snake, const Point& topLeft, const Point& bottomRight);
bool checkEatFood(const vector<Point>& snake, const Point& food);

#endif
