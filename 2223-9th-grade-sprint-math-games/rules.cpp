#include "raylib.h"
#include "rules.h"
#include <iostream>
using namespace std;

void rulesFunction()
{
	SetExitKey(KEY_ESCAPE);

	Vector2 ballPosition = { -100.0f, -100.0f };
	Vector2 mousePoint = { -100.0f, -100.0f };
	Texture2D exitToGame, exitToMenu;
	exitToGame = LoadTexture("../images/rulesToGame.png");
	exitToMenu = LoadTexture("../images/rulesToMenuButton.png");
	Rectangle exitRulesButton = { 1635, 925, exitToGame.width, exitToGame.height };
	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();
		mousePoint = GetMousePosition();

		BeginDrawing();
		DrawText("press ESC to go back", 75, 915, 20, LIME);
		DrawTexture(exitToGame, 1635, 925, WHITE);
		DrawRectangleLines(75, 85, 1580, 820, ORANGE);
		DrawCircleV(ballPosition, 10, MAROON);
		HideCursor();
		DrawFPS(75, 50);
		DrawText("The date is March 28, 2148, and the people of Earth live in", 100, 110, 50, BLUE);
		DrawText("peace and tranquility until an extraordinary piece of news", 100, 160, 50, BLUE);
		DrawText("appears on their phones and televisions. NASA announces", 100, 210, 50, BLUE);
		DrawText("that our planet will be hit by many asteroids. If they are", 100, 260, 50, BLUE);
		DrawText("not stopped before hitting Earth, our civilization will", 100, 310, 50, BLUE);
		DrawText("end. As Commander Bob, you will be in charge of a squad", 100, 360, 50, BLUE);
		DrawText("of some of the most highly skilled astronauts in the", 100, 410, 50, BLUE);
		DrawText("world. Your goal is to reach the biggest asteroid and", 100, 460, 50, BLUE);
		DrawText("eliminate it. As a result, you must destroy only those", 100, 510, 50, BLUE);
		DrawText("small asteroids which will collide with the Earth in order", 100, 560, 50, BLUE);
		DrawText("to destroy them.", 100, 610, 50, BLUE);
		DrawText("*hint*", 100, 700, 50, RED);
		DrawText("You will need to shoot a lot of shots at the giant asteroid", 100, 770, 50, ORANGE);
		DrawText("if you want it to be destroyed.", 100, 820, 50, ORANGE);
		ClearBackground(BLACK);
		EndDrawing();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, exitRulesButton))
			game();


	}

}