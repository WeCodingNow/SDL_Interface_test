#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <SDL.h>

class ResourceManager
{
private:
	std::map<std::string, SDL_Texture*> textures;
	std::vector<std::string> names;
public:
	SDL_Texture* LoadImage(std::string name);
	SDL_Texture* GetImage(std::string name);
};