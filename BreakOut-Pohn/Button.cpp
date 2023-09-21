#include "Objects/Button.h"
#include "sl.h"

void InitButton(Button& button, int texture, double x, double y, double width, double height)
{
	button.texture = texture;
	button.x = x;
	button.y = y;
	button.width = width;
	button.height = height;
}

void DrawButton(Button button)
{
	slSprite(button.texture, button.x, button.y, button.width, button.height);
}