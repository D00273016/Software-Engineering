#include "Tile.h"
#include "Character.h"

// Set the constuctor
Tile::Tile(Vector2 position, Vector2 size, TileType tileType, Texture2D texture)
	  :position(position), size(size)
{
	SetTileType(tileType, texture);
}

// Add in scope resolution operator to ensure the function is being derived from a specific class

void Tile::Draw() 
{
	// setting rotation to 0
	DrawTextureEx(texture, position,0, 1, WHITE);
}

void Tile::SetTileType(TileType type,Texture2D tileTexture)
{		
	tileType = type;
	texture = tileTexture;
}

// There will be more obstacles that will have to go through the loop 

//previously checking for a collision between rectangles as the character was a rectangle
//instead of using the collision of each of all sides the character point at his feet being checked with the built in function

bool Tile::CheckForCollision(Vector2 charPos)
{
	// First rectangle tile and second is the player / player2
	Rectangle tileRec{ position.x, position.y, size.x, size.y };
	

	//built in function that will check for collision and return boolean
	bool result = CheckCollisionPointRec(charPos, tileRec);

	return result;
}
