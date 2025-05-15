#pragma once
#include <cmath>
#include <sfml.h>

const float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
	return sqrtf(powf(b.x - a.x, 2.0f) + powf(b.y - a.y, 2.0f));
}