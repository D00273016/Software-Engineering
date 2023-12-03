#include "TileMap.h"
#include<fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

TileMap::TileMap()
{
	mapSize = { 30,30 };
	LoadTextures();
	LoadTileMap();
	totalIce = 0;
	totalFire = 0;
}

void TileMap::LoadTileMap()
{

	Vector2 tileSize = { GetScreenWidth() / mapSize.x,GetScreenHeight() / mapSize.y };


	// Creating an integer array to store the tile config
	// Change to 2d Array https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus

	int map[30][30] = {
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
		{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,2,2,0,2,2,3,3},
        {3,3,2,2,2,2,2,2,2,0,2,2,2,0,0,0,0,2,2,2,2,2,0,2,2,0,2,2,3,3},
        {3,3,2,2,2,2,2,2,2,0,2,2,2,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,2,2,2,2,2,2,2,0,2,2,2,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,0,0,0,0,0,0,0,2,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,0,0,2,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,5,0,3,3},
        {3,3,0,0,0,0,0,2,2,2,0,2,2,2,2,2,2,0,5,5,5,0,0,0,0,0,5,0,3,3},
        {3,3,0,0,0,0,0,2,2,2,0,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,5,0,3,3},
        {3,3,2,2,2,2,2,2,2,0,2,2,2,0,0,0,0,2,2,2,2,2,0,0,2,0,5,2,3,3},
        {3,3,2,2,2,2,2,2,2,0,2,2,2,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,0,0,0,5,5,5,5,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3},
        {3,3,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,0,0,2,0,3,3},
        {3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,2,2,0,2,2,3,3},
        {3,3,2,2,2,2,2,2,2,0,2,2,2,0,0,0,0,2,2,2,2,2,0,2,2,0,2,2,3,3},
        {3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3},
		{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}

	};


//Loops over the array above and sets the tiles 
	for (int x = 0; x < mapSize.x; x++) 
	{
		for (int y = 0; y < mapSize.y; y++)
		{
			TileType tileType;
			Texture2D texture;
			Vector2 position = { x * tileSize.x, y * tileSize.y };

			if (map[y][x] == 0)
			{
				tileType = Grass;
				texture = grass;
			}
			else if (map[y][x] == 1)
			{
				tileType = Ice;
				texture = ice;
			}
			else if (map[y][x] == 2)
			{
				tileType = Ground;
				texture = ground;
			}
			else if (map[y][x] == 3)
			{
				tileType = Water;
				texture = water;
			}
			else if (map[y][x] == 4)
			{
				tileType = BottomGrass;
				texture = bottomGrass;
				
			}
			else if (map[y][x] == 5)
			{
				tileType = Sand;
				texture = sand;
			}


			Tile tile(position, tileSize, tileType, texture);

			//keeps track of the tiles in the array list
			TileList.push_back(tile);
		};
	};

	// Tile Map reference logic from https://github.com/raysan5/raylib-games/blob/master/cat_vs_roomba/src/screen_gameplay.c

}

void TileMap::LoadTextures() {

	grass = LoadTexture("resources/tileGrass.png");
	water = LoadTexture("resources/tileWater_1.png");
	ground = LoadTexture("resources/tileWood.png");
	ice = LoadTexture("resources/tileSnow_slope.png");
	fire = LoadTexture("resources/tileLava.png");
	bottomGrass = LoadTexture("resources/tileGrass_bottom.png");
	sand = LoadTexture("resources/tileDirt_slope.png");


}
//Loops over the array list and draws the tiles
void TileMap::Draw() {

	for (int i = 0; i < TileList.size(); i++)
	{
		TileList.at(i).Draw();
	}

}
// Loops over all tiles, checks for collisions and changes tile type based on the player.
// Keep track of total ice and fire for player score
void TileMap::Update(Vector2 player1Position, Vector2 player2Position)
{
	totalIce = 0;
	totalFire = 0;
	// Keeping track of the score and tile types for collision
	for (int i = 0; i < TileList.size(); i++)
	{
		if (TileList.at(i).tileType == Ice)
		{
			totalIce++;
		}
		else if (TileList.at(i).tileType == Fire)
		{
			totalFire++;
		}

		if (TileList.at(i).CheckForCollision(player1Position))
		{
			TileList.at(i).SetTileType(Ice,ice);
		}

		if (TileList.at(i).CheckForCollision(player2Position))
		{
			TileList.at(i).SetTileType(Fire, fire);
		}
	
	}
}