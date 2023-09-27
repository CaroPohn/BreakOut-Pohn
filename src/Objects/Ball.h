#pragma once
#include "Pad.h"

struct Ball
{
	int texture;
	double x;
	double y;
	double width;
	double height;
	const float DEFAULT_SPEED = 500.0f;
	float speed;
	float dirX;
	float dirY;
};

void InitBall(Ball& ball);
void DrawBall(Ball ball);
void BallMovement(Ball& ball);
void BallScreenCollision(Ball& ball);
void ResetBall(Ball& ball, Pad& player);