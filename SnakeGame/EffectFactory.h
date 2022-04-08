#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H
#include <vector>
#include "Snake.h"
#include "Point.h"
#include <windows.h>
#include <mmsystem.h>
using namespace std;

void deadEffect(const Snake& snake);
void passGateEffect(const Snake& snake);
//void winEffect();
//void lostEffect();

#endif
