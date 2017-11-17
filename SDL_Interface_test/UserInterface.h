#pragma once
#include <iostream>
#include <SDL.h>

class InterfaceElement
{
protected:
	SDL_Rect Pos;
	SDL_Surface* _textureSurface; //картинка элемента интерфейса
	SDL_Window* _parentWindow; //наша кнопка ¬—≈√ƒј будет принадлежать какому-то окну, пусть метод кнопки сам рисует еЄ
public:
	InterfaceElement(SDL_Window* pWindow, int posX, int posY, int width, int height, const char* filename);
	void Update();
	void Draw();
};