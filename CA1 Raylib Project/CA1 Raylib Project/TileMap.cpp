#include "TileMap.h"
#include<fstream>

TileMap::TileMap(char* fileToLoad)
{
	LoadTileMap(fileToLoad);
}

void TileMap::LoadTileMap(char* fileToLoad)
{
	//once the tile map is read from the textile
	// it will load in a the file
	// output the file into an array.
	// Create a loop to loop over the array with if statements to display the 
	// In the SetTileType it will display this one the screen  
	
	std::fstream file;

	file.open(fileToLoad, std::fstream::in);
	
	file.close();
	// Reference https://stackoverflow.com/questions/32381484/print-a-matrix-in-a-text-file/32381610
}

void TileMap::Draw() {

}

void TileMap::Update() {

}