#pragma once

#include <sfml.h>
#include <core/render/Sprite.h>

class TileGrid;

/// <summary>
/// Base class for all game objects.
/// </summary>
class GameObject :
	public sf::Transformable, public sf::Drawable
{
	sf::Color gameColor = sf::Color::White;
	bool _isDestroyed = false;
	const char* _name;

protected:
	TileGrid* _tilegrid;

public:
	Sprite mSprite;

	GameObject(const char* name);
	virtual ~GameObject();

	virtual void tick();

	void setTileGrid(TileGrid* tilegrid) { _tilegrid = tilegrid; }

	void destroy() noexcept;

	const bool& isDestroy() const noexcept { return _isDestroyed; }

	void setGameColor(const sf::Color& color);

	const sf::Color& getGameColor() const noexcept;


	const sf::FloatRect getCollision() const noexcept;


	const char* getName() const noexcept { return _name; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};