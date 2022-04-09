#ifndef SAVE_GAME_H
#define SAVE_GAME_H
#include "Point.h"
#include <vector>
#include "Direction.h"
#include <fstream>
#include <iomanip>
#include "UIComponent.h"
#include "Menu.h"
#include "Snake.h"
#include <string>

void saveGame(const int& level, const int& score, const int& lives, const Snake& snake, const Direction& lockDirection);

#endif