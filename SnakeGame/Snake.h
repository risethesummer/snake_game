#ifndef SNAKE_H
#define SNAKE_H
#include "Point.h"
#include "ConsoleHandler.h"
#include <fstream>
using namespace std;

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
void removeLast(Snake& snake, const int& keep);
void resetSnake(Snake& snake, const Point& start, const Point& offset = { 0, 1 });
int count(const Snake& snake);
void drawSnake(const Snake& snake, const char names[], const int& namesSize, const int& color = WHITE_GREEN);
ifstream& operator>>(ifstream& stream, Snake& snake);
ofstream& operator<<(ofstream& stream, const Snake& snake);
#endif