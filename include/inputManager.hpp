#pragma once

#include "eventManager.hpp"
#include "raylib/raylib.h"

struct PlayerState {
	Vector2 direction;
	bool sprint;
};

class InputManager {
   public:
	PlayerState statePlayer1;
	PlayerState statePlayer2;

	void update(EventManager&);
};