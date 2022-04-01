#ifndef EFFECT_FACTORY_H
#define EFFECT_FACTORY_H
#include <vector>
#include "Point.h"
using namespace std;

void deadEffect(const vector<Point>& snake);
void winEffect();
void lostEffect();

#endif
