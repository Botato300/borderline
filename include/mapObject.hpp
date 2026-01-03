#include "gameObject.hpp"

class MapObject : GameObject {
   private:
	int width = 800;
	int height = 600;

   public:
	MapObject(Vector2 pos, bool hasCollision = false);

	void render() override;
	void update() override;
	Rectangle getHitbox();
};
