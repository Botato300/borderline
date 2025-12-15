#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "eventData.hpp"
#include "eventType.hpp"

class EventManager {
   private:
	std::unordered_map<EventType, std::vector<std::function<void(std::shared_ptr<Event>)>>> events;

   public:
	void addListener(EventType, std::function<void(std::shared_ptr<Event>)>);
	void emit(EventType, std::shared_ptr<Event>);
};