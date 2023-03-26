#include "raylib.h"
#include "game.h"
#include <iostream>
using namespace std;

void game()
{
	SetExitKey(KEY_ESCAPE);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		EndDrawing();
	}
}
