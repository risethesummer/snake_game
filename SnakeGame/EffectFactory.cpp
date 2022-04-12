#pragma comment(lib, "winmm.lib")
#include "EffectFactory.h"
#include "Menu.h"
#include <chrono>

void deadEffect(const Snake& snake, const char* names, const int& size)
{
  //print(snake,'YOU ARE DEAD', RED_RED);
	PlaySound(TEXT("resources/sounds/deathSoundEffect.wav"), NULL, SND_ASYNC);
	for (int i = 240; i <= 253; i++)
	{
		drawSnake(snake, names, 8, i);
		this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	for (Node* current = snake.tail; current; current = current->previous)
	{
		print(current->position, '*', WHITE_WHITE);
		this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

void passGateEffect(const Snake& snake)
{
	PlaySound(TEXT("resources/sounds/passEffect.wav"), NULL, SND_ASYNC);
	for (Node* current = snake.tail; current; current = current->previous)
	{
		print(current->position, '*', WHITE_WHITE);
		this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

void winEffect()
{
	clearConsole();
	PlaySound(TEXT("resources/sounds/winSound.wav"), NULL, SND_ASYNC);
	Menu win = loadMenu({
		"resources/menu/result/result_win.txt",
		"resources/menu/result/result_win_green.txt",
		"resources/menu/result/result_win_more_green.txt",
		"resources/menu/result/result_win_red.txt" });
	//draw(win);
	drawSroll(win.components, 150);
	Menu back = loadMenu({
		"resources/menu/about/about_exit.txt" });
	back.components[0].anchor = { 60, 162 };
	show(back);
	interact(back);
	drawArea({ 0, 0 }, { 161, 165 }, WHITE_WHITE);
	//PlaySound(NULL, NULL, SND_ASYNC);
}

void deadEffect()
{
	draw("resources/menu/result/result_dead.txt");
	PlaySound(TEXT("resources/sounds/loseEffect.wav"), NULL, SND_SYNC);
}

void eatFoodEffect()
{
	PlaySound(TEXT("resources/sounds/eatEffect.wav"), NULL, SND_ASYNC);
}

void selectFunctionEffect()
{
	PlaySound(TEXT("resources/sounds/selectFunctionEffect.wav"), NULL, SND_ASYNC);
}

void switchFunctionEffect()
{
	PlaySound(TEXT("resources/sounds/switchMenuEffect.wav"), NULL, SND_ASYNC);
}

void pauseEffect()
{
	PlaySound(TEXT("resources/sounds/pauseEffect.wav"), NULL, SND_ASYNC);
}

void exitEffect()
{
	PlaySound(TEXT("resources/sounds/exitSound.wav"), NULL, SND_SYNC);
}