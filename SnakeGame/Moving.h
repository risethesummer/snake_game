#ifndef _MOVING_H_
#define _MOVING_H_
#define WIDTH_CONSOLE 20
#define HEIGH_CONSOLE 50
int SIZE_SNAKE = 6;
#include <iostream>
#include <vector>
#include "Point.h"
#include "Direction.h"
using namespace std;

// ----
//remove snake[len - 1] (GOi trong ConsoleHandler.h print(toa do, '*', WHITE_WHITE) de xoa)
//insert new snake[0] (print(toa do, number, color);

//Xoa cai duoi (trong vector). Goi ham de xoa trong console
//Ve dau moi (them phan tu trong vector). Goi ham console de ve dau moi
void MoveRight(vector<Point>&snake);
void MoveLeft(vector<Point>&snake);
void MoveDown(vector<Point>&snake);
void MoveUp(vector<Point>&snake);
void Move(vector<Point>& snake, Direction dir)
//void MoveRight();
//void MoveLeft();
//void MoveDown();
//void MoveUp();

#endif