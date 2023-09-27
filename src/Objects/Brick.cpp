#include "Brick.h"
#include "Game/Screen.h"
#include "sl.h"

void InitBrick(Brick& brick, int brickTexture, float xPos, float yPos, float brickWidth, float brickHeigth)
{
	brick.texture = brickTexture;
	brick.x = xPos;
	brick.y = yPos;
	brick.width = brickWidth;
	brick.height = brickHeigth;
	brick.isBroken = false;
}

void FillBrickArray(Brick bricks[])
{
	int brickTexture = slLoadTexture("assets/block.png");
	int bricksPerRow = 7;
	int rowsQnty = 7;
	float brickWidth = 150.0f;
	float brickHeight = 45.0f;
	float xDistance = ((float)GetScreenWidth() - (brickWidth * bricksPerRow)) / (bricksPerRow + 1);
	float yDistance = xDistance - 10;
	float xPos = xDistance + (brickWidth / 2);
	float yPos = (float)GetScreenHeight() - yDistance - (brickHeight /2);
	int index = 0;

	for (int row = 0; row < rowsQnty; row++)
	{
		for (int col = 0; col < bricksPerRow; col++)
		{
			InitBrick(bricks[index], brickTexture, xPos, yPos, brickWidth, brickHeight);
			xPos += xDistance + brickWidth;
			index++;
		}
		xPos = xDistance + (brickWidth / 2);
		yPos -= yDistance + brickHeight;
	}
}

void DrawBricks(Brick bricks[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (!bricks[i].isBroken)
		{
			slSprite(bricks[i].texture, bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height);
		}
	}
}