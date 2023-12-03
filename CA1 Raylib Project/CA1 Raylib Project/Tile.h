#pragma once
#include <raylib.h>

// Creating enum = set of values to easier hold the state of the tile.
enum TileType {
	Grass,
	Fire,
	Ice,
	Water,
	Ground,
	BottomGrass,
	Sand

};

class Tile
{
	private:
		Vector2 position;
		Vector2 size;
		Texture2D texture;

	//Declare the constructor
	public:
		TileType tileType;

		Tile(Vector2 position, Vector2 size, TileType tileType, Texture2D texture);

		// Void when you are not returning anything.
		void Draw();

		void SetTileType(TileType tileType,Texture2D texture);

		// this function will check if the player or enemy collides with the tile
		bool CheckForCollision(Vector2 position);
		// this check for the collision and if the collison matches change the texture that is retrieving.

};

