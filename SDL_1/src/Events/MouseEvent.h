#pragma once
#include "Event.h"

class MouseMovementEvent : public Event{
public:
	MouseMovementEvent(int x, int y, int xrel, int yrel)
		:m_MouseX(x)
		,m_MouseY(y)
		,m_MouseXRel(xrel)
		,m_MouseYRel(yrel){}
	inline int GetMouseX() const{ return m_MouseX; }
	inline int GetMouseY() const { return m_MouseY; }
	inline int GetMouseXRel() const { return m_MouseXRel; }
	inline int GetMouseYRel() const { return m_MouseYRel; }

	EVENT_TYPE(MouseMovementEvent)
private:
	int m_MouseX;
	int m_MouseY;
	int m_MouseXRel;
	int m_MouseYRel;
};