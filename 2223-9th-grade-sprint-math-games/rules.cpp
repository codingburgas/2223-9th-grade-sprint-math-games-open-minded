#include "raylib.h"
#include "rules.h"
#include <iostream>
using namespace std;

void rulesFunction()
{
	SetExitKey(KEY_ESCAPE);

	Vector2 ballPosition = { -100.0f, -100.0f };

	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();

		DrawCircleV(ballPosition, 10, MAROON);
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();
	}

}
