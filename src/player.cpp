#include "player.hpp"

#include "inputManager.hpp"
#include "raylib/raylib.h"

Player::Player(Vector2 pos, Color color) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->color = color;
}

void Player::render() {
	DrawCircleGradient(pos.x, pos.y, 80.f, Fade(color, 0.5f), BLANK);
	DrawCircleV(pos, size, color);
}

void Player::update(const PlayerState& input) {
	int speed = baseSpeed;
	if (input.sprint) speed *= 2;

	pos.x += input.direction.x * speed;
	pos.y += input.direction.y * speed;
}
