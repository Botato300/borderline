#pragma once

struct Event {
	virtual ~Event() = default;
};

struct PlayerAttack : Event {
	int playerid = 0;
	int damage = 0;
};
