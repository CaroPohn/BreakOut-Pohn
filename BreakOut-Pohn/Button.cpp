#include "Objects/Button.h"

void InitButton(Button& button, int texture, double x, double y, double width, double height)
{
	button.texture = texture;
	button.x = x;
	button.y = y;
	button.width = width;
	button.height = height;
}