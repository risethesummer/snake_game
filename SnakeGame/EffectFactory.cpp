#pragma comment(lib, "winmm.lib")
#include "EffectFactory.h"
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