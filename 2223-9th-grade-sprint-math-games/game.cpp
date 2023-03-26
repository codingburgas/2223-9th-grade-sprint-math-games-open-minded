#include "raylib.h"
#include "game.h"
#include <iostream>
using namespace std;

void game()
{
	SetExitKey(KEY_ESCAPE);

	Texture2D ship, meteor,background;
	meteor = LoadTexture("../images/asteroid_model.png");
	ship = LoadTexture("../images/ship1.png");
	background = LoadTexture("../images/gameBackground.png");
	Vector2 ballPosition = { -100.0f, -100.0f };
	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();
		DrawFPS(50, 50);

		DrawTexture(background, 600, 300, WHITE);
		DrawTexture(meteor, 600, 300, WHITE);
		DrawTexture(ship, GetScreenWidth() / 3 + 90, 700, WHITE);
		DrawText("Tedo e qk", 15, 320, 15, RED);
		DrawCircleV(ballPosition, 10, MAROON);
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();


	}
}