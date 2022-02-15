#include"food.h"
#include"gotoxy.h"



bool checkFood(int x, int y) {// kiểm tra đồ ăn có trùng với thân rắn
	for (int i = 0; i < SIZE_SNAKE; i++) {
		if (Snake[i].x == x && Snake[i].y == y) {
			return true;
		}
	}
	return false;
}

void createFood() {//tạo đồ ăn ngẫu nhiên
	srand(time(NULL));
	do {
		X_FOOD = rand() % (WIDTH_CONSOLE - 1) + 1;
		Y_FOOD = rand() % (HEIGH_CONSOLE - 1) + 1;
	} while (checkFood);
}

void drawFood() {//vẽ đồ ăn
	gotoxy(X_FOOD, Y_FOOD);
	cout << "0";
}

bool checkEatFood() {//kiểm tra rắn có ăn hay không. Có trả về true, không trả về false
	return (Snake[0].x == X_FOOD, Snake[0].y == Y_FOOD);
}

void processEat() {//sau khi ăn đồ ăn
	if (checkEatFood()) {
		//thêm đốt cho rắn
		SIZE_SNAKE++;
		//tăng tốc độ
		SPEED++;
		//tăng điểm

		//tạo lại đồ ăn mới
		createFood();
		drawFood();
	}
}