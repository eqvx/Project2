#ifndef Serek
#include "serek.h"
#endif

class Player {
public:
	Player(Texture2D img, Vector2 size, Vector2 hitboxSize) : hitbox(Rectangle{})
	{
		image = img;
		image.height = size.y;
		image.width = size.x;

		hitbox.height = hitboxSize.x;
		hitbox.width = hitboxSize.y;
		hitbox.color = RED;
		hitbox.x = 0;
		hitbox.y = 0;

		position.x = 0;
		position.y = 0;

		speed = 100;
	}
	~Player()
	{
		UnloadTexture(image);
	}
	inline void Draw(Color clr, bool drawHitbox) {
		DrawTexture(image, (int)position.x, (int)position.y, clr);

		if (drawHitbox)
			DrawRectangleRec(hitbox, hitbox.color);
	}
	inline void Update(const int multiplier, Sound& tada) {
		float deltaTime = GetFrameTime();

		int multipliedSpeed = speed * multiplier;

		if (IsKeyDown(KEY_W) && position.y >= 0)
			position.y -= multipliedSpeed * deltaTime;
		if (IsKeyDown(KEY_S) && position.y + 30 < GetScreenHeight())
			position.y += multipliedSpeed * deltaTime;

		if (IsKeyDown(KEY_A) && position.x >= 0)
			position.x -= multipliedSpeed * deltaTime;
		if (IsKeyDown(KEY_D) && position.x + 30 < GetScreenWidth())
			position.x += multipliedSpeed * deltaTime;
		else if (IsKeyDown(KEY_D) and not IsSoundPlaying(tada))
			PlaySound(tada);

		/* Player Hitbox */
		hitbox.x = position.x + 5;
		hitbox.y = position.y + 5;
	}
	void Reset() {
		position.x = 0;
		position.y = 0;
	}
	Rectangle& GetHitbox() {
		return hitbox;
	}
private:
	Vector2 position;
	Rectangle hitbox;
	Texture2D image;
	int speed;
};