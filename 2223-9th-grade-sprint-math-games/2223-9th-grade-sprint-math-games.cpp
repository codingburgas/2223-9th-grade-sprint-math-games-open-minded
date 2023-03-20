#include "raylib.h"
#include <iostream>
using namespace std;

void game()
{
	Texture2D tryout = LoadTexture("../images/Try.png");
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		DrawTexture(tryout, 50, 100, WHITE);
		EndDrawing();

	}
}
void rulesFunction()
{
	
}
void quitGameFunction()
{
	
}
void mainMenu()
{
	Texture2D background, startGame, rules, quitGame;
	Vector2 mousePoint;
	
	 
	background = LoadTexture("../images/mainMenuBackground.png");
	startGame = LoadTexture("../images/start.png");
	rules = LoadTexture("../images/rules.png");
	quitGame = LoadTexture("../images/quitGame.png");
	Rectangle startGameButton = { 770, 350, startGame.width, startGame.height - 80 };
	Rectangle rulesButton = { 770, 475, rules.width, rules.height - 80 };
	Rectangle quitGameButton = { 775, 600, quitGame.width, quitGame.height - 80 };
	while (!WindowShouldClose())
	{
		mousePoint = GetMousePosition();

		BeginDrawing();

		ClearBackground(BLACK);

		DrawTexture(background, 50, 100, WHITE);
		DrawTexture(startGame, 770, 350, WHITE);
		DrawTexture(rules, 770, 475, WHITE);
		DrawTexture(quitGame, 775, 600, WHITE);

		

		EndDrawing();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, startGameButton))
		{
			game();
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, rulesButton))
		{
			rulesFunction();
		}
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, quitGameButton))
		{
			quitGameFunction();
		}
		
	}
}

int main()
{

	InitWindow(GetScreenWidth(), GetScreenHeight(), "Open Minded - game project");

	SetTargetFPS(60);

	mainMenu();

}

