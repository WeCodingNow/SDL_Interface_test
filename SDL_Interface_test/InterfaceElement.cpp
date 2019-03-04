#include "UserInterface.h"
#include "ResourceManager.h"

Image::Image(SDL_Renderer* _pRender, SDL_Texture* texture, int posX, int posY, int width, int height )
{
	if (_pRender != NULL)
	{
		_mainRenderer = _pRender;
	}
	Pos.x = posX; Pos.y = posY; Pos.w = width; Pos.h = height;
	_texture = texture;
}

void Image::Draw()
{

	if (_texture == NULL)
	{
		std::cout << "No texture surface!\n";
		return;
	}
	SDL_RenderCopy(_mainRenderer, _texture, NULL, &Pos);
}

void Image::Update()
{

}