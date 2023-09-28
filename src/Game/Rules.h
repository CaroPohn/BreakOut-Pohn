#pragma once
#include "Scenes.h"

struct Rules
{
	int texture;
	double x;
	double y;
	double width;
	double height;
};

void InitRules(Rules& rules);
void DrawRules(Rules& rules);
void RulesInput(Scenes& scene);
void RunRules(Scenes& scene, bool isNewScene);

