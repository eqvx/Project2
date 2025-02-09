#include "Player.hpp"

Sound oof = LoadSound("assets/oof.mp3");
Sound tada = LoadSound("assets/tada.mp3");

Player::Player(Texture2D img, Vector2 size, Vector2 hitboxSize) : hitbox(Rectangle{})
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

Player::~Player() 
{
	UnloadTexture(image);

	UnloadSound(tada);
	UnloadSound(oof);
}

constexpr inline void Player::Draw(Color clr, bool drawHitbox) {
	DrawTexture(image, (int)position.x, (int)position.y, clr);

	if (drawHitbox)
		DrawRectangleRec(hitbox, hitbox.color);
}

constexpr inline void Player::Update() {
	float deltaTime = GetFrameTime();

	if (IsKeyDown(KEY_W) && position.y >= 0)
		position.y -= speed * deltaTime;
	if (IsKeyDown(KEY_S) && position.y + 30 < GetScreenHeight())
		position.y += speed * deltaTime;

	if (IsKeyDown(KEY_A) && position.x >= 0)
		position.x -= speed * deltaTime;
	if (IsKeyDown(KEY_D) && position.x + 30 < GetScreenWidth())
		position.x += speed * deltaTime;
	else if (IsKeyDown(KEY_D) and not IsSoundPlaying(tada))
		PlaySound(tada);

	/* Player Hitbox */
	hitbox.x = position.x + 5;
	hitbox.y = position.y + 5;
}

void Player::Reset() {
	position.x = 0;
	position.y = 0;

	if (not IsSoundPlaying(oof))
		PlaySound(oof);
}

Rectangle& Player::GetHitbox() {
	return hitbox;
}