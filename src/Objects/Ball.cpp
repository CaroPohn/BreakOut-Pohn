#include "Ball.h"
#include "Game/Screen.h"
#include <iostream>
#include "sl.h"

int ballTexture;

void InitBall(Ball& ball)
{
	ballTexture = slLoadTexture("assets/ball.png");
	
	ball.texture = ballTexture;
	ball.width = 24;
	ball.height = 24;
	ball.x = GetScreenWidth() / 2;
	ball.y = GetScreenHeight() / 4 + ball.height / 2 - 15;
	ball.speed = ball.DEFAULT_SPEED;

	ball.dirX = 1.0f;
	ball.dirY = 1.0f;
}

void DrawBall(Ball ball)
{
	slSprite(ball.texture, ball.x, ball.y, ball.width, ball.height);
}

void BallMovement(Ball& ball)
{
	ball.x += ball.speed * ball.dirX * slGetDeltaTime();
	ball.y += ball.speed * ball.dirY * slGetDeltaTime();
}

void ResetBall(Ball& ball, Pad& player)
{
	ball.x = player.x;
	ball.y = GetScreenHeight() / 4 + ball.height / 2 - 15;
	ball.speed = ball.DEFAULT_SPEED;
	
	float randDirX = ((rand() % 19) - 9) * 0.1f;
	float randDirY = (rand() % 9) * 0.1f;

	if (randDirX >= 0 && randDirX < 0.4f)
		randDirX = 0.7f;

	else if (randDirX < 0 && randDirX > -0.4f)
		randDirX = -0.7f;

	if (randDirY >= 0 && randDirY < 0.3f)
		randDirY = 0.7f;
}
