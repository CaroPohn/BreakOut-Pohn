#include "Objects/Pad.h"
#include "sl.h"
#include "Game/Screen.h"

int padTexture;

void InitPad(Pad& player, double width, double height)
{
	padTexture = slLoadTexture("../assets/bar.png");
	
	player.texture = padTexture;
	player.x = GetScreenWidth() / 2;
	player.y = GetScreenHeight() / 4 - 30;
	player.width = width;
	player.height = height;
	player.lives = 3;
}

void DrawPad(Pad player)
{
	slSprite(padTexture, player.x, player.y, player.width, player.height);
}