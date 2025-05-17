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
    states.transform *= getTransform();
    target.draw(mSprite, states);
}

