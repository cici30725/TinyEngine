#pragma once
#include "SDL.h"
#include "KeyboardManager.h"
#include "Events/KeyEvent.h"
#include "Inputs/Observer.h"

class InputHandle
{
public:
	InputHandle(Observer* observer);
	~InputHandle();
	void HandleEvent(SDL_Event& event);
private:
	KeyboardManager m_Keyboard;
};

