#include "sl.h"

void main()
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