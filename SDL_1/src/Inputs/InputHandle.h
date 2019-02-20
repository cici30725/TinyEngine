#pragma once
#include "SDL.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Inputs/Observer.h"
#include "Inputs/Subject.h"

class InputHandle : public Subject
{
public:
	InputHandle(Observer* observer);
	~InputHandle();
	void HandleEvent(const SDL_Event& event);
	virtual void Notify(EventTypes type, Event&& event) override;
private:
};

