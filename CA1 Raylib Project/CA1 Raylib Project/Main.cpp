
//Include raylib package in the package
#include "raylib.h"


//Opens a window
//Has Sprites / 3D Models : Includes textures, shapes, shaders, 3D models
//Capable of user input : Game controller, mouse input, keyboard input, use of camera
//Sprites / 3D Models capable of : Movement, animation, collisions
//Plays audio : Background audio or individual audio clips
//Includes text : Load different fonts
//Uses git / github source control
//Use of header and source files

/* Chose 1 to 2
Power - ups or collectibles(e.g., extra lives, speed boost)
Particle effects(e.g., when an object is hit or collected)
Time - based events(e.g., speed up game pace every 30 seconds)
Enemy AI(e.g., objects that follow or avoid the player)
Different control schemes(e.g., switching between keyboard and mouse controls)
Custom features of your own choosing at an appropriate level of advancement :
Hint: Look to the examples https ://www.raylib.com/examples.html
*/

int main() {


	//Set the width and the height, and title  of the screen 
	const int screenWidth = 800;
	const int screenHeight = 600;
	const char* title = "Floor is lava";

	//Raylib build in function to initialise window by passing in variable
	InitWindow(screenWidth, screenHeight, title);

	//Setting how many times the screen refreshes per second
	SetTargetFPS(60);

	//A game loop is created to keep the window game open until the user exits by clicking excape or closing window
	while (!WindowShouldClose()) {

		//This is where the main logic will be called (classes).
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();

	};
	CloseWindow();
	return 0;
	
};