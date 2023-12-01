#include "Character.h"
#include "TileMap.h"
	

Character::Character(Vector2 position, float size, char* textureFile)
	:position(position), size(size)
{
	texture = LoadTexture(textureFile); // Load button texture
}

//Code sourced from class 6
void Character::Draw() {
	//For now making the character a movign rectangle
	DrawTextureEx(texture, position,0,size,WHITE);

}

void Character::Update() {

	//position.y = position.y - (texture.height / 2);

	if (IsKeyDown(KEY_UP))
	{
		position.y -= 5;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		position.y += 5;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		position.x -= 5;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		position.x += 5;
	}
	// This ensures the character within the screen frame on the Y axis
	// if Top left position is negative it sets it to 0
	if (position.y < 0) position.y = 0;
	// if Bottom left position is over the screen you take the character position - the height of the character
	if (position.y > GetScreenHeight() - (texture.height * size)) position.y = GetScreenHeight() - (texture.height * size);
	// This ensures the character within the screen frame on the X axis. Same logic applies as for Y axis but on X axis and using widht
	if (position.x < 0 - texture.width / 2) position.x = 0 - texture.width / 2;
	if (position.x > GetScreenWidth() - (texture.width / 2 * size)) position.x = GetScreenWidth() - (texture.width / 2 * size);
};
