#pragma once
#include "Button.h"

class DNDButton : public Button
{
private:
	int offX, offY;
public:
	DNDButton(SDL_Window* _mainWindow, int posX = 0, int posY = 0, int width = 100, int height = 100, const char* filename = "Button.bmp");
	void RememberOffset(int mouseX, int mouseY);
	void Move(int mouseX, int mouseY);
};