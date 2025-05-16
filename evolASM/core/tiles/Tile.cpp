#include "Tile.h"

Tile::Tile()
    : _isDirty(false)
{
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

