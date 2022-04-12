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

void draw(const UIComponent& component, const int& color, const long& miniDelay)
{
	Point clone(component.anchor);
	jump(clone);
	if (color == -1)
		setTextColor(component.color);
	else
		setTextColor(color);
	for (const string& current : component.content)
	{
		for (int i = 0; i < current.length(); i++)
		{
			//Jump the next char
			clone.x += 1;
			//If not space -> drawing
			if (isspace(current[i]))
				jump(clone); //Jump to next if not a char
			else
				cout << current[i];
		}
		clone.y += 1;
		clone.x = component.anchor.x;
		jump(clone);
		if (miniDelay)
			this_thread::sleep_for(std::chrono::milliseconds(miniDelay));
	}
}

void draw(const string& path, const Point& offset, const int& color)
{
	UIComponent comp = loadComponent(path);
	if (offset.x != 0 && offset.y != 0)
		comp.anchor = offset;
	if (color != -1)
		comp.color = color;
	draw(comp);
}

vector<Point> getInsidePoints(const UIComponent& component)
{
	vector<Point> points;
	const Point& anchor = component.anchor;
	for (int r = 1; r < component.content.size() - 1; r++)
	{
		const string* current = &(component.content[r]);
		for (int c = 1; c < current->size() - 1; c++)
		{
			//Jump the next char
			char ch = (*current)[c];
			//If not space -> drawing
			if (!isspace(ch))
			{
				//Get the drawn point
				points.push_back(Point{ (short)(anchor.x + c), (short)(anchor.y + r) });
			}
		}
	}
	return points;
}

void drawArea(const Point& startAnchor, const Point& endAnchor, const int& color, const long& miniDelay)
{
	setTextColor(color);
	string line = getCharString(endAnchor.x - startAnchor.x + 1, '*');
	for (int r = 0; r < endAnchor.y - startAnchor.y + 1; r++)
	{
		jump(Point{ startAnchor.x, short(startAnchor.y + r) });
		cout << line;
		if (miniDelay)
			this_thread::sleep_for(std::chrono::milliseconds(miniDelay));
	}
}

void drawBound(const UIComponent& component, const int& offset, const int& color)
{
	vector<string> str = createRectangleContent(component.content, offset);
	UIComponent drawn = { str, component.anchor - Point {2, 2},  color };
	draw(drawn);
}

void drawSroll(const vector<UIComponent>& component, const long& delay)
{
	Point clone({ 0, 0 });
	jump(clone);
	const Point& firstAnchor = component[0].anchor;
	const int row = component[0].content.size();
	for (int r = firstAnchor.y; r < row + firstAnchor.y; r++)
	{
		clone.y = r;
		for (int c = 0; c < component.size(); c++)
		{
			const Point& anchor = component[c].anchor;
			const int exactIndex = r - anchor.y;
			if (r == 14)
				int a = 5;
			if (exactIndex < 0 || exactIndex >= component[c].content.size())
				continue;
			else
			{
				const string& current = component[c].content[exactIndex];
				clone.x = anchor.x;
				jump(clone);
				setTextColor(component[c].color);
				for (const char& ch : current)
				{
					//Jump the next char
					clone.x += 1;
					//If not space -> drawing
					if (isspace(ch))
						jump(clone); //Jump to next if not a char
					else
						cout << ch;
				}

			}
		}
		this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
}

void clearConsole()
{
	drawArea({ 0, 0 }, { 163, 50 }, WHITE_WHITE);
}
