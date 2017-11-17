#include "UserInterface.h"
#include "Button.h"
#include "DNDButton.h"

#include <iostream>
#include <SDL.h>
#include <vector>

const int WIDTH = 800, HEIGHT = 600;

struct mainWindow
{
	SDL_Window* _window;
	std::vector<Button> buttons;
	std::vector<DNDButton> dndButtons;
	std::vector<InterfaceElement> images;
}mainWindow;

void SetUpMainWindow()
{
	mainWindow.buttons.push_back(Button(mainWindow._window)); //создаём все кнопки
	mainWindow.buttons.push_back(Button(mainWindow._window, 200, 0));
	mainWindow.dndButtons.push_back(DNDButton(mainWindow._window, 300, 0));

	mainWindow.images.push_back(InterfaceElement(mainWindow._window, 300, 300, 200, 200, "TheSun.bmp"));
}

void RedrawMainWindow()
{
	SDL_Surface* _screenSurface = SDL_GetWindowSurface(mainWindow._window);
	SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));

	for (auto i : mainWindow.images)
	{
		i.Draw();
	}

	for (auto i : mainWindow.buttons)
	{
		i.Update();
	}

	for (auto i : mainWindow.dndButtons) //обновляем передвигаемые кнопки поверх статичных
	{
		i.Update();
	}


	SDL_UpdateWindowSurface(mainWindow._window);
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not load! SDL Error: " << SDL_GetError() << std::endl;
	}

	SDL_Window *window = SDL_CreateWindow("InterfaceTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer *mainRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



	if (window == NULL)
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	mainWindow._window = window;

	SetUpMainWindow();
	RedrawMainWindow();

	SDL_Event windowEvent;

	Button* pressedButton = NULL;
	DNDButton* draggedButton = NULL;
	int mouseX = 0, mouseY = 0;

	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
			{
				break;
			}

			if (windowEvent.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&mouseX, &mouseY);

				for (auto &i : mainWindow.dndButtons) //находим нажатую перетаскиваемую, перерисовываем все кнопки; можно будет оптимизировать
				{
					if (i.CheckIfClicked(mouseX, mouseY))
					{
						draggedButton = &i;
						draggedButton->RememberOffset(mouseX, mouseY);
					}
				}
				if (draggedButton == NULL) //мы же не хотим нажать на передвигаемую кнопку И кнопку за ней?
				{
					for (auto &i : mainWindow.buttons) //находим нажатую кнопку, перерисовываем все кнопки; можно будет оптимизировать
					{
						if (i.CheckIfClicked(mouseX, mouseY))
						{
							pressedButton = &i;
						}
					}
				}


				RedrawMainWindow();

			}

			if (windowEvent.type == SDL_MOUSEMOTION)
			{
				if (draggedButton != NULL)
				{
					SDL_GetMouseState(&mouseX, &mouseY);
					draggedButton->Move(mouseX, mouseY);
					RedrawMainWindow();
				}
			}

			if (windowEvent.type == SDL_MOUSEBUTTONUP) //нам нужно обновлять графику кнопок только когда мы на чё-то нажали
			{
				if (pressedButton != NULL)
				{
					pressedButton->Unclick();
					pressedButton = NULL;
				}
				if (draggedButton != NULL)
				{
					draggedButton->Unclick();
					draggedButton = NULL;
				}
				RedrawMainWindow();
			}

		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}