#ifndef MENU_H
#define MENU_H
#define MAX_SHOW 15
#include "UIComponent.h"
#include "ConsoleHandler.h"
#include "KeyMapping.h"
#include "StringUtilities.h"
#include "GetUserInput.h"


struct Menu
{
	vector<UIComponent> components;
	int currentShow = 0;
	int offset = 2;
};

const UIComponent* getCurrentShow(const Menu& menu);
Menu loadMenu(const vector<string>& paths);
void show(const Menu& menu);
void showNotInteract(const Menu& menu);
void hide(const Menu& menu);
int interact(Menu& menu);
void switchComponent(Menu& menu, const int& off);

#endif