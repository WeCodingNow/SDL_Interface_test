#include "Button.h"

Button::Button(SDL_Renderer* _mainRenderer, SDL_Texture* _textur, int posX, int posY, int width, int height) : Image(_mainRenderer, _textur, posX, posY, width, height), isClicked(false)
{
	_textureVariants[0] = _texture;

	myCode = -1;

}
int Button::code = 0;

void Button::Update() //Обработчик событий для кнопки.
{


	if (isClicked == true)
	{
		_texture = _textureVariants[1];
		isClicked = false;
	}

	else
	{
		_texture = _textureVariants[0];
	}

	if (mainFunction == "one" && isClicked == true)
	{
		SDL_Event tempEvent;
		tempEvent.type = myEventType;
		tempEvent.user.code = myCode;
		SDL_PushEvent(&tempEvent);
		isClicked = false;
	}
}


bool Button::CheckIfClicked()
{
	int mouseX = 0, mouseY = 0;
	isClicked = false;

	SDL_GetMouseState(&mouseX, &mouseY);
	
		if ((mouseX > Pos.x) && (mouseX < Pos.x + Pos.w) && (mouseY > Pos.y) && (mouseY < Pos.y + Pos.h))
		{
			std::cout << "Detected a click at (" << mouseX << "," << mouseY << ")!\n";
			isClicked = true;
		}
	
	return isClicked;
}

void Button::AddPressedImage(SDL_Texture* _texture)
{
	_textureVariants[1] = _texture;
}

int Button::GetCode()
{
	return myCode;
}

void Button::setMainFunction(std::string mainFunctions, Uint32 eventType)
{
	mainFunction = mainFunctions;  //каждая функциональная кнопка уникальна
	myEventType = eventType;       //у всех кнопок один тип посылаемого в обработчик события
	myCode = code++;               //каждая функциональная кнопка отличается от другой, даже несущей такой же функцию, своим кодом
}

void Button::Unclick()
{
	isClicked = false;
}

void DNDButton::RememberOffset(int X, int Y)
{
	offX = Pos.x - X; offY = Pos.y - Y;
}

void DNDButton::Move(int X, int Y)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);
}