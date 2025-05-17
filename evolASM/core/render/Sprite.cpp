#include "Sprite.h"
#include <core/utils/Content.h>

Sprite::Sprite(sf::Texture* texture)
	: _vertices(sf::PrimitiveType::Quads, 4), _texture(texture)
{

}

Sprite::Sprite(const Sprite& sprite)
	: _vertices(sprite._vertices), _texture(sprite._texture), _size(sprite._size)
{

}

Sprite::~Sprite()
{

}

void Sprite::setSize(const sf::Vector2f size)
{
	_vertices[0].position = sf::Vector2f(0, 0);
	_vertices[1].position = sf::Vector2f(size.x, 0);
	_vertices[2].position = sf::Vector2f(size.x, size.y);
	_vertices[3].position = sf::Vector2f(0, size.y);

	_size = size;
}

void Sprite::setTexture(sf::Texture* texture)
{
	_texture = texture;

	sf::Vector2f size = (sf::Vector2f)_texture->getSize();

	_vertices[0].texCoords = sf::Vector2f(0, 0);
	_vertices[1].texCoords = sf::Vector2f(size.x, 0);
	_vertices[2].texCoords = sf::Vector2f(size.x, size.y);
	_vertices[3].texCoords = sf::Vector2f(0, size.y);
}

void Sprite::setTexture(const char* textureName)
{
	setTexture(Content::getInstance().Textures[textureName]);
}
void Sprite::setColor(const sf::Color& color)
{
	_vertices[0].color = color;
	_vertices[1].color = color;
	_vertices[2].color = color;
	_vertices[3].color = color;
}

void Sprite::flip(const bool& value)
{
	if (value == _flip)
		return;
	_flip = value;

	sf::Vector2u size = _texture->getSize();

	if (value) {
		_vertices[0].texCoords = sf::Vector2f(size.x, 0);
		_vertices[1].texCoords = sf::Vector2f(0, 0);
		_vertices[2].texCoords = sf::Vector2f(0, size.y);
		_vertices[3].texCoords = sf::Vector2f(size.x, size.y);
	}
	else {
		_vertices[0].texCoords = sf::Vector2f(0, 0);
		_vertices[1].texCoords = sf::Vector2f(size.x, 0);
		_vertices[2].texCoords = sf::Vector2f(size.x, size.y);
		_vertices[3].texCoords = sf::Vector2f(0, size.y);
	}
}

const sf::FloatRect Sprite::getCollision() const noexcept
{
	return sf::FloatRect();
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = _texture;
	target.draw(_vertices, states);
}