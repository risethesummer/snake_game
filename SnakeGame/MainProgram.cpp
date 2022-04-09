#include "GamePlay.h"
#include "EffectFactory.h"
#include "Menu.h"
#include "SaveGame.h"
using namespace std;

//User input (slide trang 12), pause, exit
//Gate (tao cong, check ran qua cong), chuyen man
//menu, save, load
//hieu ung (EffectFactory), ve man choi

int main()
{
	fixConsoleWindow();
	//startGame(1, 0);
	//Snake n;
	//deadEffect(n);
	//passGateEffect(n);

	//Menu menu = loadMenu({ "resources/menu/menu_start.txt",
	//	"resources/menu/menu_load.txt",
	//	"resources/menu/menu_settings.txt",
	//	"resources/menu/menu_exit.txt" });
	//show(menu);

	//Menu firstMenu = loadMenu({
	//	"resources/menu/menu_snake_green.txt",
	//	"resources/menu/menu_snake_black.txt",
	//	"resources/menu/menu_snake_more_green.txt",
	//	"resources/menu/menu_snake_red.txt"});
	//showNotInteract(firstMenu);

	//int choice = interact(menu);

	//startGame(1, 1, {}, RIGHT);

	Snake s;
	saveGame(1, 1, 1, s, LEFT);

	return 0;
}