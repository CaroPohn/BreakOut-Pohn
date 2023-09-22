#pragma once

struct Pad
{
	int texture;
	double x;
	double y;
	double width;
	double height;
	int lives;
};

void InitPad(Pad& player, double width, double height);
void DrawPad(Pad player);