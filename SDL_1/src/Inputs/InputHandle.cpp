#include "pch.h"
#include "InputHandle.h"


InputHandle::InputHandle(Observer* observer)
	:m_Keyboard(observer)
{
}


InputHandle::~InputHandle()
{
}

void InputHandle::HandleEvent(SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		KeyPressedEvent* k = new KeyPressedEvent(event.key.keysym.sym);
		m_Keyboard.Notify(k); // the parameter is the keycode
		delete k;
		break;
	}
}

