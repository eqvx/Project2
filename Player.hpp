#include "serek.h"

class Player {
public:
	Player(Texture2D image, Vector2 size, Vector2 hitboxSize);
	~Player();
	constexpr inline void Draw(Color color, bool drawHitbox);
	constexpr inline void Update();
	void Reset();
	Rectangle& GetHitbox();
private:
	Vector2 position;
	Rectangle hitbox;
	Texture2D image;
	int speed;
};