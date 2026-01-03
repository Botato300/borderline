#include "mapObject.hpp"

#include "gameObject.hpp"
#include "raylib/raylib.h"

MapObject::MapObject(Vector2 pos, bool collision) : GameObject(pos, collision) {
	this->pos = pos;
	this->collision = collision;
}

void MapObject::render() {
	DrawRectangleLines(pos.x - (width / 2), pos.y - (height / 2), width, height, RED);
}

void MapObject::update() {
}

Rectangle MapObject::getHitbox() {
	Rectangle hitbox = {};

	hitbox.width = width;
	hitbox.height = height;
	hitbox.x = pos.x - (width / 2);
	hitbox.y = pos.y - (height / 2);

	return hitbox;
}