#pragma once
#include <iostream>
#include <SDL.h>
#include "UserInterface.h"

class Button : public InterfaceElement
{
protected:
	bool isClicked;
	static int code;
	int myCode;
	Uint32 myEventType;
	SDL_Surface* _textureSurfaceVariants[2];
	std::string mainFunction;
public:
	void setMainFunction(std::string mainFunc, Uint32 eventType);
	Button(SDL_Window* _mainWindow, int posX = 0, int posY = 0, int width = 100, int height = 100, const char* filename = "Button.bmp");
	bool CheckIfClicked(int mouseX, int mouseY);
	int GetCode();
	void Unclick();
	void Update();
};