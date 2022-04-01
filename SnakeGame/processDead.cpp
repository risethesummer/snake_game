#include "ProcessDead.h"


bool isTouchWall(const vector<Point>& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor)
{
	return (snake[0].x >= topLeftAnchor.x && snake[0].x <= bottomRightAnchor.x) && (snake[0].y >= topLeftAnchor.y && snake[0].y <= bottomRightAnchor.y);

}

bool isSelfBite(const vector<Point>& snake)
{
	for (int i = 1; i < snake.size(); i++) {
		if (snake[0] == snake[i])
			return true;
	}
	return false;

}

bool isCollideWithObtacles(const vector<Point>& snake, const vector<vector<Point>>& obtacles)
{
	for (vector<Point> obtacle : obtacles)
	{
		for (Point p : obtacle)
		{
			if (p == snake[0])
				return true;
		}
	}
	return false;
}

bool isDead(const vector<Point>& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor, const vector<vector<Point>>& obtacles)
{
	return isTouchWall(snake, topLeftAnchor, bottomRightAnchor)
		|| isSelfBite(snake)
		|| isCollideWithObtacles(snake, obtacles);
}