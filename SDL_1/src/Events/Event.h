#pragma once
#include "SDL.h"

enum class EventTypes {
	MouseMovementEvent, MouseButtonCLickedEvent, KeyPressedEvent, KeyReleasedEvent
};

class Event {
public:
	virtual EventTypes GetEventType() const = 0;
};

#define EVENT_TYPE(type) static EventTypes GetStaticType() { return EventTypes::##type; }\
						 virtual EventTypes GetEventType() const override { return GetStaticType(); }