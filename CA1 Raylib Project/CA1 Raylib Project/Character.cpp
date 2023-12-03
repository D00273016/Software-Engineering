#include "Character.h"
#include "TileMap.h"
	

Character::Character(Vector2 position, float size, char* textureFile,int playerNumber)
	:position(position), size(size), playerNumber(playerNumber)
{
	texture = LoadTexture(textureFile); // Load button texture
	speed = 300.0f;
	//Resizing the texture
	texture.width = texture.width * size;
	texture.height = texture.height * size;
	// 12 here = number of frames in sprite sheet
	sourceRec = { position.x, position.y, (float)(texture.width) / 12   , (float)texture.height };
	// for collision check I wanted to used the middle of the feet.
	// To do so I needed to move from the top left to be centre and bottom.
	// Issues with texture height size were due to spacing in the png resulted in 1.18f figure for height. 
	// Offset = 12 frames / 2 to get the middle of the character frame
	offset = { (texture.width) / 24.0f, (texture.height) / 1.18f };
	
	// Animation code reference was sourced from lecture no. 5/6
	frame = 0;
	updateTime = 1.0 / 12.0;
	runningTime = 0.0;
	
}


void Character::Draw() 
{
	//Drawing the character
	DrawTextureRec(texture, sourceRec, position, WHITE);

	// Test to visualise collision position the circle is drawn
	//DrawCircle(positionFeet.x, positionFeet.y, 3, PINK);
}
// Animation function to reduce code repetition
void Character::Animate() {

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

void Character::StopAnimation() {

	frame = 0;
	sourceRec.x = frame * sourceRec.width;
}

void Character::Update()
{

	//The feet positions are calculated by top left hand side char position
	//by adding the calculated x offset (scaled char width / 2 to get the centre point), the same logic applies for y but vertical.

	// Sets up time in between each frame, Code refernced from Lecture 5 Animation
	deltatime = GetFrameTime();

	positionFeet.x = position.x + offset.x;
	positionFeet.y = position.y + offset.y;

	// Adding if player 1 inputs keyboard / player 2 controller
	// Moving the character
	if (playerNumber == 1) 
	{

		if (IsKeyDown(KEY_UP))
		{
			position.y -= speed * deltatime;
			Animate();
		}
		if (IsKeyReleased(KEY_UP))
		{
			StopAnimation();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			position.y += speed * deltatime;
			Animate();
		}
		if (IsKeyReleased(KEY_DOWN))
		{
			StopAnimation();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			position.x -= speed * deltatime;
			Animate();
		}
		if (IsKeyReleased(KEY_LEFT))
		{
			StopAnimation();;
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			position.x += speed * deltatime;
			Animate();
		}
		if (IsKeyReleased(KEY_RIGHT))
		{
			StopAnimation();
		}

	}
	else if (playerNumber == 2)
	{
		int gamepad = 0; // which gamepad, reference code: https://www.raylib.com/examples/core/loader.html?name=core_input_gamepad
		
		if (IsGamepadAvailable(gamepad))
		{
			if (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X) != 0 || GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y) != 0)
			{
				position.x += (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X) * speed * deltatime);

				position.y += (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y) * speed * deltatime);

				Animate();
			}
			else
			{
				StopAnimation();
			}
			// raylib game input example
		}
	}

	
	// Harcoded bounds due to time constaraints
	// This ensures the character within the hardcoded bounds of the screen

	if (position.y < 6.5) position.y = 6.5;
	// if Bottom left position is over the screen you take the character position - the height of the character
	if (position.y > GetScreenHeight() - 150) position.y = GetScreenHeight() - 150;
	// This ensures the character within the screen frame on the X axis. Same logic applies as for Y axis but on X axis and using widht
	if (position.x < 100) position.x = 100;
	if (position.x > GetScreenWidth() - 180) position.x = GetScreenWidth() - 180;
};
