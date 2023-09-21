#pragma once
#include "Game/Utilities.h"

struct Button
{
	int texture;
	double x;
	double y;
	double width;
	double height;
	bool isSelected;
};

void InitButton(Button& button, int texture, double x, double y, double width, double height);
void DrawButton(Button button);
bool CheckCollisionButtonMouse(int mouseX, int mouseY, Button button);
bool CheckMouseInput(Button button);