#include "raylib.h"
#include "game.h"
#include <iostream>
using namespace std;

void game()
{
	SetExitKey(KEY_ESCAPE);

	Texture2D ship;
	ship = LoadTexture("../images/ship1.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		DrawTexture(ship, GetScreenWidth()/3 + 50, 700, WHITE);

		ClearBackground(BLACK);
		EndDrawing();
	}
}
