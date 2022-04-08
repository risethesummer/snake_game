#include "GamePlay.h"
mutex pauseGameMutex;


void gameProcessing(int level, int score, const Direction& lockDirection, const bool& isPaused, bool& isEnded)
{
	bool isAlive = true;
	int speed = 1;
	Snake snake;
	Point middle = { 25, 20 };
	draw(guidePath);
	draw(numberPath + to_string(level) + ".txt");
	draw(numberPath + to_string(score) + ".txt", { 3, 7 });

	for (level; level < MAX_LEVEL; level++)
	{
		//Bat dau man (for loop)
		for (int i = 0; i < 8; i++)
		{
			addLast(snake, middle);
			middle.x--;
		}
		UIComponent board = loadComponent(boardPath + to_string(level) + ".txt");
		Point* gate = nullptr;
		Point bottomRight = board.anchor + Point{ (short)board.content[0].length(), (short)board.content.size() };
		vector<Point> obtacles = drawAndGetPoints(board);
		Point food = createFood(snake, obtacles, board.anchor, bottomRight);
		//Used for detecting death
		while (!isEnded)
		{
			print(snake.tail->position, '*', WHITE_WHITE);
			moveSnake(snake, lockDirection);
			drawSnake(snake, NAMES, 8);
			//Neu ma co cong -> check
			//An cong -> qua man
			//Xoa di tat ca
			//Chinh lai kich thuoc thanh 6
			//Tang toc do
			if (checkEatFood(snake, food))
			{
				if (++score == NUM_FOOD_EACH_ROUND)
				{

				}
				else
				{
					drawArea(removeScoreStart, removeScoreEnd, WHITE_WHITE);
					draw(numberPath + to_string(score) + ".txt", { 3, 7 });
					createFood(snake, obtacles, board.anchor, bottomRight);
				}
			}

			if (isPaused)
			{
				pauseGameMutex.lock();
				pauseGameMutex.unlock();
			}

			this_thread::sleep_for(std::chrono::milliseconds(SPEED_ECO / speed));
		}
		freeSnake(snake);
	}
}

void startGame(int level, int score)
{
	Direction direction = RIGHT;
	bool isEnded = false;
	bool isPause = false;
	thread gameThread(gameProcessing, level, score, cref(direction), cref(isPause), ref(isEnded)); //Create thread for snake
	HANDLE handleThread = gameThread.native_handle();
	userGameInput(direction, isPause, isEnded);
	gameThread.join();
}

void userGameInput(Direction& lock, bool& pause, bool& isEnded)
{
	int temp;
	while (true)
	{
		//inGameInputs
		temp = getInput(inGameInputs);
		if (isBelongToInputType(temp, moveInputs))
			inputToDirection(temp, lock);
		else
		{
			switch (temp)
			{
			case SPACE:
			{
				if (!pause)
				{
					pauseGameMutex.lock();
					pause = true;
				}
				else
				{
					pauseGameMutex.unlock();
					pause = false;
				}
				break;
			}
			case ESC:
			{
				isEnded = true;
				return;
			}
			}
		}
	}
}