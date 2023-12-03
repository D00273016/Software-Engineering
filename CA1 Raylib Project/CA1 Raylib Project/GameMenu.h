#pragma once
#include "Menu.h"

class GameMenu : Menu
{
	public:
		GameMenu(Font iceFont);

		void Draw(int totalIce,int totalFire, float timeRemaining);
};

