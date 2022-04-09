#include "GamePlay.h"
mutex pauseGameMutex;
mutex saveGameMutex;


void gameProcessing(int level, int score, int lives, const vector<Point>& positions, const Direction& lockDirection, const bool& isPaused, bool& isEnded, bool& isSaved)
{
	Snake snake;
	if (positions.size() == 0)
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
	UIComponent pauseComp = loadComponent(pausePath);
	draw(numberPath + to_string(level) + ".txt");
	draw(numberPath + to_string(score) + ".txt", { 3, 7 });


	for (level; level < MAX_LEVEL; level++)
	{
		//Load the shape of the board
		UIComponent board = loadComponent(boardPath + to_string(level) + ".txt");
		//Get the bottom right anchor of the board
		Point bottomRight = board.anchor + Point{ (short)(board.content[0].length() - 1), (short)(board.content.size() - 1) };
		//Get the position of the obstacles in the board
		vector<Point> obstacles = drawAndGetPoints(board);

		Point* gate = nullptr;
		Point* food = nullptr;
		//If the initial score is enough for passing the level
		//Generate a gate instead of a food
		if (score == NUM_FOOD_EACH_ROUND)
			gate = createGateAndDraw(snake, obstacles, board.anchor, bottomRight);
		else //Generate a food
			food = createFoodAndDraw(snake, obstacles, board.anchor, bottomRight);

		bool isAlive = true;
		while (!isEnded)
		{
			if (isPaused)
			{
				draw(pauseComp, RED_RED);
				pauseGameMutex.lock();
				draw(pauseComp, YELLOW_YELLOW);
				this_thread::sleep_for(std::chrono::milliseconds(1000));
				pauseGameMutex.unlock();
			}

			if (isSaved)
			{
				drawArea(board.anchor + Point{ 1, 1 }, bottomRight - Point{ 1, 1 }, WHITE_WHITE, 50);
				saveGame(level, score, lives, snake, lockDirection);
				draw(board);
				if (food)
					print(*food, '*', RED_RED);
				if (gate)
					drawGate(*gate);
				this_thread::sleep_for(std::chrono::milliseconds(1000));
				saveGameMutex.unlock();
			}

			//Remove the tail of the snake from the screen because the tail is removed when the snake moves to the next point
			print(snake.tail->position, '*', WHITE_WHITE);
			//Move the next (move the knots to their new positions)
			moveSnake(snake, lockDirection);
			//Draw the snake with new positions
			drawSnake(snake, NAMES, 8);

			//If we currently have the gate -> check to pass the level
			if (gate && snake.head->position == *gate)
			{
				passGateEffect(snake);
				drawArea(board.anchor, bottomRight, WHITE_WHITE, 10);
				delete gate;
				gate = nullptr;
				break;
			}
			//If we currently have the food -> check to increase score
			if (food && checkEatFood(snake, *food))
			{
				delete food;
				//If we reach enough score to pass the level -> generate a gate instead of a food
				if (score + 1 == NUM_FOOD_EACH_ROUND)
				{
					gate = createGateAndDraw(snake, obstacles, board.anchor, bottomRight);
					food = nullptr;
				}
				//Generate food if we do not reach the threshold to pass level
				else
				{
					score++;
					//Remove old score from screen
					drawArea(removeScoreStart, removeScoreEnd, WHITE_WHITE);
					//Draw new score
					draw(numberPath + to_string(score) + ".txt", { 3, 7 });
					//Generate new food
					food = createFoodAndDraw(snake, obstacles, board.anchor, bottomRight);
				}
			}

			//Check if the snake has touch its head, the wall or the obstacles
			if (isDead(snake, board.anchor, bottomRight, obstacles))
			{
				isAlive = false;
				break;
			}

			//Wait for the next movement
			this_thread::sleep_for(std::chrono::milliseconds(SPEED_ECO / (score + 1)));
		}


		if (food)
			delete food;
		if (gate)
			delete gate;

		//Ended by collisons -> use lives
		if (!isAlive)
		{

		}

		//Forced to end by user (esc keyboard)
		if (!isEnded)
		{

		}

	}

	freeSnake(snake);
}

void startGame(const int& level, const int& score, const int& lives, const vector<Point>& positions, const Direction& lockDirection)
{
	Direction direction = lockDirection;
	bool isEnded = false;
	bool isPause = false;
	bool isSaved = false;
	thread gameThread(gameProcessing, level, score, cref(positions),cref(direction), cref(isPause), ref(isEnded)); //Create thread for snake
	HANDLE handleThread = gameThread.native_handle();
	userGameInput(direction, isPause, isEnded, isSaved);
	gameThread.join();
}

void userGameInput(Direction& lock, bool& pause, bool& isEnded, bool& isSaved)
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
			case TAB:
			{
				isSaved = true;
				saveGameMutex.lock();
				saveGameMutex.lock();
				break;
			}
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
				if (pause)
					pauseGameMutex.unlock();
			}
			}
		}
	}
}