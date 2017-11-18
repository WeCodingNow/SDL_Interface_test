#include "Button.h"

void DNDButton::RememberOffset(int X, int Y)
{
	offX = Pos.x - X;
	offY = Pos.y - Y;
}

void DNDButton::Move(int X, int Y)
{
	Pos.x = X + offX;
	Pos.y = Y + offY;
}