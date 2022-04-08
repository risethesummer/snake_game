#ifndef MENU_H
#define MENU_H
#include "UIComponent.h"

struct Menu
{
	UIComponent* components;
	int count;
	int currentShow;
};

void show(const Menu& menu);
void hide(const Menu& menu);
int interact(Menu& menu);
void switchComponent(Menu& menu, const int& off);

#endif