#pragma once
#include "Scenes.h"

struct Pause
{
	int texture;
	double x;
	double y;
	double width;
	double height;
};

void InitPause(Pause& pause);
void DrawPause(Pause pause);
void InputPause(Scenes& scene, bool& isPaused);
void RunPause(Pause pause, Scenes& scene, bool& isPaused);