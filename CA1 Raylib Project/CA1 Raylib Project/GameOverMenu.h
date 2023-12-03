#pragma once

#include "Menu.h"

class GameOverMenu : Menu
{
private:
	Font fireFont;
public:
	GameOverMenu(Font iceFont, Font fireFont);

	void Draw(int totalIce, int totalFire);
};

