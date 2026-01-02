#include "raylib/raylib.h"

class PlayerCamera {
   private:
	Camera2D camera = {};

   public:
	PlayerCamera(Camera2D camera = {{0.0f, 0.0f}, {0.0f, 0.0f}, 0.0f, 1.0f});
	Camera2D get();
	void center();
};