#include "player.hpp"

#include "raylib/raylib.h"

Player::Player(Vector2 pos, Color color) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->color = color;
}

void Player::render() {
	DrawCircleV(pos, size, color);
}