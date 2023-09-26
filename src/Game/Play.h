#pragma once
#include "Scenes.h"
#include "Objects/Pad.h"
#include "Objects/Ball.h"

void InitGame();
void CheckInput(Pad& player, bool& isPaused);
void DrawGame();
void PadScreenCollision(Pad& player);
bool BallPadCollision(Pad player, Ball ball);
void BounceDirection(Pad player, Ball& ball);
void BallScreenCollision(Ball& ball);
void RestLives(Pad& player, Ball& ball);
void UpdateGame();
void RunGame(Scenes& scene, bool isNewScene);
