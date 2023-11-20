#pragma once
#include <raylib.h>

// Creating enum = set of values to easier hold the state of the tile.
enum TileType {
	Grass,
	Fire,
	Ice,
	Obstacle
};

class Tile
{
	private:
		Vector2 position;
		Vector2 size;
		Color color;
		TileType tileType;


	//Declare the constructor
	public:
		Tile(Vector2 position, Vector2 size, TileType tileType);
		// Void when you are not returning anything.
		void Draw();

		void SetTileType(TileType tileType);

		// this function will check if the player or enemy collides with the tile
		bool CheckForCollision(Vector2 position,Vector2 size);
		// this check for the collision and if the collison matches change the texture that is retrieving.
		void Update();

};

