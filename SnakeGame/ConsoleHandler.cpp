#include "ConsoleHandler.h"
#include "StringUtilities.h"

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

/*
template <class T>
void print(const Point& point, T content)
{
	jump(point);
	std::cout << content;
}

template <class T>
void print(const Point& point, T content, const int& color)
{
	setTextColor(color);
	print(point, content);
}

template <class T>
void print(const Point& point, T content, const int& color, const int& recoverColor)
{
	setTextColor(color);
	print(point, content);
	setTextColor(recoverColor);
}
*/

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

void drawArea(const Point& startAnchor, const Point& endAnchor, const int& color)
{
	setTextColor(color);
	string line = GetCharString(endAnchor.x - startAnchor.x + 4, '*');
	for (int r = 0; r < endAnchor.y - startAnchor.y + 2; r++)
	{
		jump(Point{ short(startAnchor.x - 1), short(startAnchor.y + r - 1) });
		cout << line;
	}
}