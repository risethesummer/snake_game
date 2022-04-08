#ifndef DIRECTION_H
#define DIRECTION_H
#include "KeyMapping.h"

enum Direction {
	LEFT, RIGHT, UP, DOWN
};

void inputToDirection(const char& input, Direction& lock);

#endif