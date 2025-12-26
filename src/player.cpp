#include "player.hpp"

#include "playerState.hpp"
#include "raylib/raylib.h"
#include "raylib/raymath.h"

Player::Player(Vector2 pos, Color color) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->color = color;
}

void Player::render() {
	DrawCircleGradient(pos.x, pos.y, 80.f, Fade(color, 0.5f), BLANK);
	DrawCircleV(pos, size, color);

	for (Vector2 item : steps) {
		DrawCircle(item.x, item.y, size * 0.5f, color);
	}
}

void Player::update(const PlayerState& input) {
	int speed = baseSpeed;
	if (input.sprint) speed *= 2;

	pos.x += input.direction.x * speed;
	pos.y += input.direction.y * speed;

	if (Vector2Distance(pos, lastPos) >= 10.0f) {
		lastPos = pos;
		if (steps.size() >= 10) steps.pop_front();

		steps.push_back(pos);
	}
}
