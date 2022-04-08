#ifndef SNAKE_H
#define SNAKE_H
#include "Point.h"
#include "ConsoleHandler.h"

struct Node
{
	Point position;
	Node* previous = nullptr;
	Node* next = nullptr;
};

struct Snake
{
	Node* head = nullptr;
	Node* tail = nullptr;
};

Node* getNode(const Point& p);
bool isEmpty(Snake& snake);
void addHead(Snake& snake, const Point& pos);
void addLast(Snake& snake, const Point& pos);
void removeLast(Snake& snake);
void freeSnake(Snake& snake);
int count(const Snake& snake);
void drawSnake(const Snake& snake, const char names[], const int& namesSize, const int& color = WHITE_GREEN);
//void clearSnake(const Snake& snake);

#endif