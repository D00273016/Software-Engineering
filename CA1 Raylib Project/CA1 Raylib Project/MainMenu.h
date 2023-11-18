#pragma once
#include <raylib.h>

class MainMenu
{
	//Setting variables
	private:
		Texture2D playButton;
		Vector2 buttonPosition;
		float buttonRotation;
		float buttonScale;
		Color buttonColor;
		Vector2 mousePosition;

	public:
		//Default consturcure
		MainMenu();
		// Overloaded constructor
		MainMenu(Texture2D playButton, Vector2 buttonPosition, float buttonRotation, float buttonScale, Color buttonColor, Vector2 mousePosition);
		//declaring functions
		void Draw();

		void Update();

	protected:
};

