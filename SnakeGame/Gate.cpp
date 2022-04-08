#include "Gate.h"

bool checkGate(const Snake& snake, const Point& gate)
{
  for (Node* current = snake.head; current; current = current->next) {
		if (current->position == gate)
			return true;
	}
	return false;
}

Point createAndDrawGate(const Snake& snake, int topLeft, int bottomRight)
{
	srand(time(NULL));
	Point gate;
	do {
			
		gate.x = rand() % (bottomRight.x - topLeft.x) + topLeft.x;
		gate.y = rand() % (bottomRight.y - topLeft.y) + topLeft.y;
	} while (checkGate(snake, gate));
	//print(gate, '▄', RED_RED);
	return gate;
}
