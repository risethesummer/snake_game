#include "ProcessDead.h"
//void ProcessDead() {
//	STATE = 0;
//	score = 0;
//	LIFE--;
//	if (LIFE == 0) {
//		PlaySound(TEXT("game_over.wav"), NULL, SND_ASYNC);
//		GotoXY(0, HEIGH_CONSOLE + 2);
//		printf("GAME OVER!!!!!!!!!!!");
//		cout << endl;
//		cout << "PRESS Y TO RESTART THE GAME, PRESS OTHER KEYS TO EXIT";
//	}
//	else 
//		StartGame();
//}
//
//void StartGame() {
//	system("cls");
//	ResetData(); // Khởi tạo dữ liệu gốc
//	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
//	display();
//	STATE = 1;
//}
//
//void ResetData() {
//	//Defaut values
//	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 1; FOOD_INDEX = 1, WIDTH_CONSOLE = 70,
//		HEIGH_CONSOLE = 20, SIZE_SNAKE = 1; COUNT = 0;
//
//	//Default snake values
//	snake[0] = { 10, 5 };
//	GenerateFood();//ham food cua Thuan
//}


bool ProcessDead(const vector<Point> snake, const Point& topLeftAnchor, const Point& bottomRightAnchor)
{
	return false;
}
