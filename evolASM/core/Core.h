#pragma once
#include <sfml.h>
#include <core/StateManager.h>
#include <core/utils/Camera.h>

/// <summary>
/// Core class is the main singletone class of the application.
/// </summary>
class Core final
{
	/// <summary>
	/// Window of the application.
	/// </summary>
	sf::RenderWindow* _window;

	// I can't say about that. That old code.
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

	/// <summary>
	/// Returns mouse position relative to the window.
	/// </summary>
	/// <returns></returns>
	const sf::Vector2f getMousePosition() const;
	const sf::Vector2u& getWindowSize() const;
	const bool& isWindowFocus() const;


	/// <summary>
	/// Load resources, initialize the window and run engine loop.
	/// </summary>
	void run();
	void stop();

	Camera& getCamera() { return *_camera; }
	StateManager& getStateManager() { return *_stateManager; }
};