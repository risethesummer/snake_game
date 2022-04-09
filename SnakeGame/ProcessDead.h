#ifndef PROCESS_DEAD_H
#define PROCESS_DEAD_H
#include <vector>
#include "Snake.h"
#include "Point.h"
using namespace std;

bool isTouchWall(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor);
bool isSelfBite(const Snake& snake);
bool isCollideWithObstacles(const Snake& snake, const vector<Point>& obstacles);
bool isDead(const Snake& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor,
	const vector<Point>& obstacles);

#endif