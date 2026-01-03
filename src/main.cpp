#include <iostream>

#include "eventManager.hpp"
#include "eventType.hpp"
#include "inputManager.hpp"
#include "mapObject.hpp"
#include "player.hpp"
#include "playerCamera.hpp"
#include "raylib/raylib.h"

void onPlayerAttack(std::shared_ptr<Event> e) {
	auto attackEvent = std::dynamic_pointer_cast<PlayerAttack>(e);
	if (attackEvent) {
		std::cout << "<Event:PlayerAttack> damage: " << attackEvent->damage << std::endl;
	}
}

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(1280, 720, "Borderline");
	SetTargetFPS(60);
	HideCursor();

	EventManager eventManager;
	InputManager inputManager;

	Player p1({80.0f, 80.0f}, LIME);
	Player p2({200.0f, 200.0f}, VIOLET);

	MapObject wall({0.0f, 0.0f}, true);

	PlayerCamera camera;
	camera.center();

	eventManager.addListener(EventType::PLAYER_ATTACK, onPlayerAttack);

	while (!WindowShouldClose()) {
		if (IsWindowResized()) {
			camera.center();
		}

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

		DrawText("Borderline!", 100, 680, 30, LIGHTGRAY);

		BeginMode2D(camera.get());

		if (inputManager.statePlayer1.attack) {
			DrawLineBezier(p1.pos, p2.pos, 3.0f, p1.color);
		}

		wall.render();
		p1.render();
		p2.render();

		EndMode2D();

		DrawFPS(25, 20);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
