#include "Gate.h"

bool checkGate(const Snake& snake, const Point& gate)//x, y
{
  for (Node* current = snake.head; current; current = current->next) {
	Point gate;
	if (current->position == gate){
		return true;
	}
	return false;
}

Point createAndDrawGate(const Snake& snake, int topLeft, int bottomRight)
{
	srand(time(NULL));
	Point gate0, gate1, gate2, gate3, gate4, gate5, gate6, gate7, gate8;
	do {
			
		gate0.x = rand() % ((bottomRight.x - 2) - (topLeft.x - 2)) + topLeft.x - 2;
		gate0.y = rand() % ((bottomRight.y - 2) - (topLeft.y - 2)) + topLeft.y - 2;
		gate1.x = gate.x - 1;	gate1.y = gate.y - 1;
		gate2.x = gate.x;	gate2.y = gate.y - 1;
		gate3.x = gate.x + 1;	gate3.y = gate.y - 1;
		gate4.x = gate.x - 1;	gate4.y = gate.y;
		gate5.x = gate.x + 1;	gate5.y = gate.y;
		gate6.x = gate.x - 1;	gate6.y = gate.y + 1;
		gate7.x = gate.x;	gate7.y = gate.y + 1;
		gate8.x = gate.x + 1;	gate8.y = gate.y + 1;
	} while (checkGate(snake, gate0) && checkGate(snake, gate1) && checkGate(snake, gate2)
		 && checkGate(snake, gate3) && checkGate(snake,gate4) && checkGate(snake, gate5)
		 && checkGate(snake, gate6) && checkGate(snake, gate7) && checkGate(snake, gate8));
	
	
	
	print(gate1, 'O', RED_RED);
	print(gate2, 'O', RED_RED);
	print(gate3, 'O', RED_RED);
	print(gate4, 'O', RED_RED);
	print(gate5, 'O', RED_RED);
	
	return gate;
}
