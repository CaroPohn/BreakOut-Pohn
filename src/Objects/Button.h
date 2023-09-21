#pragma once

struct Button
{
	int texture;
	double x;
	double y;
	double width;
	double height;
};

void InitButton(Button& button, int texture, double x, double y, double width, double height);