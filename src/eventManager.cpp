#include "eventManager.hpp"

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

void EventManager::addListener(std::string eventType, std::function<void(std::shared_ptr<Event>)> callback) {
	this->events[eventType].push_back(callback);
}

void EventManager::emit(std::string eventType, std::shared_ptr<Event> event) {
	if (this->events.count(eventType)) {
		for (auto& callback : this->events[eventType]) callback(event);
	}
}