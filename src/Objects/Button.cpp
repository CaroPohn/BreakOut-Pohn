#include "Objects/Button.h"
#include "sl.h"
#include "Game/Utilities.h"

void InitButton(Button& button, int texture, double x, double y, double width, double height)
{
	button.texture = texture;
	button.x = x;
	button.y = y;
	button.width = width;
	button.height = height;
	button.isSelected = false;
}

void DrawButton(Button button)
{
	if (button.isSelected)
	{
		slSetForeColor(0.7, 0.7, 0.7, 1);
	}
	else
		slSetForeColor(1, 1, 1, 1);

	slSprite(button.texture, button.x, button.y, button.width, button.height);
	slSetForeColor(1, 1, 1, 1);
}

bool CheckCollisionButtonMouse(int mouseX, int mouseY, Button button)
{
	return ((mouseX >= button.x - button.width/2) && (mouseX < (button.x + button.width/2)) && (mouseY >= button.y - button.height/2) && (mouseY < (button.y + button.height/2)));
}

bool CheckMouseInput(Button button)
{
	return (CheckCollisionButtonMouse(slGetMouseX(), slGetMouseY(), button) && (slGetMouseButton(SL_MOUSE_BUTTON_1) != 0));
}