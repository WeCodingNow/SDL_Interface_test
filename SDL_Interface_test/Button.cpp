#include "Button.h"

Button::Button(SDL_Window* _mainWindow, int posX, int posY, int width, int height, const char* filename) : InterfaceElement(_mainWindow, posX, posY, width, height, filename), isClicked(false)
{
	_textureSurfaceVariants[0] = _textureSurface;

	_textureSurfaceVariants[1] = SDL_LoadBMP(((std::string(filename).substr(0, std::string(filename).length() - 4)) + std::string("_pressed.bmp")).c_str()); //Button.bmp -> Button_pressed.bmp
	if (_textureSurfaceVariants[1] == NULL) std::cout << "Could not load the pressed version of " << filename << "!\n";

}


void Button::Update() //Обработчик событий для кнопки.
{
	//
	//здесь обрабатываем события для разных кнопок.
	//
	if (isClicked == true)
	{
		_textureSurface = _textureSurfaceVariants[1];
	}

	if (mainFunction == "one" && isClicked == true)
	{
		SDL_ShowSimpleMessageBox(NULL, "Kondrat lox", "Azaza zatralibasil", _parentWindow);
		isClicked = false;
	}

	Draw();
}


bool Button::CheckIfClicked(int mouseX, int mouseY)
{
	if ((mouseX > Pos.x) && (mouseX < Pos.x + Pos.w) && (mouseY > Pos.y) && (mouseY < Pos.y + Pos.h))
	{
		std::cout << "Detected a click at (" << mouseX << "," << mouseY << ")!\n";
		isClicked = true;
	}
	return isClicked;
}

void Button::Unclick()
{
	isClicked = false;
}