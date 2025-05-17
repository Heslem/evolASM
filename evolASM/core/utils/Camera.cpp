#include "Camera.h"
#include <iostream>

Camera::Camera(const sf::View& defaultView) :
	_view(defaultView), _focused(nullptr), _isLock(true), _isMoving(false), speed(10.0f)
{
	// magic numbers yeah.
	_view.move(-(1200 / 2), -(720 / 2));
}

Camera::~Camera()
{
}

void Camera::focus(sf::Transformable* transform)
{
	unlock();
	_focused = transform;
}

void Camera::setPosition(const sf::Vector2f& position)
{
	_view.setCenter(position);
}

void Camera::update()
{
	if (_isLock) return;

	_isMoving = false;

	if (_focused == nullptr) {
		sf::Vector2f movement(0, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			movement.x = -speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			movement.x = speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			movement.y = -speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			movement.y = speed;
		}
		_isMoving = movement.x != 0 || movement.y != 0;
		if (_isMoving) {
			_view.move(movement);
		}
	}
	else {
		_view.setCenter(_focused->getPosition() + sf::Vector2f(8, 8));
	}
}


void Camera::zoom(float factor)
{
	if (_isLock) return;

	_view.zoom(1.0f - factor);
}

void Camera::resize(const sf::Event& event)
{
	_view.setSize({
					   static_cast<float>(event.size.width),
					   static_cast<float>(event.size.height)
		});
}

const bool& Camera::isMove() const noexcept
{
	return this->_isMoving;
}

const sf::View& Camera::getView() const noexcept
{
	return this->_view;
}
