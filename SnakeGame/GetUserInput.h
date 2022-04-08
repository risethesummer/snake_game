#ifndef GET_USER_INPUT_H
#define GET_USER_INPUT_H
#include "KeyMapping.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;
const vector<int> moveInputs = { ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, 'A', 'W', 'S', 'D' };
const vector<int> inGameInputs = { ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, 'A', 'W', 'S', 'D', SPACE, ESC };

//
char getInput(const vector<int>& expexted);
bool isBelongToInputType(const char& input, const vector<int>& type);

#endif