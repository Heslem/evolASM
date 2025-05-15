#pragma once

#include <sfml.h>
#include <core/render/Sprite.h>

struct GameObject :
	public sf::Transformable, public sf::Drawable
{
	sf::Color gameColor = sf::Color::White;
	bool _isDestroyed = false;
	const char* _name;

protected:
	Sprite _sprite;
public:

	GameObject(const char* name);
	virtual ~GameObject();

	virtual void tick();

	void destroy() noexcept;

	const bool& isDestroy() const noexcept { return _isDestroyed; }

	void setGameColor(const sf::Color& color);

	const sf::Color& getGameColor() const noexcept;


	const sf::FloatRect getCollision() const noexcept;


	const char* getName() const noexcept { return _name; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};