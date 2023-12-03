#include "Character.h"
#include "TileMap.h"
	

Character::Character(Vector2 position, float size, char* textureFile)
	:position(position), size(size)
{
	texture = LoadTexture(textureFile); // Load button texture
	speed = 300.0f;
	//Resizing the texture works when set here rather than calculations in the source rec.
	texture.width = texture.width * size;
	texture.height = texture.height * size;
	sourceRec = { position.x, position.y, (float)(texture.width) / 12   , (float)texture.height };
	// to get the middle of the feet it has a the collision check for chaning tiles. 
	// Issues with texture height size due to spacing in the png resulted in 1.18f figure for height. 
	// Offset = 12 frames / 2 to get the middle of the character frame
	offset = { (texture.width) / 24.0f, (texture.height) / 1.18f };
	
	
	frame = 0;
	updateTime = 1.0 / 12.0;
	runningTime = 0.0;
	
}

//Code sourced from class 6
void Character::Draw() 
{
	//For now making the character a movign rectangle
    //DrawTextureEx(texture, position,0,size,WHITE);
	DrawTextureRec(texture, sourceRec, position, WHITE);

	// To visualise collision position the circle is drawn
	DrawCircle(positionFeet.x, positionFeet.y, 3, PINK);

}


void Character::Update() 
{

	//The feet positions are calculated by top left hand side char position
	//by adding the calculated x offset (scaled char width / 2 to get the centre point), the same logic applies for y but vertical.

	// Sets up time in between each frame, Code refernced from Lecture 5 Animation
	deltatime = GetFrameTime();

	positionFeet.x = position.x + offset.x;
	positionFeet.y = position.y + offset.y;

	if (IsKeyDown(KEY_UP))
	{
		position.y -= speed * deltatime;
		runningTime += deltatime;
		
		if (runningTime >= updateTime) 
		{
			runningTime = 0.0;
			sourceRec.x = frame * sourceRec.width;
			frame++;

			if (frame > 11) 
			{
				frame = 0;
			}
		}	
	}
	if (IsKeyReleased(KEY_UP)) 
	{
		frame = 0;
		sourceRec.x = frame * sourceRec.width;
	}
	if (IsKeyDown(KEY_DOWN))
	{
		position.y += speed * deltatime;
		runningTime += deltatime;

		if (runningTime >= updateTime) 
		{
			runningTime = 0.0;
			sourceRec.x = frame * sourceRec.width;
			frame++;

			if (frame > 11) 
			{
				frame = 0;
			}
		}
	}
	if (IsKeyReleased(KEY_DOWN)) 
	{
		frame = 0;
		sourceRec.x = frame * sourceRec.width;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		position.x -= speed * deltatime;
		runningTime += deltatime;

		if (runningTime >= updateTime)
		{
			runningTime = 0.0;
			sourceRec.x = frame * sourceRec.width;
			frame++;

			if (frame > 11)
			{
				frame = 0;
			}
		}
	}
	if (IsKeyReleased(KEY_LEFT))
	{
		frame = 0;
		sourceRec.x = frame * sourceRec.width;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		position.x += speed * deltatime;
		runningTime += deltatime;

		if (runningTime >= updateTime)
		{
			runningTime = 0.0;
			sourceRec.x = frame * sourceRec.width;
			frame++;

			if (frame > 11)
			{
				frame = 0;
			}
		}
	}
	if (IsKeyReleased(KEY_RIGHT))
	{
		frame = 0;
		sourceRec.x = frame * sourceRec.width;
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
