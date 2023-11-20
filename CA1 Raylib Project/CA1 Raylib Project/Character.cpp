#include "Character.h"
	

Character::Character(Vector2 position, Vector2 size, Color color)
	:position(position), size(size), color(color)
{
}

//Code sourced from class 6
void Character::Draw() {
	//For now making the character a movign rectangle
	DrawRectangle(position.x, position.y, size.x, size.y, color);
}

void Character::Update() {

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
	if (position.y > GetScreenHeight() - size.y) position.y = GetScreenHeight() - size.y;
	// This ensures the character within the screen frame on the X axis. Same logic applies as for Y axis but on X axis and using widht
	if (position.x < 0) position.x = 0;
	if (position.x > GetScreenWidth() - size.y) position.y = GetScreenWidth() - size.y;
};
