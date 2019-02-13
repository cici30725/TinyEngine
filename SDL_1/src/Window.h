#pragma once
#include "SDL.h"

class Window
{
public:
	Window(int, int);
	~Window();
	bool Init();
	SDL_Window& GetWindow() { return *window; }
private:
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	int m_ScreenWidth;
	int m_ScreenHeight;
};

