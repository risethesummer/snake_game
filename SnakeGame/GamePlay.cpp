#include "GamePlay.h"
mutex pauseMutex;
mutex endMutex;
mutex saveMutex;
mutex saveGameMutex;
mutex pauseGameMutex;
condition_variable pauseCv;
condition_variable saveCv;


void gameProcessing(Data& data, const bool& isPaused, bool& isEnded, bool& isSaved)
{
	Snake& snake = data.snake;
	int& level = data.level, & score = data.score, & lives = data.lives;
	Mode& mode = data.mode;
	if (!snake.head)
	{
		Point middle = defaultGeneratedSnakePoint;
		int len = getGeneratedLength(level, score);
		//Bat dau man (for loop)
		for (int i = 0; i < len; i++)
		{
			addHead(snake, middle);
			middle.y++;
		}
		data.lockDirection = defaultDirection;
	}
	draw(guidePath);
	draw(statsPath);
	UIComponent pauseComp = loadComponent(pausePath);
	drawStats(level, score, lives);

	UIComponent board = loadComponent(boardPath + to_string(level) + ".txt");
	vector<Point> obstacles = getInsidePoints(board);
	draw(board, -1, 3);
	Point bottomRight = board.anchor + Point{ (short)(board.content[0].length() - 1), (short)(board.content.size() - 1)};
	for (level; level < MAX_LEVEL;)
	{
		Point* gate = nullptr;
		Point* food = nullptr;
		drawSnake(snake, NAMES, NAME_LENGTH);
		//If the initial score is enough for passing the level
		//Generate a gate instead of a food
		if (score == NUM_FOOD_EACH_ROUND)
		{
			while (true)
			{
				gate = createGateAndDraw(snake, obstacles, board.anchor, bottomRight);
			}
		}
		else //Generate a food
			food = createFoodAndDraw(snake, obstacles, board.anchor, bottomRight);
		waitInGame(board, food, gate, 3, 1000);
		while (true)
		{
			{
				std::lock_guard<mutex> lk(endMutex);
				if (isEnded)
					break;
			}

			{
				std::unique_lock<mutex> lk(pauseMutex);
				if (isPaused)
				{
					lk.unlock();
					draw(pauseComp, RED_RED);
					std::unique_lock<mutex> pauseLock(pauseGameMutex);
					//Wait for the pause is false
					pauseCv.wait(pauseLock, [&] {
							std::lock_guard<mutex> waitPauseLock(pauseMutex);
							return !isPaused;
						});
					draw(pauseComp, GRAY_GRAY);
					waitInGame(board, food, gate, 3, 1000);
				}
			}

			{
				std::lock_guard<mutex> lk(saveMutex);
				if (isSaved)
				{
					drawArea(board.anchor, bottomRight, WHITE_WHITE, 3);
					saveGame(data);
					drawArea(board.anchor, bottomRight, WHITE_WHITE);
					draw(board, -1, 3);
					drawSnake(snake, NAMES, NAME_LENGTH);
					if (food)
						print(*food, '*', RED_RED);
					if (gate)
						drawGate(*gate);
					waitInGame(board, food, gate, 3, 1000);
					isSaved = false;
					//Continue to accept inputs
					saveCv.notify_one();
				}
			}


			//Remove the tail of the snake from the screen because the tail is removed when the snake moves to the next point
			print(snake.tail->position, '*', WHITE_WHITE);
			//Move the next (move the knots to their new positions)
			moveSnake(snake, data.lockDirection);
			//Draw the snake with new positions
			drawSnake(snake, NAMES, NAME_LENGTH);

			//If we currently have the gate -> check to pass the level
			if (gate && snake.head->position == *gate)
			{
				delete gate;
				gate = nullptr;
				level++;
				if (level == MAX_LEVEL)
				{
					isEnded = true;
					winEffect();
					std::lock_guard<mutex> endLock(endMutex);
				}
				else
				{
					score = 0;
					lives = DEFAULT_LIVES;
					passGateEffect(snake);
					resetSnake(snake, defaultGeneratedSnakePoint);
					data.lockDirection = defaultDirection;
					drawArea(board.anchor, bottomRight, WHITE_WHITE);
					//load new board
					board = loadComponent(boardPath + to_string(level) + ".txt");
					bottomRight = board.anchor + Point{ (short)(board.content[0].length() - 1), (short)(board.content.size() - 1) };
					obstacles = getInsidePoints(board);
					draw(board, -1, 3);
					drawStats(level, score, lives);
				}
				break;
			}
			//If we currently have the food -> check to increase score
			if (food && checkEatFood(snake, *food))
			{
				delete food;
				score++;
				addLast(snake, snake.tail->position);
				eatFoodEffect();
				drawNumber(score, drawScoreOffset);
				//If we reach enough score to pass the level -> generate a gate instead of a food
				if (score == NUM_FOOD_EACH_ROUND)
				{
					gate = createGateAndDraw(snake, obstacles, board.anchor, bottomRight);
					food = nullptr;
				}
				//Generate food if we do not reach the threshold to pass level
				else
				{
					//Generate new food
					food = createFoodAndDraw(snake, obstacles, board.anchor, bottomRight);
				}
				continue;
			}

			//Check if the snake has touch its head, the wall or the obstacles
			if (isDead(snake, board.anchor, bottomRight, obstacles, gate))
			{
				deadEffect(snake, NAMES, NAME_LENGTH);
				//dead
				if (lives - 1 == 0)
				{
					score = 0;
					lives = DEFAULT_LIVES;
					drawNumber(score, drawScoreOffset);
					drawNumber(lives, drawLivesOffset);
					removeLast(snake, getGeneratedLength(level, score));
					resetSnake(snake, defaultGeneratedSnakePoint);
					data.lockDirection = defaultDirection;
					drawArea(board.anchor, bottomRight, WHITE_WHITE);
					deadEffect();
					drawArea(board.anchor, bottomRight, WHITE_WHITE);
					draw(board, -1, 3);
				}
				else //use lives
				{
					lives--;
					drawNumber(lives, drawLivesOffset);
					resetSnake(snake, defaultGeneratedSnakePoint);
					data.lockDirection = defaultDirection;
					drawSnake(snake, NAMES, NAME_LENGTH, WHITE_WHITE);
				}
				break;
			}

			//Wait for the next movement
			this_thread::sleep_for(std::chrono::milliseconds(SPEED_ECO / (level * (mode + 1))));
		}


		if (food)
		{
			print(*food, '*', WHITE_WHITE);
			delete food;
		}
		if (gate)
		{
			removeGate(*gate);
			delete gate;
		}

		//Forces to end by the user
		std::lock_guard<mutex> lk(endMutex);
		if (isEnded)
			break;
	}

	saveGameWithoutInteracting(data);
	freeSnake(snake);
}

