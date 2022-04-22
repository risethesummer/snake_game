#include "Direction.h"


void inputToDirection(const char& input, Direction& lock)
{
	switch (input)
	{
	case ARROW_UP:
	case 'W':
		if (lock == LEFT || lock == RIGHT)
			lock = UP;
		return;
	case ARROW_DOWN:
	case 'S':
		if (lock == LEFT || lock == RIGHT)
			lock = DOWN;
		return;
	case ARROW_LEFT:
	case 'A':
		if (lock == UP || lock == DOWN)
			lock = LEFT;
		return;
	case ARROW_RIGHT:
	case 'D':
		if (lock == UP || lock == DOWN)
			lock = RIGHT;
		return;
	}
}
