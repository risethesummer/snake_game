#include "ConsoleHandler.h"
#include <vector>
#include "Direction.h"
#include "Snake.h"
#include "Moving.h"
#include "Food.h"
#include <thread>
#define NAMES "19127652"
#define NUM_FOOD_EACH_ROUND 4
using namespace std;


//User input (slide trang 12), pause, exit
//Gate (tao cong, check ran qua cong), chuyen man
//menu, save, load
//hieu ung (EffectFactory), ve man choi


//int level, int score, 
void startGame() {
	Direction lockDirection = DOWN;
	bool isAlive = true;
	bool isPause = false;
	int currentLevel = 0;
	int currentScore = 0;
	int speed = 1;
	Snake snake;
	Point middle = { 20, 20 };

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
	Point* food = &createFood(snake, board->anchor, bottomRight);
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

void pauseGame()
{

}

void exitGame()
{

}

void getUserInput()
{

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
	//Tao thread choi game
	//Terminate thread game -> back to menu
	startGame();
	return 1;
}