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
};

void InitPad(Pad& player, double width, double height);
void DrawPad(Pad player);