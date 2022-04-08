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
{
	char temp;
	vector<char>* keys = KeyMapping::GetMenuKeys();
	while (true)
	{
		temp = Input::GetInput(*keys);
		switch (temp)
		{
		case 'W':
		case ARROW_UP:
			SwitchComponent(-1);
			break;
		case 'S':
		case ARROW_DOWN:
			SwitchComponent(1);
			break;
		case 'E':
		case ENTER:
			return currentPos;
		}
	}
}

void InteractiveMenu::SwitchComponent(Menu& menu, const int& off)
{

	boundedComs[currentPos]->ClearBound();

	int newPos = currentPos + off;
	//Out of top
	if (newPos < 0)
		currentPos = boundedComs.size() - 1;
	//Out of bottom
	else if (newPos >= boundedComs.size())
		currentPos = 0;
	else
		currentPos = newPos;

	boundedComs[currentPos]->DrawBound();
}

#endif