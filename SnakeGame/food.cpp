#include"food.h"


bool checkFood(const vector<Point>& snake, const Point& food)
{
	for (int i = 0; i < snake.size(); i++) {
		if (snake[i] == food)
			return true;
	}
	return false;
}

Point createFood(const vector<Point>& snake, const Point& topLeft, const Point& bottomRight)
{
	srand(time(NULL));
	Point food;
	do {
			
		food.x = rand() % (bottomRight.x - topLeft.x) + topLeft.x;
		food.y = rand() % (bottomRight.y - topLeft.y) + topLeft.y;
	} while (checkFood(snake, food));
	return food;
}

bool checkEatFood(const vector<Point>& snake, const Point& food)
{
	return snake[0] == food;
}
