#include "ProcessDead.h"


bool isTouchWall(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor)
{
	Point& headPos = snake.head->position;
	return headPos.x <= topLeftAnchor.x || headPos.x >= bottomRightAnchor.x || headPos.y <= topLeftAnchor.y || headPos.y >= bottomRightAnchor.y;

}

bool isSelfBite(const Snake& snake)
{
	Point& headPos = snake.head->position;
	for (Node* current = snake.head->next; current; current = current->next) {
		if (current->position == headPos)
			return true;
	}
	return false;

}

bool isCollideWithObstacles(const Snake& snake, const vector<Point>& obstacles)
{
	Point& headPos = snake.head->position;
	for (Point o : obstacles)
	{
		if (o == headPos)
			return true;
	}
	return false;
}

bool isDead(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor, const vector<Point>& obstacles)
{
	return isTouchWall(snake, topLeftAnchor, bottomRightAnchor)
		|| isSelfBite(snake)
		|| isCollideWithObstacles(snake, obstacles);
}