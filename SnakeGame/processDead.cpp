#include "ProcessDead.h"


bool ProcessDead(const vector<Point> snake, const Point& topLeftAnchor, const Point& bottomRightAnchor)
{
	if ((snake[0].x > topLeftAnchor.x && snake[0].x < bottomRightAnchor.x) && (snake[0].y > topLeftAnchor.y && snake[0].y < bottomRightAnchor.y))
		return true;
	for (int i = 1; i < snake.size(); i++) {
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
			return true;
	}
	return false;
}