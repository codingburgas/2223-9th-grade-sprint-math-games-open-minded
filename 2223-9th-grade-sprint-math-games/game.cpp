#include "raylib.h"
#include "game.h"
#include <iostream>
using namespace std;

void game()
{
	Texture2D tryout = LoadTexture("../images/Try.png");

	SetExitKey(KEY_ESCAPE);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		DrawTexture(tryout, 50, 100, WHITE);
		EndDrawing();
	}
}
