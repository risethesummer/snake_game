#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H
#include <vector>
#include "Point.h"
#include <iostream>
using namespace std;

//Get the index of the longest string in the vector
int getMaxLength(const vector<string>& strs);

//Get a string including in the character
string getCharString(const int& size, const char& ch);

//Get a vector shaping a rectangle bounding the object in form of vector of strings
vector<string> createRectangleContent(const vector<string>& content, const int& offset);

#endif