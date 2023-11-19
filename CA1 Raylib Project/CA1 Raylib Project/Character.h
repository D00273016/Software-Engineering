#pragma once
#include <raylib.h>
class Character
{
	//Specifying the postion and the hight and width of the charater
private:
	int posX;
	int posY;
	int width;
	int height;
	Color color;

public:
	Character(int x, int y, int width, int height, Color color)
		:posX(x), posY(y), width(width), height(height), color(color) {}

	//Code sourced from class 6
	void Draw() {
		//For now making the character a movign rectangle
		DrawRectangle(posX,  posY, width, height, color);
	}

	void Update() {

		if (IsKeyDown(KEY_UP)) 
		{
			posY -= 5;
		}
		if (IsKeyDown(KEY_DOWN)) 
		{
			posY += 5;
		}
		if (IsKeyDown(KEY_LEFT)) 
		{
			posX -= 5;
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			posX += 5;
		}
		// This ensures the character within the screen frame on the Y axis
		// if Top left position is negative it sets it to 0
		if (posY < 0) posY = 0;                            
		// if Bottom left position is over the screen you take the character position - the height of the character
		if (posY > GetScreenHeight() - height) posY = GetScreenHeight() - height;
		// This ensures the character within the screen frame on the X axis. Same logic applies as for Y axis but on X axis and using widht
		if (posX < 0) posX = 0;
		if (posX > GetScreenWidth() - height) posY = GetScreenWidth() - height;
	};
	
	
};

