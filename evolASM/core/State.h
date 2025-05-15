#pragma once

#include <sfml.h>

class State :
	public sf::Drawable
{
public:
	State() = default;
	virtual ~State() = default;

	virtual void start() {}

	virtual void tick() = 0;

	virtual void end() {}

	virtual void drawImGui() {}
private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

