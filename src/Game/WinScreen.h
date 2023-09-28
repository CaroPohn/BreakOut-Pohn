#pragma once
#include "Scenes.h"

struct WinScreen
{
	int texture;
	double x;
	double y;
	double width;
	double height;
};

void RunWinScreen(Scenes& scene, bool isNewScene);
