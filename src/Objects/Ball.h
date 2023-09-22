#pragma once

struct Ball
{
	int texture;
	double x;
	double y;
	double width;
	double height;
	const float DEFAULT_SPEED = 600.0f;
	float speed;
	float dirX;
	float dirY;
};

void InitBall(Ball& ball);
void DrawBall(Ball ball);