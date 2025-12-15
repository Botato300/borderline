#pragma once

#include "playerState.hpp"
#include "raylib/raylib.h"

class InputManager {
   public:
	PlayerState statePlayer1;
	PlayerState statePlayer2;

	void update();
};