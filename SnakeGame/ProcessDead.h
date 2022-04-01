#ifndef PROCESS_DEAD_H
#define PROCESS_DEAD_H
#include <vector>
#include "Point.h"
using namespace std;

bool isTouchWall(const vector<Point>& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor);
bool isSelfBite(const vector<Point>& snake);
bool isCollideWithObtacles(const vector<Point>& snake, const vector<vector<Point>>& obtacles);
bool isDead(const vector<Point>& snake, const Point& topLeftAnchor, const Point& bottomRightAnchor,
	const vector<vector<Point>>& obtacles);

#endif