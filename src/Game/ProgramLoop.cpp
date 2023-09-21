#include "ProgramLoop.h"
#include "Screen.h"
#include "Menu.h"

static Scenes scene;

void GameLoop()
{
	slWindow(GetScreenWidth(), GetScreenHeight(), "Slime Hunter", false);

	scene = Scenes::Menu;
	Scenes previousScene = Scenes::Exit;
	bool isNewScene;

	InitMenu();

	do
	{
		isNewScene = (scene != previousScene);
		previousScene = scene;

		switch (scene)
		{
		case Scenes::Menu:
			RunMenu(scene, isNewScene);
			break;

		case Scenes::Play:
			
			break;

		case Scenes::Rules:
			
			break;

		case Scenes::Credits:

			break;

		case Scenes::Exit:
			break;

		default:
			break;
		}
	} while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) && scene != Scenes::Exit);

	slClose();
}