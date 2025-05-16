#pragma once
#include <sfml.h>
#include "State.h"

#include <unordered_map>

/// <summary>
/// Manages the states of the game.
/// </summary>
class StateManager final
	: public sf::Drawable
{
	friend class Core;

	// state name | state
	std::unordered_map<const char*, State*> _states;
	State* _current;

	StateManager();
	StateManager(const StateManager&) = delete;
	void operator=(const StateManager&) = delete;

	void tick();
	void drawImGui();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void addLoadingState();
public:
	~StateManager();

	void add(const char* name, State* state);
	void remove(const char* name);
	void set(const char* name);

	State* get(const char* name);

	State* getCurrent() const noexcept { return _current; }
};