#ifndef MODE_H
#define MODE_H
#include <string>

enum Mode
{
	EASY, NORMAL, HARD
};

std::string modeToString(const Mode& mode);

#endif