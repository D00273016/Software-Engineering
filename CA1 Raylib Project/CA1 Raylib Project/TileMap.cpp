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
	LoadTileMap(fileToLoad);
}

void TileMap::LoadTileMap(char* fileToLoad)
{

	Vector2 tileSize = { 1920 / mapSize.x,1080 / mapSize.y };


	// Creating an integer array to store the tile config
	// Change to 2d Array https://www.digitalocean.com/community/tutorials/two-dimensional-array-in-c-plus-plus

	int map[20][20] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,3,1,1,1,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,2,2,2,1,1,1,0,0,1,1,1,2,2,2,1,1,1},
		{1,1,1,2,2,2,1,1,1,0,0,1,1,1,2,2,2,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,1,1},
		{1,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1},
		{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,1,1},
		{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,1,1},
		{1,0,0,0,0,0,0,0,0,3,3,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,3,3,1,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,2,2,2,3,3,3,3,1,1,0,0,1,2},
		{0,0,0,0,0,0,0,2,2,2,3,3,3,3,1,1,0,0,1,2},
		{1,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,1,1},
		{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,1,1},
		{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,1,1}
	};


	// Tile Map made up from grass water and 
	// Grass = 1, Cement = 2, Ground, House = 4, Roof = 5, Water = 6
	for (int x = 0; x < 20; x++) 
	{
		for (int y = 0; y < 20; y++) 
		{
			TileType tileType;
			Vector2 position = { x * tileSize.x, y * tileSize.y };

			if (map[x][y] == 0)
			{
				tileType = Grass;
			}
			else if (map[x][y] == 1)
			{
				tileType = Ice;
			}
			else if (map[x][y] == 2)
			{
				tileType = Fire;
			}
			else if (map[x][y] == 3)
			{
				tileType = Obstacle;
			}


			Tile tile(position, tileSize, tileType);

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
		/*
		if (TileList.at(i).CheckForCollision(player.position, Vector2{player.size,player.size}))
		{
			TileList.at(i).SetTileType(Ice);
		}
		else {

			TileList.at(i).SetTileType(Fire);
		}
		*/
	}
}