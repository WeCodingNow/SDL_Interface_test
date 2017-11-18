#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <SDL.h>

class ResourceManager
{
private:
	SDL_Renderer* _mainRenderer;
	std::map<std::string, SDL_Texture*> textures;
	std::vector<std::string> names;
public:
	ResourceManager();
	ResourceManager(SDL_Renderer* _mainRender);
	SDL_Texture* LoadImage(std::string name);
//	SDL_Texture* GetImage(std::string name);
};