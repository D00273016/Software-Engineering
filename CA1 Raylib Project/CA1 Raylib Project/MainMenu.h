#pragma once
#include <raylib.h>
#include "Menu.h"

// The MainMenu(child) inherits menu
class MainMenu : Menu
{
	public:

		struct StartButton {
			Texture2D playButton;
			Vector2 buttonPosition;
			float buttonRotation;
			float buttonScale;
			Color buttonColor;
			Vector2 mousePosition;
		};


		MainMenu();
		// Overloaded constructor is passing in font for the menu and a struct
		MainMenu(Font iceFont, StartButton startButton);
		
		void Draw();
		bool StartGame(Vector2 mousePosition, Rectangle buttonBounds);

private:
		// Tidying up code
		StartButton startButton;
};

