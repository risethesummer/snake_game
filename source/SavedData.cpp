#include "SavedData.h"

void clearData(Data& data)
{
	data.level = 1;
	data.score = 0;
	data.lives = 3;
	data.lockDirection = RIGHT;
	data.mode = EASY;
	data.snake.head = data.snake.tail = nullptr;
}

ofstream& operator<<(ofstream& stream, const SavedData& savedData)
{
	size_t s = sizeof(int);

	const Data& data = savedData.data;
	stream.write(savedData.date, TIME_LENGTH);
	stream.write((char*)&data.level, s);
	stream.write((char*)&data.score, s);
	stream.write((char*)&data.lives, s);
	stream.write((char*)&data.mode, s);
	stream.write((char*)&data.lockDirection, s);
	stream << data.snake;
	return stream;
}

ifstream& operator>>(ifstream& stream, SavedData& savedData)
{
	size_t s = sizeof(int);

	Data& data = savedData.data;
	stream.read(savedData.date, TIME_LENGTH);
	savedData.date[TIME_LENGTH] = '\0';
	stream.read((char*)&data.level, s);
	stream.read((char*)&data.score, s);
	stream.read((char*)&data.lives, s);
	stream.read((char*)&data.mode, s);
	stream.read((char*)&data.lockDirection, s);
	stream >> data.snake;

	return stream;
}