#include "MainMenu.h"

MainMenu::MainMenu(Font iceFont,StartButton startButton)
	:Menu(iceFont), startButton(startButton)
{
	

}

void MainMenu::Draw()
{
	ClearBackground(RAYWHITE);

	DrawTextEx(iceFont, "Hello Welcome to Ice vs Lava.", Vector2{(float)GetScreenWidth() / 2 - 150, (float)GetScreenHeight() / 2 - 200 }, iceFont.baseSize,2, BLACK);
	DrawTextEx(iceFont, "This is a 2 player game, winner is who collects more tiles.", Vector2{ (float)GetScreenWidth() / 2 - 300, (float)GetScreenHeight() / 2 - 150 }, iceFont.baseSize, 2, BLACK);
	DrawTextEx(iceFont, "Player 1 use arrow keys, Player 2 controller.", Vector2{ (float)GetScreenWidth() / 2 - 250, (float)GetScreenHeight() / 2 - 100 }, iceFont.baseSize, 2, BLACK);
	DrawTextEx(iceFont, "Press the button to start.", Vector2{ (float)GetScreenWidth() / 2 - 130, (float)GetScreenHeight() / 2 - 50 }, iceFont.baseSize, 2, BLACK);

	//allows to draw texture and scale it.
	DrawTextureEx(startButton.playButton, startButton.buttonPosition, startButton.buttonRotation, startButton.buttonScale, startButton.buttonColor);
}

//Check if for mouse click on play button
bool MainMenu::StartGame(Vector2 mousePosition, Rectangle buttonBounds)
{
	if (CheckCollisionPointRec(mousePosition, buttonBounds))
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			return true;
		}
	}

	return false;
}
