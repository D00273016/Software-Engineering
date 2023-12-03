#pragma once
#include <raylib.h>
#include "Tile.h"
#include <vector>
#include "Character.h"

class TileMap
{
public:
	std::vector<Tile> TileList;
	//Keeping track of score
	int totalIce;
	int totalFire;

	// This will read in the tile map from the file.
private:

	Vector2 mapSize;
	Texture2D ice;
	Texture2D grass;
	Texture2D ground;
	Texture2D water;
	Texture2D fire;
	Texture2D castleGate;
	Texture2D castleWindow;
	Texture2D castleRoof;
	Texture2D castleTile;
	Texture2D castleStairsLeft;
	Texture2D castleStairsRight;
	// to create an array i looked up the tetris game logic to use vecotrs to store the tiles
    // Reference https ://www.youtube.com/watch?v=wVYKG_ch4yM


public:

	TileMap();
	
	void LoadTileMap();
	void LoadTextures();
	void Draw();
	//Player 1 & Player 2 position
	void Update(Vector2 player1Position,Vector2 player2Position);


};
