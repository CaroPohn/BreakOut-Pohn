#include "sl.h"

void Example1();
void Example2();

void main()
{
	Example2();
}

void Example1()
{
	// set up our window and a few resources we need
	slWindow(400, 400, "Simple SIGIL Example", false);
	slSetTextAlign(SL_ALIGN_CENTER);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		// background glow
		slSetForeColor(0.1, 0.9, 0.2, 0.4);

		// large text and fat line
		slSetForeColor(0.0, 0.8, 0.2, 1.0);
		slSetFontSize(24);
		slRectangleFill(200, 240, 100, 7);

		// smaller subtext
		slSetFontSize(14);
		slLine(48, 210, 352, 210);

		slRender();
	}

	slClose();
}

void Example2()
{
	const int width = 400;
	const int height = 400;

	slWindow(width, height, "Prueba breakout", false);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		slSetBackColor(0.5, 0.75, 1.0);

		slSetForeColor(1, 0, 0, 1);
		slRectangleFill(width * 0.5, height * 0.5, 100, 100);

		slRender();
	}

	slClose();
}