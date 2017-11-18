#include "IMovable.h"

DNDButton::DNDButton(SDL_Window* _mainWindow, int posX, int posY, int width, int height, const char* filename) : Button(_mainWindow, posX, posY, width, height, filename) {};

void DNDButton::RememberOffset(int mouseX, int mouseY)
{
	offX = Pos.x - mouseX;
	offY = Pos.y - mouseY;
}

void DNDButton::Move(int mouseX, int mouseY)
{
	Pos.x = mouseX + offX;
	Pos.y = mouseY + offY;
}