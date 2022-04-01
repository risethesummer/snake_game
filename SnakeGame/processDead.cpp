#include "ProcessDead.h"


bool isTouchWall(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor)
{
	Point& headPos = snake.head->position;
	return (headPos.x >= topLeftAnchor.x && headPos.x <= bottomRightAnchor.x) && (headPos.y >= topLeftAnchor.y && headPos.y <= bottomRightAnchor.y);

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

bool isCollideWithObtacles(const Snake& snake, const vector<vector<Point>>& obtacles)
{
	Point& headPos = snake.head->position;
	for (vector<Point> obtacle : obtacles)
	{
		for (Point p : obtacle)
		{
			if (p == headPos)
				return true;
		}
	}
	return false;
}

bool isDead(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor, const vector<vector<Point>>& obtacles)
{
	return isTouchWall(snake, topLeftAnchor, bottomRightAnchor)
		|| isSelfBite(snake)
		|| isCollideWithObtacles(snake, obtacles);
}