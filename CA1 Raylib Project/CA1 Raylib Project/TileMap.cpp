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

	//once the tile map is read from the textile
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

//	This will loop through x horizontal surface
	Vector2 tileSize = { 800 / mapSize.x,600 / mapSize.y };

	for (int x = 0; x < mapSize.x; x++) 
	{	
		for (int y = 0;y < mapSize.y; y++)
		{
			Vector2 position = {x * tileSize.x, y * tileSize.y };

			TileType tileType;

			if (x % 2 == 0)
			{
				tileType = Grass;
			}
			else
			{
				tileType = Obstacle;
			}

			Tile tile (position, tileSize, tileType);

			//Creating an individual tile that will be a added to the list
			TileList.push_back(tile);
		}
	}

/*
	std::ifstream file("Resources/TileConfigMap.txt");
	std::string line;

	int y = 100; // Starting y position for drawing
	if (file.is_open()) {
		while (getline(file, line)) {
			std::cout << line << '\n';
			DrawText("fgsrgdr", 10, y, 20, RED);
			y += 30; // Adjust the vertical spacing as needed
		}
		//	file.close();
	}
	else {
		std::cout << "Unable to open file";
		DrawText("Unable to open file", 10, y, 20, RED);
		std::cerr << "Error opening the file" << std::endl;
	}
	//allows to draw texture and scale it.

*/

	/*
	if (file.is_open()) {
		while (getline(file, line)) {
			std::cout << line << '\n';
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file";
	}


	string line;
	ifstream file("TileConfigMap");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << '\n';
		}
		file.close();
	}

	else cout << "Unable to open file";

	return 0;
	
	file.close();


	*/


	// Reference https://stackoverflow.com/questions/32381484/print-a-matrix-in-a-text-file/32381610
	// https://cplusplus.com/doc/tutorial/files/
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
		if (TileList.at(i).CheckForCollision(player.position, Vector2{player.size,player.size}))
		{
			TileList.at(i).SetTileType(Ice);
		}
		else {

			TileList.at(i).SetTileType(Fire);
		}
	}
}