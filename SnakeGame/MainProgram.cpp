#include "GamePlay.h"
#include "EffectFactory.h"
#include "Menu.h"
#include "SaveGame.h"
using namespace std;


void playGame();

int main()
{
	//fixConsoleWindow();
	//Data d;
	//d.mode = EASY;
	//d.level = 3;
	//d.score = 4;
	//startGame(d);
	playGame();

	return 1;
}

void playGame()
{
	fixConsoleWindow();

	Menu firstMenu = loadMenu({
		"resources/menu/main/menu_snake_green.txt",
		"resources/menu/main/menu_snake_black.txt",
		"resources/menu/main/menu_snake_more_green.txt",
		"resources/menu/main/menu_snake_red.txt" });

	Menu functions = loadMenu({ 
		"resources/menu/main/menu_start.txt",
		"resources/menu/main/menu_load.txt",
		"resources/menu/main/menu_settings.txt",
		"resources/menu/main/menu_exit.txt" });

	BorderMenu modes = loadMenu("resources/menu/modes/mode_title.txt", {
		"resources/menu/modes/mode_easy.txt",
		"resources/menu/modes/mode_normal.txt",
		"resources/menu/modes/mode_hard.txt",
		"resources/menu/modes/mode_exit.txt"});

	Menu outro = loadMenu({
		"resources/menu/outro/outro_thanks.txt",
		"resources/menu/outro/outro_for.txt",
		"resources/menu/outro/outro_playing.txt"
		});

	BorderMenu about = loadMenu("resources/menu/about/about_title.txt", {"resources/menu/about/about_exit.txt"});
	Data data;
	int choice;
	while (true)
	{
		showNotInteract(firstMenu);
		show(functions);
		choice = interact(functions);
		switch (choice)
		{
		case 0:
		{
			clearData(data);
			drawArea({ 62, 1 }, { 120, 48 }, WHITE_WHITE);
			show(modes);
			int mode = interact(modes.choices);
			if (mode == 3)
			{
				drawArea({ 58, 1 }, { 120, 50 }, WHITE_WHITE);
				break;
			}
			data.mode = (Mode)mode;
			clearConsole();
			startGame(data);
			clearConsole();
			break;
		}
		case 1:
		{
			clearConsole();
			bool load = loadGame(data);
			clearConsole();
			if (load)
				startGame(data);
			clearConsole();
			break;
		}
		case 2:
		{
			clearConsole();
			show(about);
			interact(about.choices);
			clearConsole();
			break;
		}
		case 3:
		{
			thread exitSoundThread(exitEffect);
			drawArea({ 62, 3 }, { 120, 48 }, WHITE_WHITE);
			showNotInteract(outro, 1000);
			print({ 1, 48 }, '*', WHITE_WHITE);
			exitSoundThread.join();
			return;
		}
		}
	}
}