#ifndef MENU_H
#define MENU_H
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

struct BorderMenu
{
	Menu choices;
	UIComponent title;
};

const UIComponent* getCurrentShow(const Menu& menu);
Menu loadMenu(const vector<string>& paths);
BorderMenu loadMenu(const string& titlePath, const vector<string>& paths);
void show(const BorderMenu& menu);
void show(const Menu& menu);
void showNotInteract(const Menu& menu);
void showNotInteract(const Menu& menu, const int& delay);
void hide(const Menu& menu);
int interact(Menu& menu);
void switchComponent(Menu& menu, const int& off);

#endif