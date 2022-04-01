#include"food.h"


bool checkFood(const Snake& snake, const Point& food)
{
	for (Node* current = snake.head; current; current = current->next) {
		if (current->position == food)
			return true;
	}
	return false;
}

Point createFood(const Snake& snake, const Point& topLeft, const Point& bottomRight)
{
	srand(time(NULL));
	Point food;
	do {
			
		food.x = rand() % (bottomRight.x - topLeft.x) + topLeft.x;
		food.y = rand() % (bottomRight.y - topLeft.y) + topLeft.y;
	} while (checkFood(snake, food));
	return food;
}

bool checkEatFood(const Snake& snake, const Point& food)
{
	return snake.head->position == food;
}
