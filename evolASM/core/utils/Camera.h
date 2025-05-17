#pragma once

#include <sfml.h>

class Camera
{
	sf::View _view;
	sf::Transformable* _focused;

	bool _isLock;
	bool _isMoving;

public:
	float speed;

	Camera(const sf::View& defaultView);
	~Camera();

	void focus(sf::Transformable* transform);

	void setPosition(const sf::Vector2f& position);
	void update();
	void zoom(float factor = 0.1f);
	void resize(const sf::Event& event);


	void lock() { _isLock = true; }
	void unlock() { _isLock = false; }
	const bool& isLock() const noexcept { return _isLock; }

	const bool& isMove() const noexcept;

	const sf::View& getView() const noexcept;


	const sf::Vector2f& getPosition() const { return _view.getCenter(); }
};