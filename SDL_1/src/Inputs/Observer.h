#pragma once
#include "Events/Event.h"

class Observer {
public:
	virtual void OnNotify(Event* event) = 0;
protected:
	Observer(){}
};
