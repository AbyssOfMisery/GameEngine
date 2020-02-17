#ifndef SCENE1_H
#define SCENE1_H

#include "../Utility/Util.h"
#include "../Utility/Enums.h"

static int const GRID_WIDTH = 19;
static int const GRID_HEIGHT = 19;

// The width and height of each tile in pixels.
static int const TILE_SIZE = 50;

// The level tile type.
struct Tile {
	TILE type;							// The type of tile this is.
	int columnIndex;					// The column index of the tile.
	int rowIndex;						// The row index of the tile.
	sf::Sprite sprite;					// The tile sprite.
	b2Body* physicsBody = nullptr;		// Physics body
	int H;								// Heuristic / movement cost to goal.
	int G;								// Movement cost. (Total of entire path)
	int F;								// Estimated cost for full path. (G + H)
	Tile* parentNode = nullptr;			// Node to reach this node.
};

class Scene1 : public sf::Drawable {
public:
	/**
	* Default constructor.
	*/
	Scene1();

	/**
	* Constructor.
	* A renderWindow is needed in order for the level to calculate its position.
	*/
	Scene1(sf::RenderWindow& window);

	/**
	* Returns true if the given tile index is solid.
	*/
	bool IsSolid(int columnIndex, int rowIndex);

	/**
	* Sets the index of a given tile in the 2D game grid.
	* This also changes the tile sprite, and is how tiles should be changed and set manually.
	*/
	void SetTile(int columnIndex, int rowIndex, TILE tileType);

	/**
	* Gets the index of the given tile.
	*/
	TILE GetTileType(int columnIndex, int rowIndex) const;

	/**
	* Generate a random level.
	* return player starting position.
	*/
	sf::Vector2f GenerateScene1(b2World& world);

	/**
	* Gets the tile at the given position.
	*/
	Tile* GetTile(sf::Vector2f position);

	/**
	* Gets the tile at the given position in the level array.
	*/
	Tile* GetTile(int columnIndex, int rowIndex);

	/**
	* Checks if a given tile is valid.
	*/
	bool TileIsValid(int columnIndex, int rowIndex);

	/**
	* Unlocks the door in the level.
	*/
	void UnlockDoor();

	/**
	* Return true if the given tile is a floor tile.
	*/
	bool IsFloor(int columnIndex, int rowIndex);

	/**
	* Return true if the given tile is a floor tile.
	*/
	bool IsFloor(const Tile& tile);

	/**
	* Returns the size of the tiles in the level.
	*/
	int GetTileSize() const;

	/**
	* Adds a tile to the level.
	* These tiles are essentially sprites with a unique index. Once added, they can be loaded via the LoadLevelFromFile() function by including its index in the level data.
	*/
	int AddTile(std::string fileName, TILE tileType);

private:

	/**
	* Creates a path between two nodes in the recursive backtracker algorithm.
	*/
	void CreatePath(int columnIndex, int rowIndex);

	/**
	* Adds a given number of randomly sized rooms to the level to create some
	open space.
	*/
	void CreateRooms(int roomCount);

	/**
	* Calculates the correct texture for each tile in the level.
	*/
	void CalculateTextures(b2World& world);

	/**
	* Generates an entry and exit point for the given level.
	* return one tile above entry location.
	*/
	sf::Vector2f GenerateEntryExit();

	/**
	* Draws the level grid to the provided render window.
	* @param window The render window to draw the level to.
	* @param timeDelta The time that has elapsed since the last update.
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/**
	* Checks if a given tile is a wall block.
	*/
	bool IsWall(int columnIndex, int rowIndex);

private:
	/**
	* A 2D array that describes the level data.
	* The type is Tile, which holds a sprite and an index.
	*/
	Tile m_grid[GRID_WIDTH][GRID_HEIGHT];

	/**
	* The position of the level relative to the window.
	* This is to the top-left of the level grid.
	*/
	sf::Vector2i m_origin;

	/**
	* An array containing all texture IDs of the level tiles.
	*/
	int m_textureIDs[static_cast<int>(TILE::COUNT)];

	/**
	* The indices of the tile containing the levels door.
	*/
	sf::Vector2i m_doorTileIndices;
};
#endif