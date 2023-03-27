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
string randomTask(string& task1, string& task2, string& operation)
{
	task1 = decToBin(GetRandomValue(0, 15));
	task2 = decToBin(GetRandomValue(0, 15));

	fillString(task1);
	fillString(task2);

	int operationTemp = GetRandomValue(1, 5);
	switch (operationTemp)
	{
	case 1: operation = '&'; break;
	case 2: operation = '|'; break;
	case 3: operation = '^'; break;
	case 4: operation = ">>"; break;
	case 5: operation = "<<"; break;
	}
	if (operation == ">>" || operation == "<<")
	{

		task1 = to_string(GetRandomValue(1, 3));
		task2 = to_string(GetRandomValue(1, 3));

	}
	return calculateResult(task1, task2, operationTemp);
}


void game()
{
	SetExitKey(KEY_ESCAPE);
	int temp;
	string answer;
	answer = GetRandomValue(1, 5);
	switch (temp)
	{
	case 1: answer = to_string(1); break;
	case 2: answer = to_string(14); break;
	case 3: answer = to_string(15); break;
	case 4: answer = to_string(1011); break;
	}
	
	Texture2D ship, asteroid_1, task_board;
	ship = LoadTexture("../images/ship1.png");
	task_board = LoadTexture("../images/task_board_50.png");
	asteroid_1 = LoadTexture("../images/asteroid_model.png");
	Vector2 ballPosition = { -100.0f, -100.0f };

	string task1, task2, res, op;
	res = randomTask(task1, task2, op);

	Texture2D bg = LoadTexture("../images/bg.png");
	Rectangle bgRect[2] = { { 0, 0, bg.width, bg.height} , {0, -bg.height, bg.width, bg.height} };
	float speed = 5;

	while (!WindowShouldClose())
	{
		ballPosition = GetMousePosition();

		BeginDrawing();

		for (int i = 0; i < 2; i++)
		{
			bgRect[i].y += speed;
			if ((bgRect[i].y) >= GetScreenHeight())
				bgRect[i].y = -bg.height;

			DrawTexture(bg, bgRect[i].x, bgRect[i].y, WHITE);
		}
		DrawFPS(50, 50);

		DrawTexture(ship, GetScreenWidth() / 3 + 90, 700, WHITE);
		DrawTexture(task_board, GetScreenWidth() / 3 + 90, -30, WHITE);
		DrawTexture(asteroid_1, 1100, 300, WHITE);
		DrawText(TextFormat("%s", answer.c_str(), 20, 20, 50, WHITE));
		DrawTexture(asteroid_1, 1600, 700, WHITE);
		DrawTexture(asteroid_1, 300, 400, WHITE);
		DrawTexture(asteroid_1, 100, 750, WHITE);
		DrawTexture(asteroid_1, GetScreenWidth()/2 - 170, GetScreenHeight()/2, WHITE);
		DrawCircleV(ballPosition, 10, MAROON);


		DrawText(TextFormat("%s %s %s", task1.c_str(), op.c_str(), task2.c_str()), GetScreenWidth() / 2 -75, 80, 36, GREEN);
		
		HideCursor();
		ClearBackground(BLACK);
		EndDrawing();
	}
}
