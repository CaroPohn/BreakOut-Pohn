#include "LoseScreen.h"
#include "Screen.h"
#include "sl.h"

static int loseTexture;
LoseScreen loseScreen;

void InitLoseScreen(LoseScreen& loseScreen)
{
	loseTexture = slLoadTexture("assets/lose.png");
	
	loseScreen.texture = loseTexture;
	loseScreen.x = GetScreenWidth() / 2;
	loseScreen.y = GetScreenHeight() / 2;
	loseScreen.width = GetScreenWidth();
	loseScreen.height = GetScreenHeight();
}

void DrawLoseScreen(LoseScreen loseScreen)
{
	slSprite(loseScreen.texture, loseScreen.x, loseScreen.y, loseScreen.width, loseScreen.height);
}

void LoseScreenInput(Scenes& scene)
{
	if (slGetKey(SL_KEY_ESCAPE))
	{
		scene = Scenes::Menu;
	}
}

void RunLoseScreen(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitLoseScreen(loseScreen);
	}

	DrawLoseScreen(loseScreen);
	LoseScreenInput(scene);
}

