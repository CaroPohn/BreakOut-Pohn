#include "ProgramLoop.h"
#include "Screen.h"
#include "Menu.h"
#include "Game/Play.h"
#include "WinScreen.h"
#include "LoseScreen.h"
#include "Rules.h"
#include "Credits.h"
#include <iostream>

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

		case Scenes::Win:
			RunWinScreen(scene, isNewScene);
			break;

		case Scenes::Lose:
			RunLoseScreen(scene, isNewScene);
			break;

		case Scenes::Rules:
			RunRules(scene, isNewScene);
			break;

		case Scenes::Credits:
			RunCredits(scene, isNewScene);
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