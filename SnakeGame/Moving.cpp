#include "Moving.h"

Point getAddition(const Direction& dir)
{
	Point addition;
	switch (dir)
	{
	case UP:
		addition.y -= 1;
		break;
	case DOWN:
		addition.y += 1;
		break;
	case LEFT:
		addition.x -= 1;
		break;
	case RIGHT:
		addition.x += 1;
		break;
	default:
		break;
	}
	return addition;
}

void move(vector<Point>& snake, const Direction& dir)
{
	snake.pop_back();
	snake.insert(snake.begin(), snake[0] + getAddition(dir));
}