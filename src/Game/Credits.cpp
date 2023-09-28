#include "Credits.h"
#include "Screen.h"
#include "sl.h"

static int creditsTexture;
Credits credits;

void InitCredits(Credits& credits)
{
	creditsTexture = slLoadTexture("assets/credits.png");

	credits.texture = creditsTexture;
	credits.x = GetScreenWidth() / 2;
	credits.y = GetScreenHeight() / 2;
	credits.width = GetScreenWidth();
	credits.height = GetScreenHeight();
}

void DrawCredits(Credits credits)
{
	slSprite(credits.texture, credits.x, credits.y, credits.width, credits.height);
}

void CreditsInput(Scenes& scene)
{
	if (slGetKey(SL_KEY_ESCAPE))
	{
		slSoundStopAll();
		scene = Scenes::Menu;
	}
}

void RunCredits(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitCredits(credits);
	}

	DrawCredits(credits);
	CreditsInput(scene);
}
