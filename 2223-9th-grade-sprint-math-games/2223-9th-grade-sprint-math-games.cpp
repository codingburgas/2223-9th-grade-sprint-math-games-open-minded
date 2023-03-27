#include <iostream>
#include "raylib.h"
#include "game.h"
#include "rules.h"
using namespace std;

float HEIGHT, WIDTH;
int main()
{
	InitWindow(0, 0, "Open Minded - game project");
	ToggleFullscreen();

	SetTargetFPS(60);
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	Texture2D background, startGame, rules, quitGame;
	Vector2 mousePoint;
	Vector2 ballPosition = { -100.0f, -100.0f };
	bool exitGame = false;
	background = LoadTexture("../images/mainMenuBackground.png");
	startGame = LoadTexture("../images/start.png");
	rules = LoadTexture("../images/rules.png");
	quitGame = LoadTexture("../images/quitGame.png");
	Rectangle startGameButton = { 820, 350, startGame.width, startGame.height };
	Rectangle rulesButton = { 820, 475, rules.width, rules.height };
	Rectangle quitGameButton = { 820, 600, quitGame.width, quitGame.height };

	while (!exitGame)
	{
		mousePoint = GetMousePosition();
		ballPosition = GetMousePosition();
		BeginDrawing();
		DrawFPS(50, 50);

		ClearBackground(BLACK);

		DrawTexture(background, WIDTH / 38.4f, HEIGHT / 10.8f, WHITE);
		DrawTexture(startGame, 820, 350, WHITE);
		DrawTexture(rules, 818, 475, WHITE);
		DrawTexture(quitGame, 820, 600, WHITE);
		DrawCircleV(ballPosition, 10, MAROON);
		HideCursor();

		EndDrawing();

		SetExitKey(0);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, startGameButton))
			game();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, rulesButton))
			rulesFunction();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, quitGameButton))
			exitGame = true;

	}
}

