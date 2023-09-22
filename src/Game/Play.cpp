#include "Play.h"
#include "Screen.h"
#include "Objects/Pad.h"
#include "sl.h"

int backGameTexture;
static Pad player;

void InitGame()
{
	backGameTexture = slLoadTexture("../assets/gameback.png");

	double playerWidth = 230;
	double playerHeigth = 30;

	InitPad(player, playerWidth, playerHeigth);
}

void DrawGame()
{
	slSprite(backGameTexture, GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight());
	DrawPad(player);
	slRender();
}

void RunGame(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitGame();
	}

	DrawGame();
}