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
	Uint32 userDefinedEvent;
	std::vector<Button> buttons;
	std::vector<DNDButton> dndButtons;
	std::vector<InterfaceElement> images;
}mainWindow;

void SetUpMainWindow()
{
	mainWindow.userDefinedEvent = SDL_RegisterEvents(1); //сука блять где комменты ñîçäà¸ì îïðåäåë¸ííîå ïîëüçîâàòåëåì ñîáûòèå è ñîõðàíÿåì åãî òèï, ÷òîáû ïîòîì èñïîëüçîâàòü â êíîïêàõ.

	mainWindow.buttons.push_back(Button(mainWindow._window)); //ñîçäà¸ì âñå êíîïêè
	mainWindow.buttons.push_back(Button(mainWindow._window, 200, 0));

	mainWindow.buttons[0].setMainFunction("one", mainWindow.userDefinedEvent);
	mainWindow.buttons[1].setMainFunction("one", mainWindow.userDefinedEvent);

	mainWindow.dndButtons.push_back(DNDButton(mainWindow._window, 300, 0));
	mainWindow.dndButtons.push_back(DNDButton(mainWindow._window, 500, 0));

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

	for (auto i : mainWindow.dndButtons) //îáíîâëÿåì ïåðåäâèãàåìûå êíîïêè ïîâåðõ ñòàòè÷íûõ
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

				for (auto &i : mainWindow.dndButtons) //íàõîäèì íàæàòóþ ïåðåòàñêèâàåìóþ, ïåðåðèñîâûâàåì âñå êíîïêè; ìîæíî áóäåò îïòèìèçèðîâàòü
				{
					if (i.CheckIfClicked(mouseX, mouseY))
					{
						draggedButton = &i;
						draggedButton->RememberOffset(mouseX, mouseY);
						break;
					}
				}
				if (draggedButton == NULL) //ìû æå íå õîòèì íàæàòü íà ïåðåäâèãàåìóþ êíîïêó È êíîïêó çà íåé?
				{
					for (auto &i : mainWindow.buttons) //íàõîäèì íàæàòóþ êíîïêó, ïåðåðèñîâûâàåì âñå êíîïêè; ìîæíî áóäåò îïòèìèçèðîâàòü
					{
						if (i.CheckIfClicked(mouseX, mouseY))
						{
							pressedButton = &i;
							break;
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

			if (windowEvent.type == SDL_MOUSEBUTTONUP) //íàì íóæíî îáíîâëÿòü ãðàôèêó êíîïîê òîëüêî êîãäà ìû íà ÷¸-òî íàæàëè
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

			if (windowEvent.type == mainWindow.userDefinedEvent)
			{
				if (windowEvent.user.code == mainWindow.buttons[0].GetCode())
				{
					SDL_ShowSimpleMessageBox(NULL, "Kondrat lox", "Nazhata pervaya knopka", mainWindow._window);
					continue;
				}
				SDL_ShowSimpleMessageBox(NULL, "Kondrat lox", "Nazhata knopka", mainWindow._window);
				
			}

		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
