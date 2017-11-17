#pragma once
#include <iostream>
#include <SDL.h>

class InterfaceElement
{
protected:
	SDL_Rect Pos;
	SDL_Surface* _textureSurface; //�������� �������� ����������
	SDL_Window* _parentWindow; //���� ������ ������ ����� ������������ ������-�� ����, ����� ����� ������ ��� ������ �
public:
	InterfaceElement(SDL_Window* pWindow, int posX, int posY, int width, int height, const char* filename);
	void Update();
	void Draw();
};