#include "GameMenu.h"

// Drawing the player 1 and Player 2 score and time remaining 

GameMenu::GameMenu(Font iceFont) : Menu(iceFont)
{
}

void GameMenu::Draw(int totalIce, int totalFire, float timeRemaining)
{
	DrawTextEx(iceFont, TextFormat("Player 1: %02i ", totalIce), Vector2{ 20, 20 },iceFont.baseSize,2, BLACK);
	DrawText(TextFormat("Time Remaining: %02i ", (int)timeRemaining), (GetScreenWidth() / 2) - 200, 20, 40, BLACK);
	DrawTextEx(iceFont, TextFormat("Player 2: %02i ", totalFire), Vector2{(float)GetScreenWidth() - 270, 20}, iceFont.baseSize, 2, BLACK);
}
