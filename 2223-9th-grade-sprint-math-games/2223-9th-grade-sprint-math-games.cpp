#include "raylib.h"

int main() {

	InitWindow(GetScreenWidth(), GetScreenHeight(), "Open-minded project game");

	SetTargetFPS(60);
	
	Texture2D learn, test, about, minimize, fullscreen, close;
	learn = LoadTexture("../images/learn.png");
	test = LoadTexture("../images/test.png");
	about = LoadTexture("../images/about.png");
	minimize = LoadTexture("../images/minimize.png");
	fullscreen = LoadTexture("../images/fullscreen.png");
	close = LoadTexture("../images/close.png");

	while (!WindowShouldClose())
	{
		
		BeginDrawing();

		ClearBackground(BACKGOUND_COLOR);

		DrawTexture(learn, 50, 100, WHITE);
		DrawTexture(test, 550, 100, WHITE);
		DrawTexture(about, 1050, 100, WHITE);
		DrawTexture(minimize, 1630, 40, WHITE);
		DrawTexture(fullscreen, 1730, 40, WHITE);
		DrawTexture(close, 1830, 40, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

