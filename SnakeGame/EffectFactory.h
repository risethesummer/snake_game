#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H
#include <vector>
#include "Snake.h"
#include "Point.h"
#include <windows.h>
#include <mmsystem.h>
#include <mutex>
using namespace std;

void deadEffect(const Snake& snake, const char* names, const int& size);
void passGateEffect(const Snake& snake);
void winEffect();
void deadEffect();
void eatFoodEffect();
void selectFunctionEffect();
void switchFunctionEffect();
void pauseEffect();
void exitEffect();

#endif
