#include "raylib.h"
#include "game.h"
#include <iostream>
using namespace std;

void game()
{
	SetExitKey(KEY_ESCAPE);

	Texture2D ship;
	ship = LoadTexture("../images/ship1.png");
	Vector2 ballPosition = { -100.0f, -100.0f };

	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();
		DrawFPS(50, 50);

		DrawTexture(ship, GetScreenWidth() / 3 + 90, 700, WHITE);
		DrawCircleV(ballPosition, 10, MAROON);
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();
	}
}