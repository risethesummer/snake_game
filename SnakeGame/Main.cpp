#include "ConsoleHandler.h"


void mainTest();

int main()
{
	mainTest();
	return 1;
}

void mainTest()
{
	UIComponent* board = loadComponent("board_level_1.txt");
	fixConsoleWindow();
	draw(*board);
	Point a = { 20, 20 };
	print(a, "19127652", WHITE_RED);
	delete board;
}