#include "gameObject.hpp"

class MapObject : GameObject {
   public:
	MapObject(Vector2 pos, bool hasCollision = false);

	void render() override;
	void update() override;
};
