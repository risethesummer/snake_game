#include "Snake.h"

Node* getNode(const Point& p)
{
	Node* newNode = new Node;
	newNode->position = p;
	return newNode;
}

bool isEmpty(Snake& snake)
{
	return !snake.head || !snake.tail;
}

void addHead(Snake& snake, const Point& pos)
{
	Node* addNode = getNode(pos);
	if (isEmpty(snake))
		snake.head = snake.tail = addNode;
	else
	{
		addNode->next = snake.head;
		snake.head->previous = addNode;
		snake.head = addNode;
	}
}

void addLast(Snake& snake, const Point& pos)
{
	Node* addNode = getNode(pos);
	if (isEmpty(snake))
		snake.head = snake.tail = addNode;
	else
	{
		snake.tail->next = addNode;
		addNode->previous = snake.tail;
		snake.tail = addNode;
	}
}

void removeLast(Snake& snake)
{
	if (!isEmpty(snake))
	{
		Node* beforeLast = snake.tail->previous;
		delete snake.tail;
		beforeLast->next = nullptr;
		snake.tail = beforeLast;
	}
}

void freeSnake(Snake& snake)
{
	Node* temp = snake.head;
	while (temp)
	{
		snake.head = snake.head->next;
		delete temp;
		temp = snake.head;
	}
}

int count(const Snake& snake)
{
	int c = 0;
	for (Node* current = snake.head; current; current = current->next)
		c++;
	return c;
}

void drawSnake(const Snake& snake, const char names[], const int& namesSize, const int& color)
{
	int i = 0;
	for (Node* current = snake.head; current; current = current->next, i++)
		print(current->position, names[i % namesSize], color);
}