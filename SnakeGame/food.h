#ifndef _FOOD_H_
#define _FOOD_H_
#define WIDTH_CONSOLE 20
#define HEIGH_CONSOLE 50
int SIZE_SNAKE = 6;
int  X_FOOD = -1;
int  Y_FOOD = -1;
int SPEED = 3;
#endif

#include<iostream>
#include<time.h>
using namespace std;

struct Point {
	int x;
	int y;
};

Point Snake[20];
bool checkFood(int x, int y);
void createFood();
void drawFood();
bool checkEatFood();
void processEat();




