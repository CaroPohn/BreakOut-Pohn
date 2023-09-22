#pragma once
#include "Scenes.h"
#include "Objects/Pad.h"

void InitGame();
void CheckInput(Pad& player, bool& isPaused);
void DrawGame();
void PadScreenCollision(Pad& player);
void UpdateGame();
void RunGame(Scenes& scene, bool isNewScene);
