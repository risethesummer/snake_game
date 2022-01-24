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

/**
* Load a component from disk
* 
* @param path The path of the file storing the component
* @return the pointer pointing to the component object (null if could not load the file)
*/
UIComponent* loadComponent(const string& path);

/**
* Load a component from a stream
* @param stream The stream used to load
* @param component The component keeping the loaded data
* @param the stream used to load the component
*/
istream& operator>>(istream& stream, UIComponent& component);

#endif