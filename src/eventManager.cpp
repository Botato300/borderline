#include "eventManager.hpp"

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "eventType.hpp"
#include "eventdata.hpp"

void EventManager::addListener(EventType eventType, std::function<void(std::shared_ptr<Event>)> callback) {
	this->events[eventType].push_back(callback);
}

void EventManager::emit(EventType eventType, std::shared_ptr<Event> event) {
	if (this->events.count(eventType)) {
		for (auto& callback : this->events[eventType]) callback(event);
	}
}