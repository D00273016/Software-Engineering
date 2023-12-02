#include "TileMap.h"
#include<fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

TileMap::TileMap(char* fileToLoad)
{
	mapSize = { 20,20 };
	LoadTextures();
	LoadTileMap(fileToLoad);
}

void TileMap::LoadTileMap(char* fileToLoad)
{

	Vector2 tileSize = { 1590 / mapSize.x,980/ mapSize.y };


	// Creating an integer array to store the tile config
	// Change to 2d Array https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus

	int map[20][20] = {
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,2,2,2,0,0,0,0,0,0,0,0,2,2,2,0,0,3},
        {3,0,0,2,2,2,0,0,0,0,0,0,0,0,2,2,2,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,0,3},
        {3,2,2,2,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,3},
        {3,2,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,0,0,3},
        {3,2,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,0,0,3},
        {3,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {3,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,7,0,0,3},
        {3,0,0,0,0,0,0,2,2,2,3,3,3,0,5,5,5,0,0,3},
        {3,0,0,0,0,0,0,2,2,2,3,3,3,3,5,9,5,0,0,3},
        {3,2,2,2,2,2,2,2,2,0,0,0,0,2,9,4,9,2,0,3},
        {3,2,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,0,0,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
	};


	// Tile Map made up from grass water and 
	// Grass = 1, Cement = 2, Ground, House = 4, Roof = 5, Water = 6
	for (int x = 0; x < 20; x++) 
	{
		for (int y = 0; y < 20; y++) 
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
				tileType = CastleGate;
				texture = castleGate;
				
			}
			else if (map[y][x] == 5)
			{
				tileType = CastleWindow;
				texture = castleWindow;
			}
			else if (map[y][x] == 6)
			{
				tileType = CastleRoof;
				texture = castleRoof;

			}
			else if (map[y][x] == 7)
			{
				tileType = CastleStairsRight;
				texture = castleStairsRight;

			}
			else if (map[y][x] == 8)
			{
				tileType = CastleStairsLeft;
				texture = castleStairsLeft;

			}
			else if (map[y][x] == 9)
			{
				tileType = CastleTile;
				texture = castleTile;

			}

	

			Tile tile(position, tileSize, tileType, texture);

			//Creating an individual tile that will be a added to the list
			TileList.push_back(tile);
		};
	};

	// Tile Map reference logic from https://github.com/raysan5/raylib-games/blob/master/cat_vs_roomba/src/screen_gameplay.c


	// it will load in a the file
	// output the file into an array.
	// Create a loop to loop over the array with if statements to display the 
	// In the SetTileType it will display this one the screen  

	//Createing instance of tile class, first green grass
	//Position , size
	//Tile tile(Vector2{ 0,0 }, Vector2{ 50,50 }, Obstacle);
	//Tile tile2(Vector2{ 0,0 }, Vector2{ 100,100 }, Obstacle);

	//1. Get screensize
	//2. Loop over x and y (two loops)
	//3. Check x for 

	//Increaseing the tile map size

}

void TileMap::LoadTextures() {

	grass = LoadTexture("resources/tileGrass.png");
	water = LoadTexture("resources/tileWater_1.png");
	ground = LoadTexture("resources/tileWood.png");
	ice = LoadTexture("resources/tileSnow_slope.png");
	castleGate = LoadTexture("resources/castleGate.png");
	castleWindow = LoadTexture("resources/castleWindow.png");
	castleRoof = LoadTexture("resources/castleRoof.png");
	castleTile = LoadTexture("resources/castleTile.png");
	castleStairsLeft = LoadTexture("resources/castleStairsLeft.png");
	castleStairsRight = LoadTexture("resources/castleStairsRight.png");
}

void TileMap::Draw() {

	for (int i = 0; i < TileList.size(); i++)
	{
		TileList.at(i).Draw();
	}


}

void TileMap::Update(Character player) 
{
	for (int i = 0; i < TileList.size(); i++)
	{
		
		if (TileList.at(i).CheckForCollision(player.positionFeet))
		{
			TileList.at(i).SetTileType(Ice,ice);
		}
		//else {

		//	TileList.at(i).SetTileType(Fire);
		//}
		//
	}
}