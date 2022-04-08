#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#define NAMES "19127652"
#define NUM_FOOD_EACH_ROUND 4
#define SPEED_ECO 300
#define MAX_LEVEL 4
#include "ConsoleHandler.h"
#include "GetUserInput.h"
#include "Direction.h"
#include "Snake.h"
#include "Moving.h"
#include "Food.h"
#include <thread>
#include <stdio.h>
#include "KeyMapping.h"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

const Point drawScoreOffset = { 3, 7 };
const Point removeScoreStart = { 158, 8 };
const Point removeScoreEnd = { 163, 13 };
const Point removeLevelStart = { 155, 1 };
const Point removeLevelEnd = { 160, 6 };

const string boardPath = "resources/boards/board_level_";
const string guidePath = "resources/guides/guide_in_game.txt";
const string numberPath = "resources/numbers/number_";
const string pausePath = "resources/guides/pause_game.txt";

void startGame(int level, int score);
void gameProcessing(int level, int score, const Direction& lockDirection, const bool& isPaused, bool& isEnded);
void userGameInput(Direction& lock, bool& pause, bool& isEnded);

#endif