void startGame(Data& data)
{
	bool isEnded = false;
	bool isPause = false;
	bool isSaved = false;
	thread gameThread(gameProcessing, ref(data), cref(isPause), ref(isEnded), ref(isSaved)); //Create thread for snake
	HANDLE handleThread = gameThread.native_handle();
	userGameInput(data.lockDirection, isPause, isEnded, isSaved);
	gameThread.join();
}

void userGameInput(Direction& lock, bool& pause, bool& isEnded, bool& isSaved)
{
	int temp;
	while (!isEnded)
	{
		temp = getInput(inGameInputs);
		if (isBelongToInputType(temp, moveInputs))
			inputToDirection(temp, lock);
		else
		{
			switch (temp)
			{
			case TAB:
			{
				{
					std::lock_guard<mutex> save(saveMutex);
					isSaved = true;
				}
				std::unique_lock<mutex> waitToEndSaving(saveGameMutex);
				saveCv.wait(waitToEndSaving, [&] { 
						return !isSaved; 
					});
				break;
			}
			case SPACE:
			{
				{
					std::lock_guard<mutex> pauseLock(pauseMutex);
					if (!pause)
						pause = true;
					else
					{
						pause = false;
						pauseCv.notify_one();
					}
				}
				break;
			}
			case ESC:
			{
				std::lock_guard<mutex> endLock(endMutex);
				isEnded = true;
			}
			}
		}
	}
}

void waitInGame(const UIComponent& board, Point* food, Point* gate, const int& time, const long& delay)
{
	showWaiting(time, delay);
	draw(board);
	if (food)
		print(*food, '*', RED_RED);
	if (gate)
		drawGate(*gate);
}

void showWaiting(const int& time, const long& delay)
{
	for (int i = time; i > 0; i--)
	{
		draw(numberPath + to_string(i) + ".txt", drawWaitOffset, RED_RED);
		this_thread::sleep_for(std::chrono::milliseconds(delay));
		drawArea(drawWaitOffset, drawWaitOffset + Point{ 5, 5 }, WHITE_WHITE);
	}
}

void drawStats(const int& level, const int& score, const int& lives)
{
	drawNumber(lives, drawLivesOffset);
	drawNumber(score, drawScoreOffset);
	drawNumber(level, drawLevelOffset);
}

void drawNumber(const int& number, const Point& offset)
{
	//Remove old number from screen
	drawArea(offset, offset + Point{ 5, 5 }, WHITE_WHITE);
	//Draw new score
	draw(numberPath + to_string(number) + ".txt", offset);
}

int getGeneratedLength(const int& level, const int& score)
{
	return DEAULT_LENGTH + (level - 1) * NUM_FOOD_EACH_ROUND + score;
}