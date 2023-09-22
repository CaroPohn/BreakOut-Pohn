#include "Ball.h"
#include "Game/Screen.h"
#include "sl.h"

int ballTexture;

void InitBall(Ball& ball)
{
	ballTexture = slLoadTexture("../assets/ball.png");
	
	ball.width = 24;
	ball.height = 24;
	ball.x = GetScreenWidth() / 2;
	ball.y = GetScreenHeight() / 4 + ball.height / 2 - 15;
	ball.speed = ball.DEFAULT_SPEED;

	ball.dirX = 0.0f;
	ball.dirY = 0.0f;
}

void DrawBall(Ball ball)
{
	slSprite(ballTexture, ball.x, ball.y, ball.width, ball.height);
}
