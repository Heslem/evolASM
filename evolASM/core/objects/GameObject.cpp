#include "GameObject.h"

GameObject::GameObject(const char* name)
	: _name(name)
{
}

GameObject::~GameObject()
{

}

void GameObject::tick()
{
}

void GameObject::destroy() noexcept
{
	this->_isDestroyed = true;
}

void GameObject::setGameColor(const sf::Color& color) {
	this->gameColor = color;
}

const sf::Color& GameObject::getGameColor() const noexcept {
	return this->gameColor;
}

const sf::FloatRect GameObject::getCollision() const noexcept
{
	return sf::FloatRect(getPosition(), mSprite.getSize());
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
}
