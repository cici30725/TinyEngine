#pragma once
#include "Events/Event.h"
#include "Observer.h"
#include <map>
#include <vector>

class Subject {
public:
	void addObserver(EventTypes event, Observer* observer) {
		m_Observers[event].emplace_back(observer);
	}

	void removeObserver(EventTypes event, Observer* observer) {
		std::vector<Observer*>& vec = m_Observers[event];
		auto iterator = std::find(vec.begin(), vec.end(), observer);
		if (iterator != vec.end()) {
			// Found
			vec.erase(iterator);
		}
	}
	
	virtual void Notify(Event* event) = 0;
protected:
	Subject(){}
	std::map<EventTypes, std::vector<Observer*>> m_Observers;
};