#include "UserInterface.h"

InterfaceElement::InterfaceElement(SDL_Window* pWindow, int posX, int posY, int width, int height, const char* filename)
{
	if (pWindow != NULL)
	{
		_parentWindow = pWindow;
	}
	Pos.x = posX; Pos.y = posY; Pos.w = width; Pos.h = height;
	_textureSurface = SDL_LoadBMP(filename);
	if (_textureSurface == NULL) std::cout << "Could not load " << filename << "!\n";
}

void InterfaceElement::Update()
{
	Draw();
}

void InterfaceElement::Draw()
{
	SDL_Surface* _renderSurface = SDL_GetWindowSurface(_parentWindow);

	if (_textureSurface == NULL)
	{
		std::cout << "No texture surface!\n";
		return;
	}
	SDL_BlitSurface(_textureSurface, NULL, _renderSurface, &Pos);
}