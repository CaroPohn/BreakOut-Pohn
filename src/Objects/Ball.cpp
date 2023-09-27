#include "Ball.h"
#include "Game/Screen.h"
#include <iostream>
#include "sl.h"

int ballTexture;
void RandDirection(Ball& ball);

void InitBall(Ball& ball)
{
	ballTexture = slLoadTexture("assets/ball.png");
	
	ball.texture = ballTexture;
	ball.width = 24;
	ball.height = 24;
	ball.x = GetScreenWidth() / 2;
	ball.y = GetScreenHeight() / 4 + ball.height / 2 - 15;
	ball.speed = ball.DEFAULT_SPEED;

	RandDirection(ball);
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

void BallScreenCollision(Ball& ball)
{
	if (ball.y + ball.height / 2 >= GetScreenHeight())
	{
		ball.y = GetScreenHeight() - ball.height / 2;
		ball.dirY *= -1;
	}

	if (ball.x + ball.width / 2 >= GetScreenWidth())
	{
		ball.x = GetScreenWidth() - ball.width / 2;
		ball.dirX *= -1;
	}

	if (ball.x - ball.width / 2 <= 0)
	{
		ball.x = ball.width / 2;
		ball.dirX *= -1;
	}
}

void ResetBall(Ball& ball, Pad& player)
{
	ball.x = player.x;
	ball.y = GetScreenHeight() / 4 + ball.height / 2 - 15;
	ball.speed = ball.DEFAULT_SPEED;
	RandDirection(ball);
}

void RandDirection(Ball& ball)
{
	float randDirX = ((rand() % 19) - 9) * 0.1f;
	float randDirY = (rand() % 9) * 0.1f;

	if (randDirX >= 0 && randDirX < 0.4f)
		randDirX = 0.7f;

	else if (randDirX < 0 && randDirX > -0.4f)
		randDirX = -0.7f;

	if (randDirY >= 0 && randDirY < 0.3f)
		randDirY = 0.7f;

	ball.dirX = randDirX;
	ball.dirY = randDirY;
}