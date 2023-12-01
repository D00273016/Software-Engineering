#pragma once
#include <raylib.h>

class Character
{
	//Specifying the postion and the hight and width of the charater
public: 
	Vector2 position;
	float size;

private:

	Texture2D texture;

public:
	Character(Vector2 position, float size, char* textureFile);
	
	//Code sourced from class 6
	void Draw();

	void Update();
	
	
};

