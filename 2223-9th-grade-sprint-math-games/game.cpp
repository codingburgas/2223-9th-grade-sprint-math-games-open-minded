#include "raylib.h"
#include "game.h"
#include <iostream>
#include <random>
#include <string>
#include <chrono>
using namespace std;

int numbers[50];

void decToBin(int n)
{
	int numbers[100];
	int i = 0;
	while (n > 0) {

		numbers[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << numbers[j];
}
void game()
{
	SetExitKey(KEY_ESCAPE);

	Texture2D ship;
	ship = LoadTexture("../images/ship1.png");
	Vector2 ballPosition = { -100.0f, -100.0f };
	int num, operation;
	random_device(rd);
	uniform_int_distribution <int> distNumber(0, 15);
	uniform_int_distribution <int> distOperation(0, 5);


	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();
		DrawFPS(50, 50);

		DrawTexture(ship, GetScreenWidth() / 3 + 90, 700, WHITE);
		DrawCircleV(ballPosition, 10, MAROON);
		operation = distOperation(rd);
		num = distNumber(rd);
		for (int i = 0; i < 4; i++)
		{
			decToBin(num);
			string task = to_string(numbers[i]);
		}
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();
	}
}