#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::ResourceManager(SDL_Renderer* _mainRender) : _mainRenderer(_mainRender)
{
}

SDL_Texture* ResourceManager::LoadImage(std::string filename)
{
	if (textures[filename] != NULL)
	{
		std::cout << "found " << filename.c_str();
		return textures[filename];
	} 
	else
	{
		SDL_Surface* tempSurface = SDL_LoadBMP(filename.c_str());
		if (tempSurface == NULL)
		{
			std::cout << "Could not load " << filename.c_str() << "!\n";
		}

		textures[filename] = SDL_CreateTextureFromSurface(_mainRenderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		return textures[filename];
	}
}
