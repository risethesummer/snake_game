#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#define NAMES "19127652"
#define NUM_FOOD_EACH_ROUND 4
#define SPEED_ECO 300
#define MAX_LEVEL 4
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

const Point drawScoreOffset = { 3, 7 };
const Point removeScoreStart = { 158, 8 };
const Point removeScoreEnd = { 163, 13 };
const Point removeLevelStart = { 155, 1 };
const Point removeLevelEnd = { 160, 6 };

const string boardPath = "resources/boards/board_level_";
const string guidePath = "resources/guides/guide_in_game.txt";
const string numberPath = "resources/numbers/number_";
const string pausePath = "resources/guides/pause_game.txt";

void startGame(const int& level, const int& score, const int& lives, const vector<Point>& positions, const Direction& lockDirection);
void gameProcessing(int level, int score, int lives, const vector<Point>& positions, const Direction& lockDirection, const bool& isPaused, bool& isEnded, bool& isSaved);
void userGameInput(Direction& lock, bool& pause, bool& isEnded, bool& isSaved);
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

void loadGame();
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