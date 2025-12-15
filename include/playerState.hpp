#pragma once

#include "raylib/raylib.h"

struct PlayerState {
	Vector2 direction = {0, 0};
	bool sprint = false;
	bool attack = false;
};