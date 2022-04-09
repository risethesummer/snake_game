#ifndef CONSOLE_HANDLER_H
#define CONSOLE_HANDLER_H
#include <Windows.h>
#include "UIComponent.h"
#include <vector>
#include "Color.h"
#include "Point.h"
#include <iostream>
using namespace std;

//Fix the console window to fit the game screen.
void fixConsoleWindow();

//Move the console cursor to the specified coordinate
void jump(const Point& coordinate);

//Set the text color of the console.
void setTextColor(const int& color);

//Print a text at a point.
template <class T>
void print(const Point& point, const T& content)
{
	jump(point);
	std::cout << content;
}

//Print a text with a color at a point.
template <class T>
void print(const Point& point, const T& content, const int& color)
{
	setTextColor(color);
	print(point, content);
}

//Print a text with a color at a point, then recover the console text color.
template <class T>
void print(const Point& point, const T& content, const int& color, const int& recoverColor)
{
	setTextColor(color);
	print(point, content);
	setTextColor(recoverColor);
}

//Draw an object at the top left anchor.
void draw(const UIComponent& component, const int& color = -1);
//Draw an object loaded from the path
void draw(const string& path, const Point& offset = { 0, 0 }, const int& color = -1);
//Draw an object at the top left anchor and get every coordinate of the object.
vector<Point> drawAndGetPoints(const UIComponent& component);
//Draw an rectangle object starting at the top left anchor (used for deleting an area on screen)
void drawArea(const Point& startAnchor, const Point& endAnchor, const int& color, const long& miliDelay = 0);
//Draw bound of an object
void drawBound(const UIComponent& component, const int& offset, const int& color = YELLOW_YELLOW);

#endif