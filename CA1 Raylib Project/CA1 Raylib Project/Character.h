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
	int playerNumber;
	

	int frame;         //current frame rate
	float updateTime;  //calls through diff frames
	float runningTime; //how much time was used since the last frame


private:

	Texture2D texture;

public:
	// adding player number for multiple players
	Character(Vector2 position, float size, char* textureFile,int playerNumber);
	
	void Draw();

	void Animate();
	void StopAnimation();

	void Update();
	
	
};

