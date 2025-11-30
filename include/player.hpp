#include "raylib/raylib.h"

class Player {
   public:
	Vector2 pos = {0.0f, 0.0f};
	Color color;
	int baseSpeed = 5.0f;
	float size = 5.0f;

	Player(Vector2, Color);

	void render();
};