#pragma once
#include <iostream>
#include <SDL.h>
#include "UserInterface.h"

class Button : public InterfaceElement
{
protected:
	bool isClicked;
	SDL_Surface* _textureSurfaceVariants[2];
public:
	std::string mainFunction;
	Button(SDL_Window* _mainWindow, int posX = 0, int posY = 0, int width = 100, int height = 100, const char* filename = "Button.bmp");
	bool CheckIfClicked(int mouseX, int mouseY);
	void Unclick();
	void Update();
};