#include "Gate.h"

void drawGate(const Point& centerPoint)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j != 1 || i == 0)
				print(centerPoint + Point{(short)i, (short)j}, '*', GREEN_GREEN);
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
	for (const Point& o : obstacles)
	{
		vectorDiff = { (short)abs(o.x - gate.x),(short)abs(o.y - gate.y) };
		if (vectorDiff.x < 2 && vectorDiff.y < 2)
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
		gate.y = (rand() % (bottomRight.y - topLeft.y - 3)) + topLeft.y + 2;
		
	} while (checkGate(snake, obstacles, gate));
	return new Point(gate);
}

Point* createGateAndDraw(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight)
{
	Point* gate = createGate(snake, obstacles, topLeft, bottomRight);
	drawGate(*gate);
	return gate;
}
