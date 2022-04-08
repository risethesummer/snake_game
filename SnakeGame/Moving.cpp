#include "Moving.h"

Point getAddition(Direction dir)
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

void moveSnake(Snake& snake, Direction dir)
{
	removeLast(snake);
	addHead(snake, snake.head->position + getAddition(dir));
}
