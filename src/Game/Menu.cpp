#include "Menu.h"
#include "sl.h"
#include "Screen.h"

int backTexture;
int playButtonTexture;
int rulesButtonTexture;
int creditsButtonTexture;
int exitButtonTexture;

static Button playButton;
static Button rulesButton;
static Button creditsButton;
static Button exitButton;

void InitMenu()
{
	backTexture = slLoadTexture("../assets/menuback.png");
	InitMenuButtons(playButton, rulesButton, creditsButton, exitButton);
}

void InitMenuButtons(Button& playButton, Button& rulesButton, Button& creditsButton, Button& exitButton)
{
	playButtonTexture = slLoadTexture("../assets/playbutton.png");
	rulesButtonTexture = slLoadTexture("../assets/rulesbutton.png");
	creditsButtonTexture = slLoadTexture("../assets/creditsbutton.png");
	exitButtonTexture = slLoadTexture("../assets/exitbutton.png");
	const double buttonWidth = 250;
	const double buttonHeight = 110;
	double buttonXPos = GetScreenWidth() / 2;
	const double buttonDistance = buttonHeight + 20;

	double playButtonY = GetScreenHeight() / 2 + 50;
	double rulesButtonY = playButtonY - buttonDistance;
	double creditsButtonY = rulesButtonY - buttonDistance;
	double exitButtonY = creditsButtonY - buttonDistance;

	InitButton(playButton, playButtonTexture, buttonXPos, playButtonY, buttonWidth, buttonHeight);
	InitButton(rulesButton, rulesButtonTexture, buttonXPos, rulesButtonY, buttonWidth, buttonHeight);
	InitButton(creditsButton, creditsButtonTexture, buttonXPos, creditsButtonY, buttonWidth, buttonHeight);
	InitButton(exitButton, exitButtonTexture, buttonXPos, exitButtonY, buttonWidth, buttonHeight);
}

void DrawMenu()
{
	slSprite(backTexture, GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight());

	DrawButton(playButton);
	DrawButton(rulesButton);
	DrawButton(creditsButton);
	DrawButton(exitButton);
}

void MenuInput(Button& playButton, Button& rulesButton, Button& creditsButton, Button& exitButton, Scenes& scene)
{
	if (CheckCollisionButtonMouse(slGetMouseX(), slGetMouseY(), playButton))
	{
		playButton.isSelected = true;

		if (CheckMouseInput(playButton))
		{
			scene = Scenes::Play;
		}
	}
	else
		playButton.isSelected = false;

	if (CheckCollisionButtonMouse(slGetMouseX(), slGetMouseY(), rulesButton))
	{
		rulesButton.isSelected = true;
		if (CheckMouseInput(rulesButton))
		{
			scene = Scenes::Rules;
		}
	}
	else
		rulesButton.isSelected = false;

	if (CheckCollisionButtonMouse(slGetMouseX(), slGetMouseY(), creditsButton))
	{
		creditsButton.isSelected = true;
		if (CheckMouseInput(creditsButton))
		{
			scene = Scenes::Credits;
		}
	}
	else
		creditsButton.isSelected = false;

	if (CheckCollisionButtonMouse(slGetMouseX(), slGetMouseY(), exitButton))
	{
		exitButton.isSelected = true;
		if (CheckMouseInput(exitButton))
		{
			scene = Scenes::Exit;
		}
	}
	else
		exitButton.isSelected = false;
}

void RunMenu(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitMenu();
	}

	MenuInput(playButton, rulesButton, creditsButton, exitButton, scene);
	DrawMenu();
}