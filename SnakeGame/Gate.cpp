#include "Gate.h"

void drawGate(const Point& centerPoint, const int& color)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (j != 0 || i == -1)
				print(centerPoint + Point{(short)j, (short)i}, '*', color);
		}
	}
}

bool checkGate(const Snake& snake, const vector<Point>& obstacles, const Point& gate)//x, y
{
	Point vectorDiff;
	for (Node* current = snake.head; current; current = current->next) 
	{
		vectorDiff = { (short)abs(current->position.x - gate.x),(short)abs(current->position.y - gate.y) };
		if (vectorDiff.x < 2 && vectorDiff.y < 2)
			return true;
	}

	Point inDoor = { gate.x, gate.y + 2 };
	for (const Point& o : obstacles)
	{
		vectorDiff = { (short)abs(o.x - gate.x),(short)abs(o.y - gate.y) };
		if ((vectorDiff.x < 2 && vectorDiff.y < 2) || inDoor == o)
			return true;
	}
	return false;
}

//---
//- -
Point* createGate(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight)
{
	srand(time(NULL));
	Point gate;
	do 
	{
		gate.x = (rand() % (bottomRight.x - topLeft.x - 3)) + topLeft.x + 2;
		gate.y = (rand() % (bottomRight.y - topLeft.y - 4)) + topLeft.y + 2;
	} while (checkGate(snake, obstacles, gate));
	return new Point(gate);
}

Point* createGateAndDraw(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight)
{
	Point* gate = createGate(snake, obstacles, topLeft, bottomRight);
	drawGate(*gate);
	return gate;
}
void removeGate(const Point& centerPoint)
{
	drawGate(centerPoint, WHITE_WHITE);
}
