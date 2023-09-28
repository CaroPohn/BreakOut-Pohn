#pragma once

struct Pad
{
	int texture;
	double x;
	double y;
	double width;
	double height;
	float speed;
	int lives;
	bool isAlive;
	bool playerWin;
};

void InitPad(Pad& player, double width, double height);
void MovePadRight(Pad& player);
void MovePadLeft(Pad& player);
void PadScreenCollision(Pad& player);
void DrawPad(Pad player);