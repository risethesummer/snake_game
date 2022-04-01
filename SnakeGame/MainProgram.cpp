#include "ConsoleHandler.h"
#include <vector>
#include "Direction.h"
#include "Snake.h"
#include "Moving.h"
#include "Food.h"
#include <thread>
#define NAMES "19127652"
using namespace std;


void startGame() {
	Direction lockDirection = DOWN;
	bool isAlive = true;
	bool isPause = false;
	int currentLevel = 0;
	int currentScore = 0;
	int speed = 1;
	Snake snake;
	Point middle = { 20, 20 };
	for (int i = 0; i < 8; i++)
	{
		addLast(snake, middle);
		middle.x++;
	}
	UIComponent* board = loadComponent("board_level_1.txt");
	Point bottomRight = board->anchor + Point{ (short)board->content[0].length(), (short)board->content.size() };
	Point food = createFood(snake, board->anchor, bottomRight);
	//Used for detecting death
	vector<Point> table = drawAndGetPoints(*board);

	while (isAlive)
	{
		print(snake.tail->position, '*', WHITE_WHITE, WHITE_BLACK);
		move(snake, lockDirection);
		drawSnake(snake, NAMES, 8);
		if (checkEatFood(snake, food))
		{
			currentScore++;
			createFood(snake, board->anchor, bottomRight);
		}

		Sleep(1000 / speed);
	}

	delete board;
	freeSnake(snake);
	system("cls");
}


int main()
{
	fixConsoleWindow();
	startGame();
	return 1;
}