#include "Menu.h"
#include "sl.h"
#include "Screen.h"

int backTexture;

void InitMenu()
{
	backTexture = slLoadTexture("../assets/menuback.png");
}

void InitMenuButtons()
{
	
}

void DrawMenu()
{
	slSprite(backTexture, GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight());
	slRectangleFill(GetScreenWidth() / 2, GetScreenHeight() / 2 + 50, 240, 90);
	slRectangleFill(GetScreenWidth() / 2, GetScreenHeight() / 2 - 60, 240, 90);
	slRectangleFill(GetScreenWidth() / 2, GetScreenHeight() / 2 - 170, 240, 90);
	slRectangleFill(GetScreenWidth() / 2, GetScreenHeight() / 2 - 280, 240, 90);
	slRender();
}