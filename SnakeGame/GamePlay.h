#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#define NAMES "19127652-20127142-20127348-20127652"
#define NAME_LENGTH 35
#define NUM_FOOD_EACH_ROUND 4
#define SPEED_ECO 300
#define MAX_LEVEL 4
#define DEAULT_LENGTH 6
#define AUTO_SAVE_DELAY 5000
#include "ConsoleHandler.h"
#include "Gate.h"
#include "GetUserInput.h"
#include "EffectFactory.h"
#include "SaveGame.h"
#include "Direction.h"
#include "Snake.h"
#include "Moving.h"
#include "Food.h"
#include "ProcessDead.h"
#include <thread>
#include <stdio.h>
#include "KeyMapping.h"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

const Point drawWaitOffset = { 65, 20 };
const Point drawLivesOffset = { 158, 1 };
const Point drawScoreOffset = { 158, 7 };
const Point drawLevelOffset = { 158, 13 };
const Point defaultGeneratedSnakePoint = { 65, 2 };
const Direction defaultDirection = DOWN;

const string boardPath = "resources/boards/board_level_";
const string guidePath = "resources/guides/guide_in_game.txt";
const string numberPath = "resources/numbers/number_";
const string pausePath = "resources/guides/pause_game.txt";
const string statsPath = "resources/guides/stats_in_game.txt";

void startGame(Data& data);
void gameProcessing(Data& data, const bool& isPaused, bool& isEnded, bool& isSaved);
void userGameInput(Direction& lock, bool& pause, bool& isEnded, bool& isSaved);
void waitInGame(const UIComponent& board, Point* food, Point* gate, const int& time, const long& delay);
void showWaiting(const int& time, const long& delay);
void drawNumber(const int& number, const Point& offset);
void drawStats(const int& level, const int& score, const int& lives);
int getGeneratedLength(const int& level, const int& score);
void saveGameAsync(const Data& data, const bool& shouldSave);
//level score lives direction
//size of positions
//pos 0.x pos 0. y
//pos 1.x pos 1. y
//...
// Examples:
//1 2 1 1
//5
//1 1
//2 1
//3 1
//...

//<FILE NAME 1>: Level = <l>, Score = <s>, Lives = <lv>
//<FILE NAME 2>: Level = <l>, Score = <s>, Lives = <lv>


//level
//lives
//score
//positions
//direction
// 
// 
//menu, save game (linh), load game (LINH)

//report: 
// 1.
// algs: move, dead, create food, gate; 
// data structure: snake (2 ways linked list), wall and obstacles (vector points);  (TRIET)
// 2.
// flow: 2 flows (snake, inputs) -> stack (ve flow chart), sub-modules (functions call functions)); (DUONG)

//qua man, chet (mang: lives) (THUAN)

#endif