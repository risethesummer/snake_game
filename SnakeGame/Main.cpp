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
	//Used for detecting death
	vector<Point> ps = drawAndGetPoints(*board);
	print({ 20, 20 }, "19127652", WHITE_RED);
	delete board;
}