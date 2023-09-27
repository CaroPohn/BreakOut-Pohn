#include "Objects/Pad.h"
#include "sl.h"
#include "Game/Screen.h"

static int padTexture;

void InitPad(Pad& player, double width, double height)
{
	padTexture = slLoadTexture("assets/bar.png");
	
	player.texture = padTexture;
	player.x = GetScreenWidth() / 2;
	player.y = GetScreenHeight() / 4 - 30;
	player.width = width;
	player.height = height;
	player.speed = 1100.0f;
	player.lives = 3;
}

void MovePadRight(Pad& player)
{
	if (slGetKey(SL_KEY_RIGHT)) player.x += player.speed * slGetDeltaTime();
}

void MovePadLeft(Pad& player)
{
	if (slGetKey(SL_KEY_LEFT)) player.x -= player.speed * slGetDeltaTime();
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


void DrawPad(Pad player)
{
	slSprite(padTexture, player.x, player.y, player.width, player.height);
}