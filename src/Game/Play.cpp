#include "Play.h"
#include "Screen.h"
#include "Game/Pause.h"
#include "Objects/Brick.h"
#include <iostream>
#include "sl.h"

int backGameTexture;
static Pad player;
static Ball ball;
static Pause pause;
const int TOTAL_BRICKS = 49;
Brick bricks[TOTAL_BRICKS];
static bool isPaused = false;

void InitGame();
void CheckInput(Pad& player, bool& isPaused);
void DrawGame();
void PadScreenCollision(Pad& player);
bool BallPadCollision(Pad player, Ball ball);
void BounceDirection(Pad player, Ball& ball);
bool BallBrickCollision(Brick brick, Ball ball);
void BallBrickChangeDirection(Ball& ball, Brick bricks[], int numBricks);
void RestLives(Pad& player, Ball& ball);
void UpdateGame();

void InitGame()
{
	backGameTexture = slLoadTexture("assets/gameback.png");

	double playerWidth = 230;
	double playerHeigth = 30;

	InitPad(player, playerWidth, playerHeigth);
	InitPause(pause);
	InitBall(ball);
	FillBrickArray(bricks);
}

void CheckInput(Pad& player, bool& isPaused)
{
	MovePadRight(player);
	MovePadLeft(player);

	if (slGetKey(SL_KEY_ESCAPE))
	{
		isPaused = !isPaused;
	}

}

void DrawGame()
{
	slSprite(backGameTexture, GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight());
	DrawPad(player);
	DrawBall(ball);
	DrawBricks(bricks, TOTAL_BRICKS);
}

bool BallPadCollision(Pad player, Ball ball)
{
	float playerRightEdge = player.x + player.width / 2;
	float playerLeftEdge = player.x - player.width / 2;
	float playerTopEdge = player.y + player.height / 2;
	float playerBottomEdge = player.y - player.height / 2;

	float ballRightEdge = ball.x + ball.width / 2;
	float ballLeftEdge = ball.x - ball.width / 2;
	float ballTopEdge = ball.y + ball.height / 2;
	float ballBottomEdge = ball.y - ball.height / 2;

	return (playerRightEdge >= ballLeftEdge &&
		playerLeftEdge <= ballRightEdge &&
		playerTopEdge >= ballBottomEdge &&
		playerBottomEdge <= ballTopEdge);
}

void BounceDirection(Pad player, Ball& ball)
{
	if (BallPadCollision(player, ball))
	{
		if (ball.y - ball.height / 2 < player.y + player.height / 2)
		{
			ball.y += player.y + player.height / 2 - ball.y + ball.height / 2;
		}

		if(ball.speed < 600.0f)
			ball.speed *= 1.1f;
		else
			ball.speed *= 1.0f;

		ball.dirY *= -1;

		float xCollisionPoint = (ball.x + ball.width / 2 - player.x) / player.width;
		float amplitude = 3.5f;
		ball.dirX = std::sinf(xCollisionPoint) * amplitude;
	}
}

bool BallBrickCollision(Brick brick, Ball ball)
{
	float brickRightEdge = brick.x + brick.width / 2;
	float brickLeftEdge = brick.x - brick.width / 2;
	float brickTopEdge = brick.y + brick.height / 2;
	float brickBottomEdge = brick.y - brick.height / 2;

	float ballRightEdge = ball.x + ball.width / 2;
	float ballLeftEdge = ball.x - ball.width / 2;
	float ballTopEdge = ball.y + ball.height / 2;
	float ballBottomEdge = ball.y - ball.height / 2;

	return (brickRightEdge >= ballLeftEdge &&
		brickLeftEdge <= ballRightEdge &&
		brickTopEdge >= ballBottomEdge &&
		brickBottomEdge <= ballTopEdge &&
		!brick.isBroken);
}

void BallBrickChangeDirection(Ball& ball, Brick bricks[], int numBricks) 
{
	for (int i = 0; i < numBricks; i++)
	{
		float brickRightEdge = bricks[i].x + bricks[i].width / 2;
		float brickLeftEdge = bricks[i].x - bricks[i].width / 2;
		float brickTopEdge = bricks[i].y + bricks[i].height / 2;
		float brickBottomEdge = bricks[i].y - bricks[i].height / 2;

		float ballRightEdge = ball.x + ball.width / 2;
		float ballLeftEdge = ball.x - ball.width / 2;
		float ballTopEdge = ball.y + ball.height / 2;
		float ballBottomEdge = ball.y - ball.height / 2;

		if (BallBrickCollision(bricks[i], ball))
		{
			if (ballBottomEdge < brickBottomEdge && ball.x < brickRightEdge && ball.x > brickLeftEdge)
			{
				ball.y = brickBottomEdge - ball.height / 2;
				if (ball.dirY > 0)
					ball.dirY *= -1;
			}
			else if (ballTopEdge > brickTopEdge && ball.x < brickRightEdge && ball.x > brickLeftEdge)
			{
				ball.y = brickTopEdge + ball.height / 2;
				if (ball.dirY < 0)
					ball.dirY *= -1;
			}
			else if (ballRightEdge > brickRightEdge && ball.y < brickTopEdge && ball.y > brickBottomEdge)
			{
				ball.x = brickRightEdge + ball.width / 2;
				if (ball.dirX < 0)
					ball.dirX *= -1;
			}
			else if (brickLeftEdge < brickLeftEdge && ball.y < brickTopEdge && ball.y > brickBottomEdge)
			{
				ball.x = brickLeftEdge - ball.width / 2;
				if (ball.dirX > 0)
					ball.dirX *= -1;
			}
			else
			{
				if (ballBottomEdge < brickBottomEdge && ball.dirY > 0)
				{
					ball.y = brickBottomEdge - ball.height / 2;
					ball.dirY *= -1;
				}
				else if (ballTopEdge < brickTopEdge && ball.dirY < 0)
				{
					ball.y = brickTopEdge + ball.height / 2;
					ball.dirY *= -1;
				}
			}

			bricks[i].isBroken = true;
		}
	}
}

void RestLives(Pad& player, Ball& ball)
{
	if (ball.y - ball.height / 2 <= 0)
	{
		player.lives -= 1;
		ResetBall(ball, player);
	}
}

void UpdateGame()
{
	CheckInput(player, isPaused);
	PadScreenCollision(player);
	BallMovement(ball);
	BallScreenCollision(ball);
	BounceDirection(player, ball);
	BallBrickChangeDirection(ball, bricks, TOTAL_BRICKS);
	RestLives(player, ball);
}

void RunGame(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitGame();
		isPaused = false;
	}

	if (!isPaused)
	{
		UpdateGame();
	}

	DrawGame();

	if (isPaused)
	{
		RunPause(pause, scene, isPaused);
	}
}