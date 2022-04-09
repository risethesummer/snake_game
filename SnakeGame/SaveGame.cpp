#include "SaveGame.h"

void saveGame(const int& level, const int& score, const int& lives, const Snake& snake, const Direction& lockDirection)
{
	ifstream stream;
	string path;
	Menu slots;
	slots.offset = 2;
	string savedTime;
	int savedLev, savedScore, savedLives;
	Point starAnchor = { 30, 15 };
	for (int i = 0; i < MAX_SHOW; i++)
	{
		path = "saves/save_slot_" + to_string(i) + ".txt";
		stream.open(path);
		if (stream.good())
		{
			getline(stream, savedTime);
			stream >> savedLev >> savedScore >> savedLives;
			slots.components.push_back({ {to_string(i) + ": " + savedTime, "Level = " + to_string(savedLev) + ", Score = " + to_string(savedScore) + ", Lives = " + to_string(savedLives)}, starAnchor, WHITE_RED });
		}
		else
			slots.components.push_back({ {to_string(i) + ": The slot has no data"}, starAnchor, WHITE_BLACK });
		stream.close();
		if (i == MAX_SHOW / 2)
		{
			starAnchor.y = 15;
			starAnchor.x += 40;
		}
		else
		{
			starAnchor.y += 4;
		}
	}
	slots.components.push_back({ {"Back to the game"}, starAnchor, WHITE_BLACK });

	draw("resources/menu/save/menu_save_title.txt");
	show(slots);
	int slot = interact(slots);

	if (slot == MAX_SHOW)
		return;

	ofstream savedStream("saves/save_slot_" + to_string(slot) + ".txt");

	tm newtime;
	time_t now = time(0);
	auto tm = localtime_s(&newtime, &now);
	savedStream << std::put_time(&newtime, "%d/%m/%Y %H:%M:%S") << '\n';
	savedStream << level << ' ' << score << ' ' << lives << ' ' << lockDirection << '\n';
	savedStream << count(snake) << '\n';
	for (Node* current = snake.head; current; current = current->next)
		savedStream << current->position << '\n';
}