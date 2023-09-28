#include "WinScreen.h"
#include "Screen.h"

#include "sl.h"

static int winTexture;
WinScreen winScreen;

void InitWinScreen(WinScreen& winScreen);
void DrawWinScreen(WinScreen winScreen);
void WinScreenInput(Scenes& scene);

void InitWinScreen(WinScreen& winScreen)
{
	winTexture = slLoadTexture("assets/win.png");
	
	winScreen.texture = winTexture;
	winScreen.x = GetScreenWidth() / 2;
	winScreen.y = GetScreenHeight() / 2;
	winScreen.width = GetScreenWidth();
	winScreen.height = GetScreenHeight();
}

void DrawWinScreen(WinScreen winScreen)
{
	slSprite(winScreen.texture, winScreen.x, winScreen.y, winScreen.width, winScreen.height);
}

void WinScreenInput(Scenes& scene)
{
	if (slGetKey(SL_KEY_ESCAPE))
	{
		scene = Scenes::Menu;
	}
}

void RunWinScreen(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitWinScreen(winScreen);
	}

	WinScreenInput(scene);
	DrawWinScreen(winScreen);
}
