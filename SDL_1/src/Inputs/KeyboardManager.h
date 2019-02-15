#pragma once
#include "Subject.h"
#include "Events/KeyEvent.h"

class KeyboardManager : public Subject {
public:
	KeyboardManager(Observer* observer);
	virtual void Notify(Event* event) override;
};
