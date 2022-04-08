#include "UIComponent.h"
#include <string>
#include <fstream>

UIComponent loadComponent(const string& path)
{
	ifstream stream(path);
	UIComponent component;
	if (stream)
		stream >> component;
	return component;
}

istream& operator>>(istream& stream, UIComponent& component)
{

	stream >> component.anchor;
	stream >> component.color;
	//Ignore the endline character
	stream.ignore();
	string temp;
	while (getline(stream, temp))
		component.content.push_back(temp);
	return stream;
}
