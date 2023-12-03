
//Include raylib package in the package
#include "raylib.h"
#include "Character.h"
#include "Tile.h"
#include "TileMap.h"
#include "Main.h"
#include "MainMenu.h"
#include "GameOverMenu.h"
#include "GameMenu.h"

/* Game description  

The game opens to main menu.
Game overview is displayed, user is asked to click the play button.
This is a 2 player game where player one uses arrow keys and player 2 controller.
(Tested using playstation controller) 
The player who covers the most tiles wins.
Game speeds up after 30 secods and ends after total of 60 seconds.
Game over screen is displayed at the end of the game with the winner player

Initial tile map concept reference https://www.youtube.com/watch?v=DqKrZ7Zffxw
*/

//Screen type
enum Screen
{
	Menu,
	Game,
	GameOver
};

int main() {

	//Sets the width and the height, and title  of the screen 
	const int screenWidth = 1920;
	const int screenHeight = 1080;
	const char* title = "Floor is lava";

	//Speed increase boolean, allowed once
	bool increaseSpeed = true;

	// Setting game time remaining, 1 second longer than time as it reduces before drawing
	float gameTime = 61;

	Vector2 mousePosition = { 0.0f, 0.0f };
	Screen currentScreen = Menu;

	//Raylib built in function to initialise window by passing in variable
	InitWindow(screenWidth, screenHeight, title);

	//Setting how many times the screen refreshes per second
	SetTargetFPS(60);
	
	// Load button texture reference https://kenney.nl/assets/ui-pack
	Texture2D playButton = LoadTexture("resources/Play_button.png"); 
	
	//Font references https://www.1001fonts.com/search.html?search=fire&page=2 https://www.1001fonts.com/search.html?search=ice
	Font iceFont = LoadFontEx("resources/Snowy Season.ttf", 32, 0, 250);
	Font fireFont = LoadFontEx("resources/Fire.ttf", 32, 0, 250);
	
	//Struct to access start button
	MainMenu::StartButton startButton{};
	startButton.playButton = playButton;
	startButton.buttonPosition = { (float)screenWidth / 2,(float)screenHeight / 2 };
	startButton.buttonRotation = 0.00;
	startButton.buttonScale = { 2.0f };
	startButton.buttonColor = SKYBLUE;

	//Settting up audio from reference code https://www.raylib.com/examples/audio/loader.html?name=audio_music_stream
	//Audio was downloaded from https://clement-panchout.itch.io/yet-another-free-music-pack?download#google_vignette 'Life is full of Joy'
	InitAudioDevice();
	Music music = LoadMusicStream("resources/Joy.wav");
	PlayMusicStream(music);

	//Creating instance of the players referenced from https://craftpix.net/freebies/free-golems-chibi-2d-game-sprites/?num=1&count=9&sq=golem&pos=3
	Character player1(Vector2{ screenWidth / 2 ,screenHeight / 2 }, 0.1, (char*)"Resources/Ice_Golem_Run.png", 1);  //This is the character 1
	Character player2(Vector2{screenWidth / 2-10, screenHeight / 2-6}, 0.1, (char*)"Resources/Fire_Golem_Run.png",2); //This is the character 2

	TileMap tileMap{};

	// Setting the play button bounds 
	Rectangle buttonBounds = { startButton.buttonPosition.x, startButton.buttonPosition.y, playButton.width * startButton.buttonScale, playButton.height * startButton.buttonScale };
	
	MainMenu mainMenu{ iceFont, startButton };
	GameMenu gameMenu { iceFont };
	GameOverMenu gameOverMenu { iceFont, fireFont };


	// Game Logic

	while (!WindowShouldClose()) 
	{
		UpdateMusicStream(music); 
		mousePosition = GetMousePosition();

		if (currentScreen == Menu)
		{
			if (mainMenu.StartGame(mousePosition, buttonBounds)) // Start the game if button clicked
			{
				currentScreen = Game;
			}
		}
		else if (currentScreen == Game)
		{	
			// Moves the players
			player1.Update();
			player2.Update();

			tileMap.Update(player1.positionFeet,player2.positionFeet); // Checks for collisions between tiles and the player

			// Reducing the time of the game by 1 second (to match the frame time)
			gameTime -= 1 * GetFrameTime();
			

			if (increaseSpeed == true) {
				// time event less than 30 seconds increases players speed  
				if (gameTime <= 30) {

					player1.speed *= 1.5f;
					player2.speed *= 1.5f;

					increaseSpeed = false;
				}
			}
			if (gameTime <= 0)
			{
				currentScreen = GameOver;
			}
			
		}

		BeginDrawing();

		// Checks for current screen and draws the object depending on what screen
		if (currentScreen == Menu) 
		{
			ClearBackground(RAYWHITE);

			mainMenu.Draw();	
		}
		else if (currentScreen == Game)
		{
			ClearBackground(RAYWHITE);
	
			//Order matters determines what object is on top
			tileMap.Draw();
			player1.Draw();
			player2.Draw();

			gameMenu.Draw(tileMap.totalIce, tileMap.totalFire, gameTime); //Displays game UI, players scores and time remaining
		}
		else 
		{
			ClearBackground(RAYWHITE);

			gameOverMenu.Draw(tileMap.totalIce, tileMap.totalFire); //Displays winner in fire/ ice font
		}

		EndDrawing();
		
	};
	UnloadMusicStream(music);   // Unload music stream buffers from RAM
	CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)
	CloseWindow();
	return 0;
	
};
