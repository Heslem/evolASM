#pragma once
#include <sfml.h>
#include <core/StateManager.h>
#include <utils/Camera.h>

class Core final
{
	sf::RenderWindow* _window;
	sf::Time _oneTcp;

	Camera* _camera;

	StateManager* _stateManager;

	Core();
	Core(const Core&) = delete;
	void operator=(const Core&) = delete;

	inline void pollEvents();
	void loop();
public:
	~Core();

	static Core& getInstance() {
		static Core instance;
		return instance;
	}

	const sf::Vector2f getMousePosition() const;
	const sf::Vector2u& getWindowSize() const;
	const sf::Vector2f& getCameraPosition() const;
	const bool& isWindowFocus() const;

	Camera& getCamera();

	void run();
	void stop();

	StateManager& getStateManager() { return *_stateManager; }
};