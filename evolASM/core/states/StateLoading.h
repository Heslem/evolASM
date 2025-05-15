#pragma once

#include <core/State.h>

class StateLoading :
	public State
{
public:
	StateLoading();
	~StateLoading();

	void start() override;
	void tick() override;
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

