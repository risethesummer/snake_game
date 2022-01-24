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

/**
 * Set the text color of the console.
 * @param color Color value (should use colors in the Color.h).
 */
void setTextColor(const int& color);

/**
 * Print a text at a point.
 * @param point Starting point of the text.
 * @param content Content of the text.
 */
template <class T>
void print(const Point& point, const T& content)
{
	jump(point);
	std::cout << content;
}

/**
 * Print a text with a color at a point.
 * @param point Starting point of the text.
 * @param content Content of the text.
 * @param color Color of the text (should use colors in the Color.h).
 */
template <class T>
void print(const Point& point, const T& content, const int& color)
{
	setTextColor(color);
	print(point, content);
}

/**
 * Print a text with a color at a point, then recover the console text color.
 * @param point Starting point of the text.
 * @param content Content of the text.
 * @param color Color of the text (should use colors in the Color.h).
 * @param recoverColor Color used to set the console text color after printing the text.
 */
template <class T>
void print(const Point& point, const T& content, const int& color, const int& recoverColor)
{
	setTextColor(color);
	print(point, content);
	setTextColor(recoverColor);
}


/**
 * Draw an object at the top left anchor.
 * @param component The component drawn on the console screen
 */
void draw(const UIComponent& component);

/**
 * Draw an object at the top left anchor and get every coordinate of the object.
 * @param component The component drawn on the console screen
 * @return every coordinate which the object is drawn on
 */
vector<Point> drawAndGetPoints(const UIComponent& component);

/**
 * Draw an rectangle object starting at the top left anchor (used for deleting an area on screen)
 * @param startAnchor Top left anchor of the object.
 * @param endAnchor Bot right anchor of the object.
 * @param color Color of the object (should use colors in the Color.h).
 */
void drawArea(const Point& startAnchor, const Point& endAnchor, const int& color);

#endif