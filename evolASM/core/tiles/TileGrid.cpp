#include "TileGrid.h"
#include <core/utils/Content.h>
#include <core/utils/PerlinNoise.h>
#include <core/utils/Logger.h>

void addTileToArr(sf::VertexArray& arr, int x, int y, int type)
{
    sf::Vector2f a1(x * TILE_SIZE, y * TILE_SIZE);
    sf::Vector2f a2(x * TILE_SIZE  + TILE_SIZE, y * TILE_SIZE);
    sf::Vector2f b1(x * TILE_SIZE  + TILE_SIZE, y * TILE_SIZE + TILE_SIZE);
    sf::Vector2f b2(x * TILE_SIZE, y * TILE_SIZE + TILE_SIZE);

    sf::Vector2f t1(type * TILE_SIZE, 0);
    sf::Vector2f t2(type * TILE_SIZE + TILE_SIZE, 0);
    sf::Vector2f t3(type * TILE_SIZE + TILE_SIZE, TILE_SIZE);
    sf::Vector2f t4(type * TILE_SIZE, TILE_SIZE);

    arr.append(sf::Vertex(a1, t1));
    arr.append(sf::Vertex(a2, t2));
    arr.append(sf::Vertex(b1, t3));
    arr.append(sf::Vertex(b2, t4));
}

TileGrid::TileGrid(const unsigned int& width, const unsigned int& height)
    : _width(width), _height(height), _array(sf::PrimitiveType::Quads, 0)
{
    noise::PerlinNoise perlinNoise;

    _tiles = new Tile[_width * _height];

    auto& content = Content::getInstance();

    _tilemap = Content::getInstance().Textures["tilemap"];
    

    // Initialize all tiles and set position by x, y
    size_t numTiles = _width * _height;
    for (size_t i = 0; i < numTiles; i++)
    {
		unsigned int x = i % _width;
		unsigned int y = i / _width;

		Tile& tile = _tiles[i];
		tile.setPosition(x * TILE_SIZE, y * TILE_SIZE);

        double n = perlinNoise.ValueNoise_2D(x, y);


        if (n > 0.41) {
            // show
            addTileToArr(_array, x, y, 6);
        }
        else if (n > 0.25) {
            // stone
            addTileToArr(_array, x, y, 3);
        }
        else if (n > 0.05) {
            //grass
            addTileToArr(_array, x, y, 1);
        }
        else if (n > 0.0) {
            // dirt
            addTileToArr(_array, x, y, 0);
        }
        else if (n < -0.1) {
            // very deep water
            addTileToArr(_array, x, y, 5);
        }
        else if (n < -0.03) {
            // deep water
            addTileToArr(_array, x, y, 4);
        }
        else if (n < 0.0) {
            // water
            addTileToArr(_array, x, y, 2);
        }
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
    //// Draw all tiles
    //for (unsigned int y = 0; y < _height; y++)
    //{
    //    for (unsigned int x = 0; x < _width; x++) 
    //    {
    //        const Tile& tile = getTile(x, y);
    //        
    //        target.draw(tile, states);
    //    }
    //}
    states.texture = _tilemap;
    target.draw(_array, states);
}


