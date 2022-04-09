#include"food.h"


bool checkFood(const Snake& snake, const vector<Point>& obstacles, const Point& food)
{
	for (Node* current = snake.head; current; current = current->next) {
		if (current->position == food)
			return true;
	}
	for (const Point& o : obstacles)
		if (o == food)
			return true;
	return false;
}

Point* createFood(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight)
{
	srand(time(NULL));
	Point food;
	do {
			
		food.x = rand() % (bottomRight.x - topLeft.x - 1) + topLeft.x + 1;
		food.y = rand() % (bottomRight.y - topLeft.y - 1) + topLeft.y + 1;
	} while (checkFood(snake, obstacles, food));
	return new Point(food);
}

Point* createFoodAndDraw(const Snake& snake, const vector<Point>& obstacles, const Point& topLeft, const Point& bottomRight)
{
	Point* food = createFood(snake, obstacles, topLeft, bottomRight);
	print(*food, '*', RED_RED);
	return food;
}

bool checkEatFood(const Snake& snake, const Point& food)
{
	return snake.head->position == food;
}
