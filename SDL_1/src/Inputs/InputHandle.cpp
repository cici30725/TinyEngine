#include "pch.h"
#include "InputHandle.h"


InputHandle::InputHandle(Observer* observer)
{
}


InputHandle::~InputHandle()
{
}

void InputHandle::HandleEvent(const SDL_Event& event)
{
	switch (event.type) {
	case SDL_KEYDOWN:
		Notify(EventTypes::KeyPressedEvent, KeyPressedEvent(event.key.keysym.sym));
		break;
	case SDL_MOUSEMOTION:
		Notify(EventTypes::MouseMovementEvent, MouseMovementEvent(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel));
		break;
	}

}

void InputHandle::Notify(EventTypes type, Event&& event) {
	auto& vec = m_Observers[type];
	for (auto observer : vec) {
		observer->OnNotify(event);
	}
}

