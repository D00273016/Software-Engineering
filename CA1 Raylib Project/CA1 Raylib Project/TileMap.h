#pragma once
#include <raylib.h>
#include "Tile.h"
#include <vector>


class TileMap
{

	// This will read in the tile map from the file.
private:
	std::vector<Tile> TileList;
	// to create an array i looked up the tetris game logic to use vecotrs to store the tiles
    // Reference https ://www.youtube.com/watch?v=wVYKG_ch4yM


public:
	char* fileToLoad;

	TileMap(char* fileToLoad);
	
	void LoadTileMap(char* fileToLoad);
	void Draw();
	void Update();


};
