void MoveRight() 
{
		if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE) {
				ProcessDead();
		}
	
		else {
				if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) {
						processEat();
				}
				for (int i = 0; i < SIZE_SNAKE - 1; i++) {
					snake[i].x = snake[i + 1].x;
					snake[i].y = snake[i + 1].y;
				}
			 snake[SIZE_SNAKE - 1].x++;
		}
}

 void MoveLeft() {
	 if (snake[SIZE_SNAKE - 1].x - 1 == 0) {
		 ProcessDead();
	 }
	 else {
		  if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y) 
		  {
			  processEat();
		  }
		  for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			  snake[i].x = snake[i + 1].x;
			  snake[i].y = snake[i + 1].y;
		 }
		  snake[SIZE_SNAKE - 1].x--;
	 }
 }
 
 void MoveDown() {
	 if (snake[SIZE_SNAKE - 1].y + 1 == HEIGH_CONSOLE) {
		 ProcessDead();
	 }
	 else {
		 if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y)
		 {
			 processEat()();
		 }
		 for (int i = 0; i < SIZE_SNAKE - 1; i++) {
			 snake[i].x = snake[i + 1].x;
			 snake[i].y = snake[i + 1].y;
		 }
		 snake[SIZE_SNAKE - 1].y++;
	 }
 }

 void MoveUp() 
 {
		  if (snake[SIZE_SNAKE - 1].y - 1 == 0) {
			  ProcessDead();
		  }
		  else {
			  if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
			  {
				  processEat();
			  }
			  for (int i = 0; i < SIZE_SNAKE - 1; i++) {
				  snake[i].x = snake[i + 1].x;
				  snake[i].y = snake[i + 1].y;
			  }
			  snake[SIZE_SNAKE - 1].y--;
		  }
 }
	 
	
