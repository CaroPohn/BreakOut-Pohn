#pragma once

struct Brick
{
	int texture;
	double x;
	double y;
	double width;
	double height;
	bool isBroken;
};

void InitBrick(Brick& brick, int brickTexture, float xPos, float yPos, float brickWidth, float brickHeigth);
void FillBrickArray(Brick bricks[]);
void DrawBricks(Brick bricks[], int arraySize);