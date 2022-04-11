#include "SaveGame.h"

void saveGame(Data& data)
{
	Menu slots = showSlots();
	int slot = AUTO_SLOT;
	do
	{
		slot = interact(slots);
	} while (slot == AUTO_SLOT);
	if (slot == MAX_SHOW)
		return;
	saveGameWithoutInteracting(data, slot);
}

void saveGameWithoutInteracting(Data& data, const int& slot)
{
	tm newtime;
	time_t now = time(0);
	auto tm = localtime_s(&newtime, &now);
	std::ostringstream oss;
	oss << std::put_time(&newtime, "%d/%m/%Y %H:%M:%S");
	string timeStr = oss.str();
	ofstream stream("saves/save_slot_" + to_string(slot) + ".dat");
	SavedData save;
	save.data = data;
	strcpy_s(save.date, TIME_LENGTH + 1, timeStr.c_str());
	stream << save;
}

Menu showSlots(const int& offsetX, const int& savedColor, const int& noColor)
{
	ifstream stream;
	Menu slots;
	slots.offset = 2;
	Point starAnchor = Point{ (short)(8 + offsetX), 10 };
	SavedData loaded;
	string title;
	for (int i = 0; i < MAX_SHOW; i++)
	{
		stream.open("saves/save_slot_" + to_string(i) + ".dat");
		title = i == AUTO_SLOT ? "Auto saved: " : to_string(i + 1);
		if (stream.good())
		{
			stream >> loaded;
			Data data = loaded.data;
			slots.components.push_back(
				UIComponent{
					{
						title + loaded.date,
						"Mode: " + modeToString(data.mode), 
						"Level = " + to_string(data.level) + ", Score = " + to_string(data.score) + ", Lives = " + to_string(data.lives)
					}, 
					starAnchor, 
					savedColor});
		}
		else
			slots.components.push_back({ {title + ": The slot has no data"}, starAnchor, noColor });
		stream.close();
		if ((i + 1) % MAX_SHOW_ROW == 0)
		{
			starAnchor.y = 10;
			starAnchor.x += 40;
		}
		else
		{
			starAnchor.y += 6;
		}
	}
	slots.components.push_back({ {"Back to the game"}, starAnchor, WHITE_BLACK });
	UIComponent saveTitles = loadComponent("resources/menu/save/menu_save_title.txt");
	saveTitles.anchor.x += offsetX;
	draw(saveTitles);
	show(slots);
	return slots;
}

bool loadGame(Data& data)
{
	Menu slots = showSlots(20, WHITE_GREEN, WHITE_RED);
	SavedData loaded;
	ifstream stream;
	while (true)
	{
		int slot = interact(slots);
		if (slot == MAX_SHOW)
			return false;
		stream.open("saves/save_slot_" + to_string(slot) + ".dat");
		if (stream.good())
		{
			stream >> loaded;
			data = loaded.data;
			break;
		}
	}
	return true;
}
