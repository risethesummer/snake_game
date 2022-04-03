#include "ConsoleHandler.h"
#include <vector>
#include "Direction.h"
#include "Snake.h"
#include "Moving.h"
#include "Food.h"
#include <Windows.h>
#include <thread>
#include <string.h>
#define NAMES "19127652"
#define NUM_FOOD_EACH_ROUND 4
using namespace std;


//User input (slide trang 12), pause, exit
//Gate (tao cong, check ran qua cong), chuyen man
//menu, save, load
//hieu ung (EffectFactory), ve man choi

void pauseGame(HANDLE t)
{
	system("cls");
	TerminateThread(t, 0);
}

void exitGame(HANDLE t)
{
	SuspendThread(t);
}

void getUserInput(HANDLE t, Direction lock)
{
	
	int temp;
	while (1) {
		temp = toupper(getchar());
		if (temp == 'P')
			pauseGame(t);
		else if ((temp != 0) && (temp == UP || temp == RIGHT || temp == LEFT || temp == DOWN)) {
			if (temp == UP)
				lock = DOWN;
			else if (temp == DOWN)
				lock = UP;
			else if (temp = LEFT)
				lock = RIGHT;
			else lock = LEFT;
		}
		else {
			exitGame(t);
			return;
		}
	}
}
//int level, int score, 
void startGame() {
	Direction lockDirection;
	bool isAlive = true;
	bool isPause = false;
	int currentLevel = 0;
	int currentScore = 0;
	int speed = 1;
	Snake snake;
	Point middle = { 20, 20 };
	thread t1(move(snake, lockDirection));
	HANDLE handle_t1 = t1.native_handle();
	getUserInput(handle_t1, lockDirection);
	//Bat dau man (for loop)
	for (int i = 0; i < 8; i++)
	{
		addLast(snake, middle);
		middle.x++;
	}
	UIComponent* board = loadComponent("board_level_1.txt");
	Point* gate = nullptr;
	Point bottomRight = board->anchor + Point{ (short)board->content[0].length(), (short)board->content.size() };
	vector<Point> table = drawAndGetPoints(*board);
	Point food = createFood(snake, board->anchor, bottomRight);
	//Used for detecting death
	while (isAlive)
	{
		print(snake.tail->position, '*', WHITE_WHITE, WHITE_BLACK);
		move(snake, lockDirection);
		drawSnake(snake, NAMES, 8);
		//Neu ma co cong -> check
		//An cong -> qua man
		//Xoa di tat ca
		//Chinh lai kich thuoc thanh 6
		//Tang toc do
		if (checkEatFood(snake, food))
		{
			print(food, '*', WHITE_WHITE);
			currentScore++;
			createFood(snake, board->anchor, bottomRight);
		}

		Sleep(1000 / speed);
	}
	//Ket thuc man
	delete board;
	freeSnake(snake);
	system("cls");
}


void menu()
{

}


//Level
//Score
//Positions
//
void save()
{

}

void load()
{

}


int main()
{
	fixConsoleWindow();
	
	//Menu
	//Terminate thread game -> back to menu
	startGame();
	return 1;
}