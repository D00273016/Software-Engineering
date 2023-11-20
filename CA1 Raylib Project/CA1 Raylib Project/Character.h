#pragma once
#include <raylib.h>

class Character
{
	//Specifying the postion and the hight and width of the charater
private:

	Color color;

public:
	Vector2 position;
	Vector2 size;

	Character(Vector2 position, Vector2 size, Color color);

	//Code sourced from class 6
	void Draw();

	void Update();
	
	
};

