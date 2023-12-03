#pragma once
#include <raylib.h>

class Character
{
	//Specifying the postion and the hight and width of the charater
	//To fix the collision the feet position and offset was required, speed was added to remove hardcoding
public: 
	Vector2 position;
	Vector2 positionFeet;
	// Distance between the top left position and character feet.
	Vector2 offset; 
	Rectangle sourceRec;
	float speed;
	float size;
	float deltatime;
	
	//I NEED TO MOVE THIS INTO A STRUCt
	/*
	Rectangle animRec;
	Vector2 animposition;*/
	int frame;         //current frame rate
	float updateTime;  //calls through diff frames
	float runningTime; //how much time was used since the last frame


private:

	Texture2D texture;

public:

	Character(Vector2 position, float size, char* textureFile);
	
	//Code sourced from class 6
	void Draw();

	void Update();
	
	
};

