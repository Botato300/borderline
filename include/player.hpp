#include <deque>

#include "inputManager.hpp"
#include "raylib/raylib.h"

class Player {
   public:
	Vector2 pos = {0.0f, 0.0f};
	std::deque<Vector2> steps = {};
	Vector2 lastPos = {};

	Color color;
	int baseSpeed = 5;
	float size = 10.0f;

	Player(Vector2, Color);

	void render();
	void update(const PlayerState&);
};