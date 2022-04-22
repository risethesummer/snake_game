#ifndef _FOOD_H_
#define _FOOD_H_
#include<iostream>
#include "Point.h"
#include <vector>
#include "Snake.h"
#include<time.h>
using namespace std;


bool checkFood(const Snake& snake, const vector<Point>& obstacles, const Point& food);
Point* createFood(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight);
Point* createFoodAndDraw(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight);
bool checkEatFood(const Snake& snake, const Point& food);

#endif
