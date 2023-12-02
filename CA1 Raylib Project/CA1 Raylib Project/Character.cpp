#include "Character.h"
#include "TileMap.h"
	

Character::Character(Vector2 position, float size, char* textureFile)
	:position(position), size(size)
{
	texture = LoadTexture(textureFile); // Load button texture
	speed = 5.0f;

   // to get the middle of the feet it has a the collision check for chaning tiles. 
   // Issues with texture height size due to spacing in the png resulted in 1.18f figure for height. 
   // The 
	offset = { (texture.width * size) / 2, (texture.height * size) / 1.18f };

}

//Code sourced from class 6
void Character::Draw() {
	//For now making the character a movign rectangle
	DrawTextureEx(texture, position,0,size,WHITE);
	// To visualise collision position the circle is drawn
	DrawCircle(positionFeet.x, positionFeet.y, 3, PINK);

}

void Character::Update() {

	//The feet positions are calculated by top left hand side char position
	//by adding the calculated x offset (scaled char width / 2 to get the centre point), the same logic applies for y but vertical.

	positionFeet.x = position.x + offset.x;
	positionFeet.y = position.y + offset.y;

	if (IsKeyDown(KEY_UP))
	{
		position.y -= speed;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		position.y += speed;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		position.x -= speed;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		position.x += speed;
	}

	int gamepad = 0; // which gamepad, reference code: https://www.raylib.com/examples/core/loader.html?name=core_input_gamepad

	if (IsGamepadAvailable(gamepad))
	{
		// raylib game input example
		position.x += (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X) * speed);
		position.y += (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y) * speed);
	}

	// This ensures the character within the screen frame on the Y axis
	// if Top left position is negative it sets it to 0
	if (position.y < 0) position.y = 0;
	// if Bottom left position is over the screen you take the character position - the height of the character
	if (position.y > GetScreenHeight() - (texture.height * size)) position.y = GetScreenHeight() - (texture.height * size);
	// This ensures the character within the screen frame on the X axis. Same logic applies as for Y axis but on X axis and using widht
	if (position.x < 0) position.x = 0; 
	if (position.x > GetScreenWidth() - (texture.width / 2 * size)) position.x = GetScreenWidth() - (texture.width / 2 * size);
};
