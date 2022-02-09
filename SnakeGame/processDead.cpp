void ProcessDead() {
	STATE = 0;
	score = 0;
	LIFE--;
	if (LIFE == 0) {
		PlaySound(TEXT("game_over.wav"), NULL, SND_ASYNC);
		GotoXY(0, HEIGH_CONSOLE + 2);
		printf("GAME OVER!!!!!!!!!!!");
		cout << endl;
		cout << "PRESS Y TO RESTART THE GAME, PRESS OTHER KEYS TO EXIT";
	}
	else StartGame();
}