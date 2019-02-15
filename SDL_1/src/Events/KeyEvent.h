#pragma once
#include "Event.h"

class KeyEvent : public Event {
public:
	inline SDL_Keycode GetKeyCode() const { return m_KeyCode; }
protected:
	KeyEvent(SDL_Keycode code)
		:m_KeyCode(code){}
	SDL_Keycode m_KeyCode;
};

class KeyPressedEvent : public KeyEvent {
public:
	KeyPressedEvent(SDL_Keycode code)
		:KeyEvent(code){}

	EVENT_TYPE(KeyPressedEvent)
};
