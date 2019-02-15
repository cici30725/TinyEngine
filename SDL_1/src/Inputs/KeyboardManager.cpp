#include "pch.h"
#include "KeyboardManager.h"

KeyboardManager::KeyboardManager(Observer* observer) {
	addObserver(EventTypes::KeyPressedEvent, observer);
}

void KeyboardManager::Notify(Event* event) {
	auto vec = m_Observers[event->GetEventType()];
	for (auto observer : vec) {
		observer->OnNotify(event);
	}
}