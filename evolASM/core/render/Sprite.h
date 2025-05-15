#pragma once
#include <sfml.h>

class Sprite
	: public sf::Drawable
{
	sf::Vector2f _size;
	sf::VertexArray _vertices;
	sf::Texture* _texture = nullptr;
	bool _flip;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	Sprite(sf::Texture* texture = nullptr);
	Sprite(const Sprite& sprite);
	~Sprite();

	void setSize(const sf::Vector2f size);
	void setTexture(sf::Texture* texture);
	void setColor(const sf::Color& color);

	void flip(const bool& value);

	const sf::FloatRect getCollision() const noexcept;

	const sf::Vector2f& getSize() const noexcept { return _size; }
};