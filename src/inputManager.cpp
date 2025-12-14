#include "inputManager.hpp"

#include "eventManager.hpp"
#include "raylib/raylib.h"

void InputManager::update(EventManager& eventManager) {
	statePlayer1.direction = {0, 0};
	statePlayer1.sprint = IsKeyDown(KEY_LEFT_SHIFT);

	if (IsKeyDown(KEY_W)) statePlayer1.direction.y -= 1;
	if (IsKeyDown(KEY_S)) statePlayer1.direction.y += 1;
	if (IsKeyDown(KEY_A)) statePlayer1.direction.x -= 1;
	if (IsKeyDown(KEY_D)) statePlayer1.direction.x += 1;

	statePlayer2.direction = {0, 0};
	statePlayer2.sprint = IsKeyDown(KEY_RIGHT_SHIFT);

	if (IsKeyDown(KEY_UP)) statePlayer2.direction.y -= 1;
	if (IsKeyDown(KEY_DOWN)) statePlayer2.direction.y += 1;
	if (IsKeyDown(KEY_LEFT)) statePlayer2.direction.x -= 1;
	if (IsKeyDown(KEY_RIGHT)) statePlayer2.direction.x += 1;

	if (IsKeyPressed(KEY_SPACE)) {
		std::shared_ptr<PlayerAttack> eventData = std::make_shared<PlayerAttack>();
		eventManager.emit("PlayerAttack", eventData);
	}
}