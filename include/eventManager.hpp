#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

struct Event {
	virtual ~Event() = default;
};

struct PlayerAttack : Event {
	int playerid = 0;
	int damage = 0;
};

class EventManager {
   private:
	std::unordered_map<std::string, std::vector<std::function<void(std::shared_ptr<Event>)>>> events;

   public:
	void addListener(std::string, std::function<void(std::shared_ptr<Event>)>);
	void emit(const std::string, std::shared_ptr<Event>);
};