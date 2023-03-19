#include "raylib.h"
#include <iostream>
using namespace std;

void mainMenu()
{
	Texture2D mainMenu, startGame, rules, quitGame;
	mainMenu = LoadTexture("../images/mainMenu.png");
	startGame = LoadTexture("../images/start.png");
	rules = LoadTexture("../images/rules.png");
	quitGame = LoadTexture("../images/quitGame.png");
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawTexture(mainMenu, 50, 100, WHITE);
		DrawTexture(startGame, 770, 350, WHITE);
		DrawTexture(rules, 770, 475, WHITE);
		DrawTexture(quitGame, 775, 600, WHITE);


		EndDrawing();
	}
}

int main()
{

	InitWindow(GetScreenWidth(), GetScreenHeight(), "Open Minded - game project");

	SetTargetFPS(60);

	mainMenu();

}

