#include "ConsoleHandler.h"
#include "StringUtilities.h"
#include <mutex>

void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	//Show the program frame with the max size
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	//Hide the vertical scrollbar
	ShowScrollBar(consoleWindow, SB_VERT, FALSE);
	//Hide the maximize button
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	//https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
	//Hide the input cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info{ 100, false };
	SetConsoleCursorInfo(consoleHandle, &info);
	//Set the console to white color
	system("Color F0");
}

void jump(const Point& coordinate)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ coordinate.x, coordinate.y });
}


void setTextColor(const int& color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void draw(const UIComponent& component)
{
	Point clone(component.anchor);
	jump(clone);
	setTextColor(component.color);
	for (const string& current : component.content)
	{
		for (int i = 0; i < current.length(); i++)
		{
			//Jump the next char
			clone.x += 1;
			//If not space -> drawing
			if (!isspace(current[i]))
				cout << current[i];
			else
				jump(clone); //Jump to next if not a char
		}
		clone.y += 1;
		clone.x = component.anchor.x;
		jump(clone);
	}
}

void draw(const string& path, const Point& offset, const int& color)
{
	UIComponent comp = loadComponent(path);
	comp.anchor += offset;
	if (color != -1)
		comp.color = color;
	draw(comp);
}

vector<Point> drawAndGetPoints(const UIComponent& component)
{
	vector<Point> points;
	Point clone(component.anchor);
	jump(clone);
	setTextColor(component.color);
	for (int r = 0; r < component.content.size(); r++)
	{
		const string* current = &(component.content[r]);
		for (int c = 0; c < current->size(); c++)
		{
			//Jump the next char
			clone.x += 1;
			char ch = (*current)[c];
			//If not space -> drawing
			if (!isspace(ch))
			{
				cout << ch;
				if (r != 0 
					&& r != component.content.size() - 1 
					&& c!= 0 
					&& c != current->size() - 1)
					//Get the drawn point
					points.push_back(Point{ short(clone.x - 1), clone.y });
			}
			else
				jump(clone); //Jump to next if not a char
		}
		clone.y += 1;
		clone.x = component.anchor.x;
		jump(clone);
	}
	return points;
}

void drawArea(const Point& startAnchor, const Point& endAnchor, const int& color, const long& miniDelay)
{
	setTextColor(color);
	string line = GetCharString(endAnchor.x - startAnchor.x + 4, '*');
	for (int r = 0; r < endAnchor.y - startAnchor.y + 2; r++)
	{
		jump(Point{ short(startAnchor.x - 1), short(startAnchor.y + r - 1) });
		cout << line;
		if (miniDelay > 0)
			this_thread::sleep_for(std::chrono::milliseconds(miniDelay));
	}
}