#include "Play.h"
#include "Screen.h"
#include "Game/Pause.h"
#include <iostream>
#include "sl.h"

int backGameTexture;
static Pad player;
static Ball ball;
static Pause pause;
static bool isPaused = false;

void InitGame()
{
	backGameTexture = slLoadTexture("assets/gameback.png");

	double playerWidth = 230;
	double playerHeigth = 30;

	InitPad(player, playerWidth, playerHeigth);
	InitPause(pause);
	InitBall(ball);
}

void CheckInput(Pad& player, bool& isPaused)
{
	if(slGetKey(68) || slGetKey(100)) player.x += player.speed * slGetDeltaTime();
	if(slGetKey(65) || slGetKey(97)) player.x -= player.speed * slGetDeltaTime();

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
}

void PadScreenCollision(Pad& player)
{
	if (player.x - player.width / 2 <= 0)
	{
		player.x = 0 + player.width / 2;
	}

	if (player.x + player.width / 2 >= GetScreenWidth())
	{
		player.x = GetScreenWidth() - player.width / 2;
	}
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
			ball.y += player.y + player.height / 2 - ball.y;
		}

		if (ball.speed < 900.0f)
			ball.speed *= 1.1f;
		else
			ball.speed *= 1.0f;

		ball.dirY *= -1;

		float collisionInX = (ball.x - (player.x + player.width / 2)) / (player.width / 2);

		ball.dirX = std::sin(collisionInX);
	}
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
		ball.dirX *= -1;
	}

	if (ball.x - ball.width / 2 <= 0)
	{
		ball.dirX *= -1;
	}
}

void RestLives(Pad& player, Ball ball)
{
	if (ball.y - ball.height / 2 <= 0)
	{
		player.lives -= 1;
		InitBall(ball);
	}
}

void UpdateGame()
{
	CheckInput(player, isPaused);
	PadScreenCollision(player);
	BallMovement(ball);
	BallScreenCollision(ball);
	BounceDirection(player, ball);
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