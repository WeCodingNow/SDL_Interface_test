#pragma once
#include <iostream>
#include <SDL.h>
#include "UIObject.h"


class Image: public UIObject
{
protected:
	SDL_Rect Pos;
	SDL_Texture* _texture; //картинка элемента интерфейса
	SDL_Renderer* _mainRenderer; //наша кнопка ¬—≈√ƒј будет принадлежать какому-то окну, пусть метод кнопки сам рисует еЄ
public:
	Image(SDL_Renderer* _pRenderer, SDL_Texture* _texture, int posX, int posY, int width, int height);
	void Update();
	void Draw();

};