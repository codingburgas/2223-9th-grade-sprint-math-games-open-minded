#include "raylib.h"
#include "game.h"
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <cstring>
using namespace std;

int numbers[50];

string decToBin(int n)
{
	string num = "";
	int d;
	if (n == 0)return "0";
	while (n)
	{
		d = n % 2;
		if (d)num = '1' + num;
		else num = '0' + num;
		n /= 2;
	}
	return num;
}

void fillString(string& a)
{
	for (int i = 0; i < 4 - a.size(); i++)
	{	
		a = '0' + a;
	}
}
string calculateResult(string num1, string num2, int op)
{
	string res;
	for (int i = 0; i < num1.size(); i++)
	{
		switch (op)
		{
		case 1:
			res[i] = (int)(num1[i] - '0') & (int)(num2[i] - '0'); break;
		case 2:
			res[i] = (int)(num1[i] - '0') | (int)(num2[i] - '0'); break;
		case 3:
			res[i] = (int)(num1[i] - '0') ^ (int)(num2[i] - '0'); break;
		case 4:
			res[i] = (int)(num1[i] - '0') << (int)(num2[i] - '0'); break;
		case 5:
			res[i] = (int)(num1[i] - '0') >> (int)(num2[i] - '0'); break;
		
		}
		return res;
	}
}
void game()
{
	SetExitKey(KEY_ESCAPE);

	Texture2D ship, asteroid_1, task_board;
	ship = LoadTexture("../images/ship1.png");
	task_board = LoadTexture("../images/task_board.png");
	asteroid_1 = LoadTexture("../images/asteroid_model_1.png");
	Vector2 ballPosition = { -100.0f, -100.0f };
	int num1, num2, operationTemp;
	string task1, task2, operation, res;
	num1 = GetRandomValue(0, 15);
	task1 = decToBin(num1);
	fillString(task1);
	num2 = GetRandomValue(0, 15);
	task2 = decToBin(num2);
	fillString(task2);
	
	operationTemp = GetRandomValue(1, 5);
	switch (operationTemp)
	{
	case 1: operation = '&'; break;
	case 2: operation = '|'; break;
	case 3: operation = '^'; break;
	case 4: operation = ">>"; break;
	case 5: operation = "<<"; break;
	}
	if (operationTemp == 4 || operationTemp == 5)
	{
		num1 = GetRandomValue(0, 5);
		task1 = to_string(num1);
		num2 = GetRandomValue(0, 5);
		task2 = to_string(num2);

	}
	res = calculateResult(task1, task2, operationTemp);
	

	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();
		DrawFPS(50, 50);

		DrawTexture(ship, GetScreenWidth() / 3 + 90, 700, WHITE);
		DrawTexture(task_board, GetScreenWidth() / 3 + 20, -150, WHITE);
		
		DrawCircleV(ballPosition, 10, MAROON);
		
	
		DrawText(TextFormat("%s %s %s", task1.c_str(), operation.c_str(), task2.c_str()), 900, 50, 36, GREEN);
		
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();
	}
}