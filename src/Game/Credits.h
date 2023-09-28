#pragma once
#include "Scenes.h"

struct Credits
{
	int texture;
	double x;
	double y;
	double width;
	double height;
};

void InitCredits(Credits& credits);
void DrawCredits(Credits credits);
void CreditsInput(Scenes& scene);
void RunCredits(Scenes& scene, bool isNewScene);