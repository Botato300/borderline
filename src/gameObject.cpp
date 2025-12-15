#include "gameObject.hpp"

GameObject::GameObject(Vector2 pos, bool collision) {
	this->pos = pos;
	this->collision = collision;
}