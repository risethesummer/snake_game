#include "GetUserInput.h"

//
char getInput(const vector<int>& expexted)
{
	int temp;
	do
	{
		temp = toupper(_getch());
	} while (!isBelongToInputType(temp, expexted));
	return temp;
}

bool isBelongToInputType(const char& input, const vector<int>& type)
{
	for (const char& find : type)
		if (input == find)
			return true;
	return false;
}
