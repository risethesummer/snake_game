#include "Gate.h"

bool checkGate(const Snake& snake, const vector<Point>& obtacles, const Point& gate)//x, y
{
	for (Node* current = snake.head; current; current = current->next) 
	{
		if (current->position == gate) 
			return true;
	}
	for (const Point& o : obtacles)
		if (o == gate)
			return true;
	return false;
}

//---
//- -
Point* createAndDrawGate(const Snake& snake, const vector<Point>& obtacles, const Point& topLeft, const Point& bottomRight)
{
	srand(time(NULL));
	Point gate0, gate1, gate2, gate3, gate4, gate5;
		//, gate6, gate7, gate8;
	do 
	{
		gate0.x = (rand() % (bottomRight.x - topLeft.x - 3)) + topLeft.x + 2;
		gate0.y = (rand() % (bottomRight.y - topLeft.y - 3)) + topLeft.y + 2;
		gate1.x = gate0.x - 1;	gate1.y = gate0.y - 1;
		gate2.x = gate0.x;	gate2.y = gate0.y - 1;
		gate3.x = gate0.x + 1;	gate3.y = gate0.y - 1;
		gate4.x = gate0.x - 1;	gate4.y = gate0.y;
		gate5.x = gate0.x + 1;	gate5.y = gate0.y;
		//gate6.x = gate0.x - 1;	gate6.y = gate0.y + 1;
		//gate7.x = gate0.x;	gate7.y = gate0.y + 1;
		//gate8.x = gate0.x + 1;	gate8.y = gate0.y + 1;
	} while (checkGate(snake, obtacles, gate0) 
		|| checkGate(snake, obtacles, gate1) 
		|| checkGate(snake, obtacles, gate2)
		|| checkGate(snake, obtacles, gate3) 
		|| checkGate(snake, obtacles, gate4) 
		|| checkGate(snake, obtacles, gate5));
		 //&& checkGate(snake, gate6) && checkGate(snake, gate7) && checkGate(snake, gate8));
	
	print(gate1, 'O', RED_RED);
	print(gate2, 'O', RED_RED);
	print(gate3, 'O', RED_RED);
	print(gate4, 'O', RED_RED);
	print(gate5, 'O', RED_RED);
	
	return new Point(gate0);
}