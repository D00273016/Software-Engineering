#include "MainMenu.h"

MainMenu::MainMenu() {


}

//:: Scope resolution operator meaning this fn it belongs to this class
void MainMenu::Draw()
{
	ClearBackground(RAYWHITE);

	DrawText("Hello Welcome to Floor is lava", 200, 100, 20, BLACK);
	DrawText("The aim of the game is put out lava by moving the character.", 100, 150, 20, BLACK);
	DrawText("Please select the difficulty level .", 200, 200, 20, BLACK);
	DrawText("Press the Button to Start", 250, 250, 20, BLUE);

	//allows to draw texture and scale it.
	DrawTextureEx(playButton, buttonPosition, buttonRotation, buttonScale, buttonColor);
}

void MainMenu::Update()
{

}
