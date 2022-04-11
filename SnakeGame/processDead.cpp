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

bool isDead(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor, const vector<Point>& obstacles, Point* gate)
{
	return isTouchWall(snake, topLeftAnchor, bottomRightAnchor)
		|| isSelfBite(snake)
		|| isCollideWithObstacles(snake, obstacles)
		|| (gate ? isCollideWithGate(snake, *gate) : false);
}

bool isCollideWithGate(const Snake& snake, const Point& centerPoint)
{
	Point vectorDiff;
	if (snake.head->position == Point{centerPoint.x, (short)(centerPoint.y + 1)})
		return false;
	for (Node* current = snake.head; current; current = current->next)
	{
		vectorDiff = { (short)abs(current->position.x - centerPoint.x),(short)abs(current->position.y - centerPoint.y) };
		if (vectorDiff.x < 2 && vectorDiff.y < 2)
			return true;
	}
	return false;
}
