#include "raylib.h"
#include "game.h"
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <cstring>
using namespace std;

int numbers[50];

int decToBin(int n)
{
	int numbers[100];
	int i = 0;
	while (n > 0) {

		numbers[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		return numbers[j];
}
void game()
{
	SetExitKey(KEY_ESCAPE);

	Texture2D ship, asteroid_1, task_board;
	ship = LoadTexture("../images/ship1.png");
	task_board = LoadTexture("../images/task_board.png");
	asteroid_1 = LoadTexture("../images/asteroid_model_1.png");
	Vector2 ballPosition = { -100.0f, -100.0f };
	int num, numm, operation, num1[50], num2[50];
	string strr;
	random_device(rd);
	uniform_int_distribution <int> distNumber(0, 15);
	uniform_int_distribution <int> distOperation(0, 5);
	operation = distOperation(rd);
		num = distNumber(rd);
		numm = distNumber(rd);

	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();
		DrawFPS(50, 50);

		DrawTexture(ship, GetScreenWidth() / 3 + 90, 700, WHITE);
		DrawTexture(task_board, GetScreenWidth() / 3 + 20, -150, WHITE);
		/*DrawTexture(asteroid_1, 1000, 100, WHITE);*/
		DrawCircleV(ballPosition, 10, MAROON);
		
		num1[40] = decToBin(num);
		num2[40] = decToBin(numm);
		switch (operation)
		{
			case 0: strr ="&"; break;
			case 1: strr = "|"; break;
			case 2: strr = "^"; break;
			case 3: strr = "~"; break;
			case 4: strr = "<<"; break;
			case 5: strr = ">>"; break;
		
		}
		for (int i = 0; i < 5; i++)
		{
			string task = to_string(num1[i]); 
			const char* str = task.c_str();
			string task_operation = to_string(operation);
			const char* str2 = task_operation.c_str();
			string task2 = to_string(num2[i]);
			const char* str3 = task2.c_str();

			DrawText(str, 850, 50, 30, GREEN);
			DrawText(str, 875, 50, 30, GREEN);
			DrawText(str, 900, 50, 30, GREEN);
		}
		
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();
	}
}