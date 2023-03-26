#include <iostream>
#include "raylib.h"
#include "game.h"
#include "rules.h"
using namespace std;

int main()
{
	InitWindow(GetScreenWidth(), GetScreenHeight(), "Open Minded - game project");

	SetTargetFPS(60);

	Texture2D background, startGame, rules, quitGame;
	Vector2 mousePoint;
	Vector2 ballPosition = { -100.0f, -100.0f };
	bool exitGame = false;
	background = LoadTexture("../images/mainMenuBackground.png");
	startGame = LoadTexture("../images/start.png");
	rules = LoadTexture("../images/rules.png");
	quitGame = LoadTexture("../images/quitGame.png");
	Rectangle startGameButton = { 820, 350, startGame.width - 110, startGame.height - 60 };
	Rectangle rulesButton = { 770, 475, rules.width - 110, rules.height - 60 };
	Rectangle quitGameButton = { 775, 600, quitGame.width - 110, quitGame.height - 60 };

	while (!exitGame)
	{
		mousePoint = GetMousePosition();
		ballPosition = GetMousePosition();
		BeginDrawing();
		DrawFPS(50, 50);

		ClearBackground(BLACK);

		DrawTexture(background, 50, 100, WHITE);
		DrawTexture(startGame, 770, 350, WHITE);
		DrawTexture(rules, 770, 475, WHITE);
		DrawTexture(quitGame, 775, 600, WHITE);
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

