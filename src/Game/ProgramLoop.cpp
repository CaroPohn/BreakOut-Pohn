#include "ProgramLoop.h"
#include "Screen.h"
#include "Menu.h"
#include "Game/Play.h"

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
			RunGame(scene, isNewScene);
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

		slRender();

	} while (!slShouldClose() && (!slGetKey(81) || !slGetKey(113)) && scene != Scenes::Exit);

	slClose();
}