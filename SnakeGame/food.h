#ifndef _FOOD_H_
#define _FOOD_H_
//#define WIDTH_CONSOLE 20
//#define HEIGH_CONSOLE 50
int SIZE_SNAKE = 6;
int  X_FOOD = -1;
int  Y_FOOD = -1;
int SPEED = 3;
#endif

#include<iostream>
#include <vector>
#include<time.h>
using namespace std;

struct Point {
	int x;
	int y;
};

Point Snake[20];
bool checkFood(int x, int y);
//Fix
bool checkFood(const vector<Point>& snake, const Point& food);
void createFood();
//Fix
Point createFood(const vector<Point>& snake, const Point& topLeft, const Point& bottomRight);
void drawFood();
//Fix
bool checkEatFood(const vector<Point>& snake, const Point& food);
void processEat();