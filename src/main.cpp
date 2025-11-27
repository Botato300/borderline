#include "raylib/raylib.h"

int main() {
	InitWindow(800, 600, "Borderline");
	SetTargetFPS(60);

	Vector2 player = {30.0f, 30.0f};
	float baseSpeed = 5.0f;

	while (!WindowShouldClose()) {
		float speed = baseSpeed;

		if (IsKeyDown(KEY_LEFT_SHIFT))
			speed *= 2;

		if (IsKeyDown(KEY_W)) player.y -= speed;
		if (IsKeyDown(KEY_S)) player.y += speed;
		if (IsKeyDown(KEY_A)) player.x -= speed;
		if (IsKeyDown(KEY_D)) player.x += speed;

		BeginDrawing();
		ClearBackground(BLACK);

		DrawText("Borderline!", 100, 200, 40, LIGHTGRAY);

		DrawCircleV(player, 10.0f, RED);

		DrawFPS(5, 5);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}