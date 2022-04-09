#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H
#include "Point.h"
#include <vector>
#include <iostream>
using namespace std;

//Store a UI component including in the shape and the coordinate
struct UIComponent
{
	//The shape of the component in form of a vector of strings
	vector<string> content;
	//The top left anchor
	Point anchor;
	//The displayed color (should use colors in Color.h)
	int color;
};

//Load a component from disk
UIComponent loadComponent(const string& path);

//Load a component from a stream
istream& operator>>(istream& stream, UIComponent& component);

#endif