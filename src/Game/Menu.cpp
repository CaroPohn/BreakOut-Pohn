#include "Menu.h"
#include "sl.h"
#include "Screen.h"

int backTexture;
int buttonTexture;

static Button playButton;
static Button rulesButton;
static Button creditsButton;
static Button exitButton;

void InitMenu()
{
	backTexture = slLoadTexture("../assets/menuback.png");
}

void InitMenuButtons(Button& playButton, Button& rulesButton, Button& creditsButton, Button& exitButton)
{
	buttonTexture = slLoadTexture("../assets/button.png");
	double 
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