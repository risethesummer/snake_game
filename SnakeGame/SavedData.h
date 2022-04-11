#include "Snake.h"
#include "Direction.h"
#include <iomanip>
#include <sstream>
#include "Mode.h"
#ifndef SAVED_DATA_H
#define SAVED_DATA_H
#define TIME_LENGTH 19
#define DEFAULT_LIVES 3

struct Data
{
	int level = 1, score = 0, lives = DEFAULT_LIVES;
	Mode mode = EASY;
	Direction lockDirection = RIGHT;
	Snake snake;
};

struct SavedData
{
	char date[TIME_LENGTH + 1];
	Data data;
};

void clearData(Data& data);
ofstream& operator<<(ofstream& stream, const SavedData& savedData);
ifstream& operator>>(ifstream& stream, SavedData& savedData);

#endif