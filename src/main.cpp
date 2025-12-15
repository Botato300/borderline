#include <iostream>

#include "eventManager.hpp"
#include "eventType.hpp"
#include "inputManager.hpp"
#include "mapObject.hpp"
#include "player.hpp"
#include "raylib/raylib.h"

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
	InputManager inputManager;

	Player p1({80.0f, 80.0f}, LIME);
	Player p2({SCREEN_WIDTH - 150.0f, SCREEN_HEIGHT - 150.0f}, VIOLET);

	MapObject wall({40.0f, 40.0f}, true);

	eventManager.addListener(EventType::PLAYER_ATTACK, onPlayerAttack);

	while (!WindowShouldClose()) {
		inputManager.update();

		p1.update(inputManager.statePlayer1);
		p2.update(inputManager.statePlayer2);

		if (inputManager.statePlayer1.attack) {
			std::shared_ptr<PlayerAttack> eventData = std::make_shared<PlayerAttack>();
			eventData->damage = 999;
			eventData->playerid = 1;
			eventManager.emit(EventType::PLAYER_ATTACK, eventData);
		}

		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("Borderline!", 100, 200, 40, LIGHTGRAY);

		wall.render();
		p1.render();
		p2.render();

		DrawFPS(5, 5);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
