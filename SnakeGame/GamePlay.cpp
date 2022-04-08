#include "GamePlay.h"
mutex pauseGameMutex;


void gameProcessing(int level, int score, const vector<Point>& positions, const Direction& lockDirection, const bool& isPaused, bool& isEnded)
{
	bool isAlive = true;
	int speed = 1;
	Snake snake;

	if (positions.size() > 0)
	{
		Point middle = { 3, 23 };
		int len = 6 + (level - 1) * NUM_FOOD_EACH_ROUND + score;
		//Bat dau man (for loop)
		for (int i = 0; i < len; i++)
		{
			addHead(snake, middle);
			middle.x++;
		}
	}
	else
	{
		for (const Point& p : positions)
			addLast(snake, p);
	}

	draw(guidePath);
	draw(numberPath + to_string(level) + ".txt");
	draw(numberPath + to_string(score) + ".txt", { 3, 7 });

	for (level; level < MAX_LEVEL; level++)
	{
		UIComponent board = loadComponent(boardPath + to_string(level) + ".txt");
		Point* gate = nullptr;
		Point bottomRight = board.anchor + Point{ (short)(board.content[0].length() - 1), (short)(board.content.size() - 1) };
		vector<Point> obtacles = drawAndGetPoints(board);
		Point food = createFood(snake, obtacles, board.anchor, bottomRight);
		//Used for detecting death
		while (!isEnded)
		{
			if (isPaused)
			{
				pauseGameMutex.lock();
				pauseGameMutex.unlock();
			}

			//this_thread::sleep_for(std::chrono::milliseconds(10000));
			print(snake.tail->position, '*', WHITE_WHITE);
			moveSnake(snake, lockDirection);
			drawSnake(snake, NAMES, 8);

			if (gate)
			{
				if (snake.head->position == *gate)
				{
					passGateEffect(snake);
					drawArea(board.anchor, bottomRight, WHITE_WHITE, 10);
					delete gate;
					gate = nullptr;
					break;
				}
			}
			//Neu ma co cong -> check
			//An cong -> qua man
			//Xoa di tat ca
			//Chinh lai kich thuoc thanh 6
			//Tang toc do
			if (checkEatFood(snake, food))
			{
				if (score + 1 == NUM_FOOD_EACH_ROUND)
					gate = createAndDrawGate(snake, obtacles, board.anchor, bottomRight);
				else
				{
					score++;
					drawArea(removeScoreStart, removeScoreEnd, WHITE_WHITE);
					draw(numberPath + to_string(score) + ".txt", { 3, 7 });
					createFood(snake, obtacles, board.anchor, bottomRight);
				}
			}
			this_thread::sleep_for(std::chrono::milliseconds(SPEED_ECO / speed));
			//this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		freeSnake(snake);
	}
}

void startGame(int level, int score, const vector<Point>& positions, const Direction& lockDirection)
{
	Direction direction = lockDirection;
	bool isEnded = false;
	bool isPause = false;
	thread gameThread(gameProcessing, level, score, cref(positions),cref(direction), cref(isPause), ref(isEnded)); //Create thread for snake
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