#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(Font iceFont, Font fireFont) : Menu(iceFont), fireFont(fireFont)
{
}

void GameOverMenu::Draw(int totalIce, int totalFire)
{
	//Condition to check who won

	if (totalIce > totalFire)
	{
		DrawTextEx(iceFont, "Game Over, Player One Wins", Vector2{ (float)GetScreenWidth() / 2 - 200, (float)GetScreenHeight() / 2 }, iceFont.baseSize, 2, SKYBLUE);
	}
	else if (totalFire > totalIce)
	{
		DrawTextEx(fireFont, "Game Over, Player Two Wins", Vector2{ (float)GetScreenWidth() / 2 - 200, (float)GetScreenHeight() / 2 }, fireFont.baseSize, 2, ORANGE);
	}
	else
	{
		DrawText("Game Over, Draw!", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2, 20, BLACK);
	}
}
