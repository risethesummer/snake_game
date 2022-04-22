#include "Menu.h"
#include <chrono>
#include <thread>
#include "EffectFactory.h"

const UIComponent* getCurrentShow(const Menu& menu)
{
	return &menu.components[menu.currentShow];
}

Menu loadMenu(const vector<string>& paths)
{
	Menu menu;
	for (const string& p : paths)
		menu.components.push_back(loadComponent(p));
	menu.currentShow = 0;
	return menu;
}

BorderMenu loadMenu(const string& titlePath, const vector<string>& paths)
{
	BorderMenu menu;
	menu.title = loadComponent(titlePath);
	menu.choices = loadMenu(paths);
	return menu;
}

void show(const BorderMenu& menu)
{
	draw(menu.title);
	show(menu.choices);
}

void show(const Menu& menu)
{
	showNotInteract(menu);
	drawBound(*getCurrentShow(menu), menu.offset);
}

void showNotInteract(const Menu& menu)
{
	for (UIComponent c : menu.components)
		draw(c);
}

void showNotInteract(const Menu& menu, const int& delay)
{
	for (UIComponent c : menu.components)
	{
		draw(c);
		this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void hide(const Menu& menu)
{
	for (UIComponent c : menu.components)
		draw(c, WHITE_WHITE);
	drawBound(*getCurrentShow(menu), WHITE_WHITE);
}

int interact(Menu& menu)
{
	char temp;
	while (true)
	{
		temp = getInput(menuInputs);
		switch (temp)
		{
		case 'W':
		case ARROW_UP:
			switchComponent(menu, -1);
			break;
		case 'S':
		case ARROW_DOWN:
			switchComponent(menu, 1);
			break;
		case 'E':
		case ENTER:
			selectFunctionEffect();
			return menu.currentShow;
		}
	}
	return 0;
}

void switchComponent(Menu& menu, const int& off)
{
	switchFunctionEffect();
	drawBound(*getCurrentShow(menu), menu.offset, WHITE_WHITE);
	int newPos = menu.currentShow + off;
	vector<UIComponent>* comps = &menu.components;
	//Out of top
	if (newPos < 0)
		menu.currentShow = comps->size() - 1;
	//Out of bottom
	else if (newPos >= comps->size())
		menu.currentShow = 0;
	else
		menu.currentShow = newPos;

	drawBound(*getCurrentShow(menu), menu.offset);
}