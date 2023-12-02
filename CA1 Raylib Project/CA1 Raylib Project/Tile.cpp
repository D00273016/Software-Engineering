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

bool Tile::CheckForCollision(Vector2 charPos, Vector2 charSize)
{
	// First rectangle tile and second is the player / enemy
	Rectangle tileRec{ position.x, position.y, size.x, size.y };
	Rectangle charRec{ charPos.x, charPos.y, charSize.x, charSize.y };

	//built in function that will check for collision and return boolean
	bool result = CheckCollisionRecs(tileRec, charRec);

	return result;
}
