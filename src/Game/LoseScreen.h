#pragma once
#include "Scenes.h"

struct LoseScreen
{
	int texture;
	double x;
	double y;
	double width;
	double height;
};

void InitLoseScreen(LoseScreen& loseScreen);
void DrawLoseScreen(LoseScreen loseScreen);
void LoseScreenInput(Scenes& scene);
void RunLoseScreen(Scenes& scene, bool isNewScene);

