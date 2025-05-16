#include "TileGrid.h"

TileGrid::TileGrid(const unsigned int& width, const unsigned int& height)
    : _width(width), _height(height)
{
    _tiles = new Tile[_width * _height];
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

