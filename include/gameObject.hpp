#pragma once

#include "raylib/raylib.h"

struct GameObject {
	Vector2 pos = {0, 0};
	bool collision = false;

	GameObject(Vector2 pos, bool collision);
	virtual ~GameObject() = default;

	virtual void update() = 0;
	virtual void render() = 0;
};