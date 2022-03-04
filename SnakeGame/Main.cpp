#include "ConsoleHandler.h"
#include <vector>
#include "Direction.h"
using namespace std;

void mainTest();

void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	display();
	STATE = 1;
}

void ResetData();

int main()
{
	vector<Point> snake;
	Point food;
	vector<Point> table; //Dead
	int currentLevel = 0;
	bool isAlive = false;
	Direction lockDirection;

	//Draw board
	//Generate food
	//Generate snake
	//Thread chinh dung de nhan input
	//Tao thread de ve con ran
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