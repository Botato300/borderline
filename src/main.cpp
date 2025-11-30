#include <iostream>

#include "eventManager.hpp"
#include "player.hpp"
#include "raylib/raylib.h"

class MapObject {
   public:
	Vector2 pos = {0.0f, 0.0f};
	bool hasCollision = false;

	MapObject(Vector2 pos, bool hasCollision = false) {
		this->pos = pos;
		this->hasCollision = hasCollision;
	}

	void render() {
		DrawRectangleLines(pos.x, pos.y, 800 - 80, 600 - 80, RED);
	}
};

void onPlayerAttack(std::shared_ptr<Event> e) {
	auto attackEvent = std::dynamic_pointer_cast<PlayerAttack>(e);
	if (attackEvent) {
		std::cout << "<Event:PlayerAttack> damage: " << attackEvent->damage << std::endl;
	}
}

int main() {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Borderline");
	SetTargetFPS(60);
	HideCursor();

	EventManager eventManager;

	eventManager.addListener("PlayerAttack", onPlayerAttack);

	Player p1({80.0f, 80.0f}, LIME);
	Player p2({SCREEN_WIDTH - 150.0f, SCREEN_HEIGHT - 150.0f}, VIOLET);

	MapObject objWall({40.0f, 40.0f});

	while (!WindowShouldClose()) {
		int speed = p1.baseSpeed;
		if (IsKeyDown(KEY_LEFT_SHIFT)) speed *= 2;

		if (IsKeyPressed(KEY_SPACE)) {
			std::shared_ptr<PlayerAttack> event = std::make_shared<PlayerAttack>();
			eventManager.emit("PlayerAttack", event);
		}

		if (IsKeyDown(KEY_W)) p1.pos.y -= speed;
		if (IsKeyDown(KEY_S)) p1.pos.y += speed;
		if (IsKeyDown(KEY_A)) p1.pos.x -= speed;
		if (IsKeyDown(KEY_D)) p1.pos.x += speed;

		if (IsKeyDown(KEY_UP)) p2.pos.y -= 5.0f;
		if (IsKeyDown(KEY_DOWN)) p2.pos.y += 5.0f;
		if (IsKeyDown(KEY_LEFT)) p2.pos.x -= 5.0f;
		if (IsKeyDown(KEY_RIGHT)) p2.pos.x += 5.0f;

		BeginDrawing();
		ClearBackground(BLACK);

		objWall.render();
		p1.render();
		p2.render();

		DrawFPS(5, 5);
		DrawText("Borderline!", 100, 200, 40, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
