#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H
#include <vector>
#include "Point.h"
#include <iostream>
using namespace std;

/**
* Get the index of the longest string in the vector
* @param strs the vector of strings
* @return the index of the longest string
*/
int GetMaxLength(const vector<string>& strs);

/**
* Get a string including in the character
* @param size the size of the string
* @param ch the appended character
* @return the string which each element is the character
*/
string GetCharString(const int& size, const char& ch);

/**
* Get a vector shaping a rectangle bounding the object in form of vector of strings
* @param content the text object in form of vector of strings
* @offset the top left anchor of the object
* @return the rectangle bounding the object
*/
vector<string> CreateRectangleContent(const vector<string>& content, const Point& offset);

#endif