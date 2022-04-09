#include "StringUtilities.h"

int getMaxLength(const vector<string>& strs)
{
	int cur = strs[0].length();
	for (int i = 1; i < strs.size(); i++)
	{
		if (strs[i].length() > cur)
			cur = strs[i].length();
	}
	return cur;
}

string getCharString(const int& size, const char& ch)
{
	string str;
	for (int i = 0; i < size; i++)
		str += ch;
	return str;
}

vector<string> createRectangleContent(const vector<string>& content, const int& offset = 2)
{
	int width = getMaxLength(content) + 2 * offset;
	int height = content.size() + 2 * offset;
	vector<string> recContent;
	recContent.resize(height);
	for (string& row : recContent)
		row.resize(width);
	for (int i = 0; i < height; i++)
	{
		//The first and the last line is filled fully
		if (i == 0 || i == height - 1)
		{
			for (char& ch : recContent[i])
				ch = '*';
		}
		else
		{
			string& temp = recContent[i];
			temp[0] = '*';
			temp[temp.length() - 1] = '*';
			for (int j = 1; j < temp.length() - 1; j++)
				temp[j] = ' ';
		}
	}

	return recContent;
}