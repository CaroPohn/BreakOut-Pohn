#include "ProgramLoop.h"

static Scenes scene;

void GameLoop()
{
	const int screenWidth = 1200;
	const int screenHeight = 900;	

	slWindow(screenWidth, screenHeight, "BreakOut", false);

	scene = Scenes::Menu;
	Scenes previousScene = Scenes::Exit;
	bool isNewScene;

	do
	{
		isNewScene = (scene != previousScene);
		previousScene = scene;

		switch (scene)
		{
		case Scenes::Menu:
			
			break;

		case Scenes::Play:
			
			break;

		case Scenes::Rules:
			
			break;

		case Scenes::Exit:
			break;

		default:
			break;
		}
	} while (!slShouldClose && !slGetKey(SL_KEY_ESCAPE) && scene != Scenes::Exit);

	slClose();
}