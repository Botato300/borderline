#include "playerCamera.hpp"

#include "raylib/raylib.h"

PlayerCamera::PlayerCamera(Camera2D camera) {
	this->camera = camera;
}

Camera2D PlayerCamera::get() {
	return camera;
}

void PlayerCamera::center() {
	camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
}