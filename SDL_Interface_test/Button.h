#pragma once
#include <iostream>
#include <SDL.h>
#include "UserInterface.h"
#include "IMovable.h"

class Button : public Image
{
protected:
	bool isClicked;
	static int code;
	int myCode;
	Uint32 myEventType;
	SDL_Texture* _textureVariants[2];
	std::string mainFunction;
public:
	void setMainFunction(std::string mainFunc, Uint32 eventType);
	Button(SDL_Renderer* _mainRenderer, SDL_Texture* _texture, int posX = 0, int posY = 0, int width = 100, int height = 100);
	int GetCode();
	void Unclick();
	void Update();
	void AddPressedImage(SDL_Texture* _texture);
	bool CheckIfClicked();
};

class DNDButton : public Button, public IMovable
{
	void RememberOffset(int X, int Y);
	void Move(int X, int Y);
};