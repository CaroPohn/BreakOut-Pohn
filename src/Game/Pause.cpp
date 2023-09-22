#include "Pause.h"
#include "Screen.h"
#include "sl.h"

int pauseTexture;

void InitPause(Pause& pause)
{
	pauseTexture = slLoadTexture("../assets/pause.png");

	pause.texture = pauseTexture;
	pause.x = GetScreenWidth() / 2;
	pause.y = GetScreenHeight() / 2;
	pause.width = 600;
	pause.height = 450;
}

void DrawPause(Pause pause)
{
	slSprite(pause.texture, pause.x, pause.y, pause.width, pause.height);
}

void InputPause(Scenes& scene, bool& isPaused)
{
	if (slGetKey(77) || slGetKey(109))
	{
		scene = Scenes::Menu;
	}

	if (slGetKey(32))
	{
		isPaused = false;
	}
}

void RunPause(Pause pause, Scenes& scene, bool& isPaused)
{
	InputPause(scene, isPaused);
	DrawPause(pause);
}