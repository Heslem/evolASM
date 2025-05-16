#include <sfml.h>
#include <core/tiles/Tile.h>

/// <summary>
/// A 2D grid of tiles.
/// </summary>
class TileGrid final
    : public sf::Drawable
{
    // 2D array of tiles
    Tile* _tiles;
    unsigned int _width;
    unsigned int _height;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	TileGrid(const unsigned int& width, const unsigned int& height);
	~TileGrid();

    void tick();


    Tile& getTile(const unsigned int& x, const unsigned int& y) const noexcept { return _tiles[x + y * _width]; }
    void setTile(const unsigned int& x, const unsigned int& y, const Tile& tile) noexcept { _tiles[x + y * _width] = tile; }

    const unsigned int& getWidth() const noexcept { return _width; }
    const unsigned int& getHeight() const noexcept { return _height; }
};
