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
	int brickTexture2 = slLoadTexture("assets/block2.png");
	int brickTexture3 = slLoadTexture("assets/block3.png");
	int brickTexture4 = slLoadTexture("assets/block4.png");
	int brickTexture5 = slLoadTexture("assets/block5.png");
	int brickTexture6 = slLoadTexture("assets/block6.png");
	int bricksPerRow = 7;
	int rowsQnty = 7;
	float brickWidth = 150.0f;
	float brickHeight = 45.0f;
	float xDistance = ((float)GetScreenWidth() - (brickWidth * bricksPerRow)) / (bricksPerRow + 1);
	float yDistance = xDistance - 10;
	float xPos = xDistance + (brickWidth / 2);
	float yPos = (float)GetScreenHeight() - yDistance - (brickHeight /2) - 40;
	int index = 0;

	for (int row = 0; row < rowsQnty; row++)
	{
		for (int col = 0; col < bricksPerRow; col++)
		{
			switch (row)
			{
			case 0:
				InitBrick(bricks[index], brickTexture, xPos, yPos, brickWidth, brickHeight);
				break;

			case 1:
				InitBrick(bricks[index], brickTexture2, xPos, yPos, brickWidth, brickHeight);
				break;

			case 2:
				InitBrick(bricks[index], brickTexture3, xPos, yPos, brickWidth, brickHeight);
				break;

			case 3:
				InitBrick(bricks[index], brickTexture6, xPos, yPos, brickWidth, brickHeight);
				break;

			case 4:
				InitBrick(bricks[index], brickTexture4, xPos, yPos, brickWidth, brickHeight);
				break;

			case 5:
				InitBrick(bricks[index], brickTexture5, xPos, yPos, brickWidth, brickHeight);
				break;

			default:
				InitBrick(bricks[index], brickTexture, xPos, yPos, brickWidth, brickHeight);
				break;
			}
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