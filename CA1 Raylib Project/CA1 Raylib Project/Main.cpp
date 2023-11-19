
//Include raylib package in the package
#include "raylib.h"
#include "Character.h"


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




#define NUM_FRAMES  3  
*/

enum Screen
{
	Menu,
	Game
};

int main() {


	//Set the width and the height, and title  of the screen 
	const int screenWidth = 800;
	const int screenHeight = 600;
	const char* title = "Floor is lava";
	Vector2 mousePosition = { 0.0f, 0.0f };

	Screen currentScreen = Menu;

	//Raylib build in function to initialise window by passing in variable
	InitWindow(screenWidth, screenHeight, title);

	//Setting how many times the screen refreshes per second
	SetTargetFPS(60);

	Texture2D playButton = LoadTexture("resources/Play_button.png"); // Load button texture

	//Texture2D characterTexture = LoadTexture("Resources/Denis.png");
	Vector2 buttonPosition = { (float)screenWidth / 2,(float)screenHeight / 2 };
	float buttonRotation = 0.00;
	float buttonScale = { 2.0f };
	Color buttonColor = SKYBLUE;


	//Creating instance of the character class
	Character player(50, 100, 20, 20, PINK);

	// First you take the top left position X, then y then it if the scale was not multiplied it the selection would not cover the exact button 
	Rectangle buttonBounds = { buttonPosition.x, buttonPosition.y, playButton.width * buttonScale, playButton.height * buttonScale };

	while (!WindowShouldClose()) 
	{

		mousePosition = GetMousePosition();

		if (currentScreen == Menu)
		{
			if (CheckCollisionPointRec(mousePosition, buttonBounds))
			{
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
				{
					currentScreen = Game;
				}
			}
		}
		else
		{
			player.Update();
		}


		// Draw ----------------------------------------------------------------------------------
		BeginDrawing();

		//Testing the button press action ideally this should be in another fuction

		if (currentScreen == Menu) {
			
			ClearBackground(RAYWHITE);

			//Adds Instructions text to scrren
			DrawText("Hello Welcome to Floor is lava", 200, 100, 20, BLACK);
			DrawText("The aim of the game is put out lava by moving the character.", 100, 150, 20, BLACK);
			DrawText("Please select the difficulty level .", 200, 200, 20, BLACK);
			DrawText("Press the Button to Start", 250, 250, 20, BLUE);

			//allows to draw texture and scale it.
			DrawTextureEx(playButton, buttonPosition, buttonRotation, buttonScale, buttonColor);
		
		}
		else 
		{
			ClearBackground(RAYWHITE);
			player.Draw();
		
		}


			EndDrawing();
		 //-------------------------------------------------------------------------------------
	};
			
	CloseWindow();
	return 0;
	
};

// Menu Screen
//  List of potential classes
// Game Class - Main logic 
// Map Class - Tile map
// Tile Object Class
// Character Class - Mr Snow
// Enemy Class - Inherits character? since it will have alot of the same atributes 
// Player Class inherits the character? Same applies
// Bonus collectable class
// SceneManagement of the game background, audio text, transition between scenes.

