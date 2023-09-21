#include "Screen.h"

Screen screen{ 1200, 900 };

int GetScreenWidth()
{
    return screen.width;
}

int GetScreenHeight()
{
    return screen.height;
}