#include "TileGrid.h"
#include <core/utils/Content.h>

TileGrid::TileGrid(const unsigned int& width, const unsigned int& height)
    : _width(width), _height(height)
{
    _tiles = new Tile[_width * _height];

    auto& content = Content::getInstance();

    // Initialize all tiles and set position by x, y
    size_t numTiles = _width * _height;
    for (size_t i = 0; i < numTiles; i++)
    {
		unsigned int x = i % _width;
		unsigned int y = i / _width;

		Tile& tile = _tiles[i];
		tile.setPosition(x * TILE_SIZE, y * TILE_SIZE);
        tile.mSprite.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        
        tile.mSprite.setTexture(content.Textures["debug"]);
    }
}

TileGrid::~TileGrid()
{
    delete[] _tiles;
}

void TileGrid::tick()
{
    // Tick only dirty tiles
    for (unsigned int i = 0; i < _width * _height; i++)
    {
        if (_tiles[i].isDirty())
        {
            _tiles[i].tick();
        }
    }
}

void TileGrid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Draw all tiles
    for (unsigned int y = 0; y < _height; y++)
    {
        for (unsigned int x = 0; x < _width; x++) 
        {
            const Tile& tile = getTile(x, y);
            
            target.draw(tile, states);
        }
    }
}


