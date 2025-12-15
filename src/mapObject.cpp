#include "mapObject.hpp"

#include "gameObject.hpp"
#include "raylib/raylib.h"

MapObject::MapObject(Vector2 pos, bool collision) : GameObject(pos, collision) {
	this->pos = pos;
	this->collision = collision;
}

void MapObject::render() {
	DrawRectangleLines(pos.x, pos.y, 800 - 80, 600 - 80, RED);
}

void MapObject::update() {
}