#ifndef SAVE_GAME_H
#define SAVE_GAME_H
#define MAX_SHOW 20
#define MAX_SHOW_ROW 7
#define AUTO_SLOT 19
#include "Point.h"
#include "Direction.h"
#include <fstream>
#include <iomanip>
#include "Menu.h"
#include "Snake.h"
#include "SavedData.h"
#include <string>

void saveGame(Data& data);
void saveGameWithoutInteracting(Data& data, const int& slot = AUTO_SLOT);
Menu showSlots(const int& offsetX = 0, const int& savedColor = WHITE_RED, const int& noColor = WHITE_GREEN);
bool loadGame(Data& data);

#endif