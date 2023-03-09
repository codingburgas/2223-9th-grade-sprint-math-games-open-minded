#include "raylib.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Open-minded project game");

	SetTargetFPS(60);
	
	while (!WindowShouldClose())
	{

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		DrawText("First steps in raylib", 190, 200, 20, ORANGE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

